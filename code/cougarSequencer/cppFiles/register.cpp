#include <pqxx/pqxx>
#include <iostream>
#include <string>
#include "../hFiles/register.h"

// create a function that sends a string for whether it was successful in creating a user or not
std::string registerUser(const std::string& username, const std::string& password, pqxx::connection& conn) {
    try {
        std::cout << "[DEBUG] Starting insert for user: " << username << std::endl;

        // to open a connection between the database and server
        pqxx::work txn(conn);

        // how to do SQL in C++, sending these parameters of what SQL code you want to run and the parameters that you want to insert
        txn.exec_params( // txn.exec for mac txn.exec_params for WSL
        "INSERT INTO users (user_name, pass_word) VALUES ($1, $2)",
        pqxx::params{username, password}
        );

        // commit the insert
        txn.commit();

        // If it worked - they chose a username that no one else had
        return "success";
    } 
    catch (const pqxx::unique_violation& e) { // this is if it wasn't a valid username and it was already taken
        std::cerr << "[DB WARNING] Unique constraint violation: " << e.what() << std::endl;
        return "This user name is already taken. Please try again";
    }
    catch (const std::exception& e) { // if something went wrong with what was inserted by the user or other external factor
        std::cerr << "[DB ERROR] Query failed: " << e.what() << std::endl;
        return "error";
    }
}
