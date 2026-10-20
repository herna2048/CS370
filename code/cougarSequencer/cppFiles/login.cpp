#include <pqxx/pqxx>
#include <iostream>
#include <string>
#include "../hFiles/register.h"

std::string loginUser(const std::string& username, const std::string& password, pqxx::connection& conn) {
    try {
        std::cout << "[DEBUG] Starting insert for user: " << username << std::endl;

        pqxx::work txn(conn);

        // 1. Run the parameterized select
        auto result = txn.exec(
        "SELECT pass_word FROM users WHERE user_name = $1",
        pqxx::params{username}
        );

        if (result.empty() or result.size() == 0)
            return "This username is not valid. Please try again.";
        
        if (password == result[0][0].c_str())
            return "success"; // If it worked - they choose a username that no one else had

        
        return "This password is not valid. Please try again.";
    } 
 catch(const std::exception& e) {
        std::cerr << "[DB ERROR] Query failed: " << e.what() << std::endl;
        return "There was something wrong with your username or password. Please try again.";
    }
}