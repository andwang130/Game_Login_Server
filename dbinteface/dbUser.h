//
// Created by wj on 18-10-8.
//

#ifndef LOGINSERVER_DBUSER_H
#define LOGINSERVER_DBUSER_H

#include <iostream>
#include "../Model/User.h"
#include "../config.h"
using namespace std;
class dbUser {

public:
    dbUser();
    ~dbUser();
    MUser get_User(std::string &name);
    int add_User(MUser &user);

private:
    mysqlpp::Connection *coon;
};


#endif //LOGINSERVER_DBUSER_H
