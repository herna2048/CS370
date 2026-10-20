#include <pqxx/pqxx>
#include <iostream>
#include <string>
#include "../hFiles/register.h"

std::string loginUser(const std::string& username, const std::string& password, pqxx::connection& conn) {
    try {
        std::cout << "[DEBUG] Starting insert for user: " << username << std::endl;

        // to open a connection between the database and server
        pqxx::work txn(conn);

        // how to do SQL in C++, sending these parameters of what SQL code you want to run and the parameters that you want to select
        auto result = txn.exec(
        "SELECT pass_word FROM users WHERE user_name = $1",
        pqxx::params{username}
        );

        // check to see if the user name exists
        if (result.empty() or result.size() == 0)
            return "This username is not valid. Please try again.";

        // check to see if the password corresponds with the username they selected
        if (password == result[0][0].c_str())
            return "success"; // If it worked - they choose a username that no one else had

        
        return "This password is not valid. Please try again.";
    } 
 catch(const std::exception& e) { // if something went wrong with what was inserted by the user or other external factor
        std::cerr << "[DB ERROR] Query failed: " << e.what() << std::endl;
        return "There was something wrong with your username or password. Please try again.";
    }
}
