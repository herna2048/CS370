#include <pqxx/pqxx>
#include <iostream>
#include <string>
#include "../hFiles/register.h"

std::string registerUser(const std::string& username, const std::string& password, pqxx::connection& conn) {
    try {
        std::cout << "[DEBUG] Starting insert for user: " << username << std::endl;

        pqxx::work txn(conn);

        // 1. Run the parameterized insert
        txn.exec(
        "INSERT INTO users (user_name, pass_word) VALUES ($1, $2)",
        pqxx::params{username, password}
        );

        // 2. CRITICAL: Commit the transaction
        txn.commit();

        // If it worked - they choose a username that no one else had
        return "success";
    } 
    catch (const pqxx::unique_violation& e) {
        std::cerr << "[DB WARNING] Unique constraint violation: " << e.what() << std::endl;
        return "This user name is already taken. Please try again";
    }
    catch (const std::exception& e) {
        std::cerr << "[DB ERROR] Query failed: " << e.what() << std::endl;
        return "error";
    }
}