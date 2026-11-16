#pragma once
#include <string>

int userId(const std::string& username, pqxx::connection& conn);