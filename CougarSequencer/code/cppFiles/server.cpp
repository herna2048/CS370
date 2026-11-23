#include <iostream>
#include <memory>
#include <pqxx/pqxx> // client for PostGreSQL
#include <exception> // for throwing exceptions
#include <string>

#include "../hFiles/crow_all.h" // API
#include "../hFiles/userId.h"
#include "../hFiles/dbLogin.h"
#include "../hFiles/greeter.h"
#include "../hFiles/account/register.h"
#include "../hFiles/account/login.h"

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

// Connect to the PostGreSQL server 
string connStr = dbLogin();
user u(1, "guestUser");
  
try {
pqxx::connection conn(connStr);

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

// the get for the userInfo button, when you push it, you send out a request which this function then sends back through res["userInfo"], reads data
CROW_ROUTE(app, "/api/userInfo").methods(crow::HTTPMethod::GET)
([&u]() {
    crow::json::wvalue res;

    res["id"] = u.getId(); // Returns your username
    res["username"] = u.getUsername(); // Returns your username
    return crow::response(200, res);
});
        
// the POST for when you request to submit data for the database to insert in username and password
CROW_ROUTE(app, "/api/register").methods(crow::HTTPMethod::POST)
([&conn, &u](const crow::request& req) {
    auto body = crow::json::load(req.body);
    // check to see if there is a body and it contains what we had sent over in the js
    if (!body || !body.has("username") || !body.has("password")) {
        return crow::response(400, "{\"error\": \"Missing name field\"}");
    }

    u.setUsername(body["username"].s());
    u.setId(body["id"].i());

    crow::json::wvalue res;
    // Call function defined in register.cpp
    res["register"] = registerUser(u.getUsername(), body["password"].s(), u, conn);

    crow::response response(res);
    response.set_header("Content-Type", "application/json");
    return response;
});

// the POST for when you request to submit data for the database to select the username to see if it has a corresponding password
CROW_ROUTE(app, "/api/login").methods(crow::HTTPMethod::POST)
([&conn, &u](const crow::request& req) {
    auto body = crow::json::load(req.body);
    // check to see if there is a body and it contains what we had sent over in the js
    if (!body || !body.has("username") || !body.has("password")) {
        return crow::response(400, "{\"error\": \"Missing name field\"}");
    }

    u.setUsername(body["username"].s());
    u.setId(body["id"].i());

    crow::json::wvalue res;
    // Call function defined in login.cpp
    res["login"] = loginUser(u.getUsername(), body["password"].s(), u, conn);

    crow::response response(res);
    response.set_header("Content-Type", "application/json");
    return response;
});

// the PUT for when you request to submit data for the database to select the username to see if it has a corresponding password
CROW_ROUTE(app, "/api/logOut").methods(crow::HTTPMethod::PUT)
([&conn, &u](const crow::request& req) {
    auto body = crow::json::load(req.body);

    u.setUsername(body["username"].s());
    u.setId(body["id"].i());

    crow::json::wvalue res;
    res["status"] = "updated";
    return crow::response(200, res);;
});

// // the POST for when you request the data for the database for the specific song
// CROW_ROUTE(app, "/api/openProject").methods(crow::HTTPMethod::POST)
// ([&conn](const crow::request& req) {
//     auto body = crow::json::load(req.body);
//     // check to see if there is a body and it contains what we had sent over in the js
//     if (!body || !body.has("/*temp parameter*/") || !body.has("/*temp parameter*/")) {
//         return crow::response(400, "{\"error\": \"Missing name field\"}");
//     }

//     crow::json::wvalue res;
//     // Call function defined in saveProject.cpp
//     res["openProject"] = openProject(/*temp parameter*/, conn);

//     crow::response response(res);
//     response.set_header("Content-Type", "application/json");
//     return response;
// });

// // the POST for when you request to submit data for the database for the specific song
// CROW_ROUTE(app, "/api/saveProject").methods(crow::HTTPMethod::POST)
// ([&conn](const crow::request& req) {
//     auto body = crow::json::load(req.body);
//     // check to see if there is a body and it contains what we had sent over in the js
//     if (!body || !body.has("/*temp parameter*/") || !body.has("/*temp parameter*/")) {
//         return crow::response(400, "{\"error\": \"Missing name field\"}");
//     }

//     crow::json::wvalue res;
//     // Call function defined in saveProject.cpp
//     res["saveProject"] = saveProject(/*temp parameter*/, conn);

//     crow::response response(res);
//     response.set_header("Content-Type", "application/json");
//     return response;
// });

    app.port(18080).run();

// if the connection isn't valid
} catch (const std::exception &e) {
cerr << e.what() << endl;
return 1;
}
}