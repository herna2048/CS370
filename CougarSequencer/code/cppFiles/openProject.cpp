#include <pqxx/pqxx>
#include <iostream>
#include "../hFiles/openProject.h"

std::string openProject(const /*temp paramter*/, pqxx::connection& conn) {
    try {
        return "temp return value";
    } 
 catch(const std::exception& e) { // if something went wrong with what was inserted by the user or other external factor
        std::cerr << "[DB ERROR] Query failed: " << e.what() << std::endl;
        return "Something went wrong with saving your project";
    }
}
