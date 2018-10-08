//
// Created by wj on 18-10-8.
//

#ifndef LOGINSERVER_DBUSER_H
#define LOGINSERVER_DBUSER_H

#include <iostream>
#include "../Model/User.h"
using namespace std;
class dbUser {

public:
    MUser get_User(string name);
    string add_User(MUser &user);
};


#endif //LOGINSERVER_DBUSER_H
