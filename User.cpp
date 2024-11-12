#include "User.h"

User::User() : userid(0), username(""), password(""), role(""), permissions("") {}

User::~User() {}

bool User::haspermissions(const string& permission) {
    return permissions.find(permission) != string::npos; 
}

bool User::authenticate(const string& password) {
    return this->password == password; 
}

string User::getrole() const {
    return role;
}
