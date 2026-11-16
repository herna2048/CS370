#include <pqxx/pqxx>
#include <iostream>
#include "../hFiles/account/userId.h"

using namespace std;

// create a function that sends a string for whether it was successful in creating a user or not
int userId(const string& username, pqxx::connection& conn) {
    cout << "[DEBUG] Starting select for user: " << username << endl;

    // to open a connection between the database and server
    pqxx::work txn(conn);

    cerr << username << endl;

    // how to do SQL in C++, sending these parameters of what SQL code you want to run and the parameters that you want to insert
    auto result = txn.exec_params( // txn.exec for mac txn.exec_params for WSL
    "SELECT id FROM users WHERE user_name = $1",
    username
    );

    cerr << stoi(result[0][0].c_str()) << endl;

    return stoi(result[0][0].c_str());
}
