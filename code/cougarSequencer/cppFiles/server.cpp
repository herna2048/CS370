#include "../hFiles/crow_all.h"
#include "../hFiles/greeter.h"

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
    crow::App<CORSRules> app;

    CROW_ROUTE(app, "/<path>").methods(crow::HTTPMethod::OPTIONS)
    ([](crow::response& res, std::string) {
        res.code = 204;
        res.end();
    });

    CROW_ROUTE(app, "/api/greeter").methods(crow::HTTPMethod::POST)
    ([](const crow::request& req) {
        crow::json::wvalue res;
        // Call function defined in greeter.cpp
        res["greeterOutput"] = createGreeting();

        crow::response response(res);
        response.set_header("Content-Type", "application/json");
        return response;
    });

     CROW_ROUTE(app, "/api/register").methods(crow::HTTPMethod::POST)
    ([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body || !body.has("username") || !body.has("password")) {
            return crow::response(400, "{\"error\": \"Missing name field\"}");
        }

        crow::json::wvalue res;
        // Call function defined in greeter.cpp
        res["registerOutput"] = register(body["username"].s(), body["password"].s());

        crow::response response(res);
        response.set_header("Content-Type", "application/json");
        return response;
    });

    app.port(18080).run();
}