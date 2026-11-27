#include <iostream>
#include <string>
#include <random> //Random number generator for salt 
#include <functional> //built in c++ hash function 
//#include "Timer.cpp" //to test the time it takes to hash
using namespace std;

static const string ANUM = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMKNOPQRSTUVEWXYZ";

string generate_salt(){
    //Creates random number generator
    random_device rd;
    mt19937 generator(rd());


    //Ensures random numbers are uniformally taken across ANUM
    uniform_int_distribution<> distribution(0, ANUM.length() - 1);

    //Generates a random 7 character salt
    string salt;
    for (int i = 0; i < 7; i++) {
        salt += ANUM[distribution(generator)];
    }

    return salt;
    
}


string hash_password(const string& password, const string& salt) {
    hash<string> hash; 

    int hash_len = 32; 
    int iteratives = 2000; //Number of times hash was run
    string iter = salt + password; //current iteration of the hashed password
  

    //Attempted iterative chaining
    for (int i = 0; i < iteratives; i++) {
        iter = to_string(hash(iter));
    }

    return iter;
}

bool verify_password(const string& password, const string& salt, const string& hashed_password) {
    string hashed_input = hash_password(password, salt);
    return hashed_input == hashed_password;
}

int main() {
    
    string salt = generate_salt();
    cout << "Salt: " << salt << endl;

    string password = "password123";
    cout << "Password: " << password << endl;


    string hashed_password = hash_password(password, salt);

    cout << "Hashed Password: " << hashed_password << endl;

    return 0;
}
