#include <iostream>
#include <memory>
#include <pqxx/pqxx> // client for PostGreSQL
#include <exception> // for throwing exceptions
#include <string>
#include "../hFiles/crow_all.h"
#include "../hFiles/greeter.h"
#include "../hFiles/register.h"
#include "../hFiles/login.h"

using namespace std;

// All of the rules for the crow for POST, GET, etc...
struct CORSRules {
    struct context {};
    void before_handle(crow::request&, crow::response&, context&) {}
    void after_handle(crow::request&, crow::response& res, context&) {
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS, PUT, DELETE");
        res.add_header("Access-Control-Allow-Headers", "Content-Type, Authorization");
    }
};

int main() {

// Connect to the PostGreSQL server through a hardcoded host, port, etc...
try {
pqxx::connection conn("host=localhost port=5432 dbname=CougarSequencer user=postgres password=Baseball712 connect_timeout=3");

// creating the app for the crow in order to connect to the server
crow::App<CORSRules> app;

// initializing the response code to be 204 for no content
CROW_ROUTE(app, "/<path>").methods(crow::HTTPMethod::OPTIONS)
([](crow::response& res, std::string) {
    res.code = 204;
    res.end();
});

// the get for the greeter button, when you push it, you send out a request which this function then sends back through res["greeter"], reads data
CROW_ROUTE(app, "/api/greeter").methods(crow::HTTPMethod::GET)
([]() {
    crow::json::wvalue res;
    // Call function defined in greeter.cpp
    res["greeter"] = createGreeting(); // Returns your greeting string
    return crow::response(200, res);
});
        
// the POST for when you request to submit data for the database to insert in username and password
CROW_ROUTE(app, "/api/register").methods(crow::HTTPMethod::POST)
([&conn](const crow::request& req) {
    auto body = crow::json::load(req.body);
    // check to see if there is a body and it contains what we had sent over in the js
    if (!body || !body.has("username") || !body.has("password")) {
        return crow::response(400, "{\"error\": \"Missing name field\"}");
    }

    crow::json::wvalue res;
    // Call function defined in register.cpp
    res["register"] = registerUser(body["username"].s(), body["password"].s(), conn);

    crow::response response(res);
    response.set_header("Content-Type", "application/json");
    return response;
});

// the POST for when you request to submit data for the database to select the username to see if it has a corresponding password
CROW_ROUTE(app, "/api/login").methods(crow::HTTPMethod::POST)
([&conn](const crow::request& req) {
    auto body = crow::json::load(req.body);
    // check to see if there is a body and it contains what we had sent over in the js
    if (!body || !body.has("username") || !body.has("password")) {
        return crow::response(400, "{\"error\": \"Missing name field\"}");
    }

    crow::json::wvalue res;
    // Call function defined in login.cpp
    res["login"] = loginUser(body["username"].s(), body["password"].s(), conn);

    crow::response response(res);
    response.set_header("Content-Type", "application/json");
    return response;
});

    app.port(18080).run();

// if the connection isn't valid
} catch (const std::exception &e) {
cerr << e.what() << endl;
return 1;
}
}
