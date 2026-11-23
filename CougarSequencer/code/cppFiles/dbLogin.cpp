#include <iostream>
#include <pqxx/pqxx> // client for PostGreSQL
#include <string>

#include "../hFiles/dbLogin.h"

using namespace std;

string dbLogin() {
    ostringstream oss;
    string password;

    cout << "Enter password for CougarSequencer PostgreSQL Database: ";
    cin >> password;

    oss << "host=localhost"
        << " port=5432"
        << " dbname=CougarSequencer"
        << " user=postgres"
        << " password=" << password
        << " connect_timeout=3";

    return oss.str();
}