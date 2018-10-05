//
// Created by wj on 18-10-5.
//

#ifndef LOGINSERVER_USER_H
#define LOGINSERVER_USER_H

#endif //LOGINSERVER_USER_H

#include <iostream>
using namespace std;

class User
{
public:
    User();
    User(string name,string pswd);
    void add_User(string name,string pswd);
private:
    string name_;
    string pswd_;


};