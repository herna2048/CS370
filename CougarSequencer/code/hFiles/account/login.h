#pragma once
#include <string>

std::string loginUser(const std::string& username, const std::string& password, int& id, pqxx::connection& conn);