#pragma once
#include <string>

std::string registerUser(const std::string& username, const std::string& password, pqxx::connection& conn);