//
// Created by wj on 18-10-8.
//

#ifndef LOGINSERVER_DATABSE_H
#define LOGINSERVER_DATABSE_H


#include <map>
#include <iostream>
#include "User.h"
#include "../commds.h"
using namespace std;
static mutex Mutex;
typedef std::shared_ptr<MUser> prt_User;
static map<std::string,prt_User> UserMap;
static map<CoonPrt,prt_User> Login_User;
#endif //LOGINSERVER_DATABSE_H
