#pragma once
#include <string>
#include "../userId.h"

std::string openProject(project& p, pqxx::connection& conn);