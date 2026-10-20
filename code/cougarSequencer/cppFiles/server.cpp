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

struct CORSRules {
    struct context {};
    void before_handle(crow::request&, crow::response&, context&) {}
    void after_handle(crow::request&, crow::response& res, context&) {
        res.add_header("Access-Control-Allow-Origin", "*");
        res.add_header("Access-Control-Allow-Methods", "GET, POST, OPTIONS, PUT, DELETE");
        res.add_header("Access-Control-Allow-Headers", "Content-Type, Authorization");
    }
};

// std::string getEnvVar(const std::string& key, const std::string& defaultValue) {
//     const char* val = std::getenv(key.c_str());
//     return (val != nullptr) ? std::string(val) : defaultValue;
// }

int main() {
// string db_host = getEnvVar("DB_HOST", "127.0.0.1");
// string db_port = getEnvVar("DB_PORT", "5432");
// string db_name = getEnvVar("DB_NAME", "CougarSequencer");
// string db_user = getEnvVar("DB_USER", "postgres");
// string db_pass = getEnvVar("DB_PASS", "Baseball712");

// string conn_str = "host=" + db_host +
//                     " port=" + db_port +
//                     " dbname=CougarSequencer" +
//                     " user=" + db_user +
//                     " password=" + db_pass;

try {
// Connect to the database
// pqxx::connection conn(conn_str);
pqxx::connection conn("host=192.168.96.1 port=5432 dbname=CougarSequencer user=postgres password=Baseball712");

} catch (const std::exception &e) {
cerr << e.what() << endl;
return 1;
}

pqxx::connection conn("host=192.168.96.1 port=5432 dbname=CougarSequencer user=postgres password=Baseball712");

crow::App<CORSRules> app;

CROW_ROUTE(app, "/<path>").methods(crow::HTTPMethod::OPTIONS)
([](crow::response& res, std::string) {
    res.code = 204;
    res.end();
});

CROW_ROUTE(app, "/api/greeter").methods(crow::HTTPMethod::GET)
([]() {
    crow::json::wvalue res;
    // Call function defined in greeter.cpp
    res["greeter"] = createGreeting(); // Returns your greeting string
    return crow::response(200, res);
});
        

CROW_ROUTE(app, "/api/register").methods(crow::HTTPMethod::POST)
([&conn](const crow::request& req) {
    auto body = crow::json::load(req.body);
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

CROW_ROUTE(app, "/api/login").methods(crow::HTTPMethod::POST)
([&conn](const crow::request& req) {
    auto body = crow::json::load(req.body);
    if (!body || !body.has("username") || !body.has("password")) {
        return crow::response(400, "{\"error\": \"Missing name field\"}");
    }

    crow::json::wvalue res;
    // Call function defined in register.cpp
    res["login"] = loginUser(body["username"].s(), body["password"].s(), conn);

    crow::response response(res);
    response.set_header("Content-Type", "application/json");
    return response;
});

    app.port(18080).run();
}