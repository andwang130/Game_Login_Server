//
// Created by wj on 18-10-8.
//

#ifndef LOGINSERVER_DBUSER_H
#define LOGINSERVER_DBUSER_H

#include <iostream>
#include "../Model/User.h"
#include "dbBase.h"
using namespace std;
class dbUser: public dbBase
{

public:
    std::shared_ptr<MUser>  get_User(std::string &name);
    int add_User(MUser &user);
};


#endif //LOGINSERVER_DBUSER_H
