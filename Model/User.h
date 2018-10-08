//
// Created by wj on 18-10-5.
//

#ifndef LOGINSERVER_USER_H
#define LOGINSERVER_USER_H



#include <iostream>
using namespace std;

class MUser
{
public:
    MUser();
    MUser(std::string name,std::string pswd,std::string phone,std::string email);
    void add_User(std::string name,std::string pswd);
    std::string name_;
    std::string pswd_;
    std::string phone_;
    std::string email_;

};
#endif //LOGINSERVER_USER_H