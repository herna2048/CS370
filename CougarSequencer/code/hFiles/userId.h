#pragma once
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

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

class project {
private:
    int id;
    user& u;
    string name;
    int bpm;
    json grid;

public:
    project(user& uS, string n)
       : u(uS), name(std::move(n)) {}

    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    int getBpm() {
        return bpm;
    }

    json getGrid() {
        return grid;
    }

    int getUserId() {
        return u.getId();
    }

    string getUserUsername() {
        return u.getUsername();
    }

    void setId(int i) {
        id = i;
    }

    void setName(string n) {
        name = n;
    }

    void setBpm(int b) {
        bpm = b;
    }

    void setGrid(json g) {
        grid = g;
    }
};