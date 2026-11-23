#include <pqxx/pqxx>
#include <iostream>
#include <string>
#include "../hFiles/account/register.h"
#include "helper.hpp"

using namespace std;

// create a function that sends a string for whether it was successful in creating a user or not
string registerUser(const string& username, const string& password, user& u, pqxx::connection& conn) {
    try {
        cout << "[DEBUG] Starting insert for user: " << username << endl;

        // to open a connection between the database and server
        pqxx::work txn(conn);

        // how to do SQL in C++, sending these parameters of what SQL code you want to run and the parameters that you want to insert
        exec_p(txn, 
        "INSERT INTO users (user_name, pass_word) VALUES ($1, $2)",
        username, password
        );

        // If it worked - they chose a username that no one else had
        auto result = exec_p(txn,
        "SELECT id FROM users WHERE user_name = $1",
        username
        );

        u.setId(stoi(result[0][0].c_str()));

        // commit the insert
        txn.commit();

        return "success";
    } 
    catch (const pqxx::unique_violation& e) { // this is if it wasn't a valid username and it was already taken
        cerr << "[DB WARNING] Unique constraint violation: " << e.what() << endl;
        u.setId(1);
        u.setUsername("guestUser");
        return "This user name is already taken. Please try again";
    }
    catch (const exception& e) { // if something went wrong with what was inserted by the user or other external factor
        cerr << "[DB ERROR] Query failed: " << e.what() << endl;
        u.setId(1);
        u.setUsername("guestUser");
        return "error";
    }
}
