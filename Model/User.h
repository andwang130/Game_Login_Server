//
// Created by wj on 18-10-5.
//

#ifndef LOGINSERVER_USER_H
#define LOGINSERVER_USER_H

#endif //LOGINSERVER_USER_H

#include <iostream>
using namespace std;

class MUser
{
public:
    MUser();
    MUser(string name,string pswd,string phone,string email);
    void add_User(string name,string pswd);
    string name_;
    string pswd_;
    string phone_;
    string email_;

};