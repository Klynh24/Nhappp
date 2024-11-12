#ifndef USER_H
#define USER_H


#include "Database.cpp"

class User 
{ 
    private:
       int userid;
       string username;
       string password;
       string role;
       string permissions;
    public:
       User();
       ~User();
       bool haspermissions(const string& permission);
       bool authenticate(const string& password);
       string getrole() const;
};

#endif