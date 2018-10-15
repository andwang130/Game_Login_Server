//
// Created by wj on 18-10-8.
//

#ifndef LOGINSERVER_DATABSE_H
#define LOGINSERVER_DATABSE_H


#include <map>
#include <iostream>
#include "User.h"
#include "../commds.h"
#include "Role.h"
#include "Field.h"
using namespace std;

typedef std::shared_ptr<MUser> prt_User;
typedef std::shared_ptr<Role> prt_Role;
typedef std::shared_ptr<Field> prt_Filed;

//extern声明全局对象,用static的话每个文件会有一个副本，静态变量一般用在类当中，供类函数使用
extern mutex Mutex;
extern map<CoonPrt,prt_User> Login_User;

extern mutex roleMutex;
extern map<CoonPrt,prt_Role> Login_role;

extern mutex mathchingMutex;
extern map<int,prt_Filed> Filedmap;

extern void baseRemove(const CoonPrt &coonPrt);

extern void removeFiledmap(const CoonPrt &coonPrt);

extern void removeLogin_role(const CoonPrt &coonPrt);

extern void removeLogin_User(const CoonPrt &coonPrt);
#endif //LOGINSERVER_DATABSE_H
