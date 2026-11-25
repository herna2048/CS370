#include <pqxx/pqxx>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include "../hFiles/account/openProject.h"
#include "helper.hpp"

using namespace std;

using json = nlohmann::json;

string openProject(project& p, pqxx::connection& conn) {
    try {
        cout << "[DEBUG] Starting insert for user: " << p.getUserUsername() << endl;

        // to open a connection between the database and server
        pqxx::work txn(conn);

        // project id
        auto id = exec_p(txn,
        "SELECT id FROM songs WHERE user_id = $1 AND song_name = $2",
        p.getUserId(), p.getName()
        );

        // check to see if the user name exists
        if (id.empty() or id.size() == 0)
            return "This Song does not exist. Please try again.";

        p.setId(stoi(id[0][0].c_str()));
        

        // project bpm
        auto bpm = exec_p(txn,
        "SELECT bpm FROM songs WHERE id = $1",
        p.getId()
        );

        p.setBpm(stoi(bpm[0][0].c_str()));
        

        // project grid
        auto grid = exec_p(txn,
        "SELECT grid FROM songs WHERE id = $1",
        p.getId()
        );

        string raw = grid[0][0].c_str();
        p.setGrid(json::parse(raw));
        
        return "success";
    }
    catch(const exception& e) { // if something went wrong with what was inserted by the user or other external factor
        cerr << "[DB ERROR] Query failed: " << e.what() << endl;
        p.setBpm(60);
        p.setGrid(json::object());
        return "There was something wrong with your request. Please try again.";
    }
}
