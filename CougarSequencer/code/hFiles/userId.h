#pragma once
#include <iostream>
#include <string>

using namespace std;

class user {
    private:
        int id;
        string username;  
    public:
        user(int i, string u) {
            id = i;
            username = u; 
        }

        int getId() const {
            return id;
        }

        string getUsername() const {
            return username;
        }

        void setId(int i) {
            id = i;
        }

        void setUsername(string u) {
            username = u;
        }
};