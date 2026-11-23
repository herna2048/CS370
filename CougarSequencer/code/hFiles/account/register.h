#pragma once
#include <string>
#include "../userId.h"

std::string registerUser(const std::string& username, const std::string& password, user& u, pqxx::connection& conn);