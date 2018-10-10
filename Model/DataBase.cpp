//
// Created by wj_de on 18-10-10.
//
#include "DataBase.h"
mutex Mutex;
map<CoonPrt,prt_User> Login_User;

mutex roleMutex;
map<CoonPrt,prt_Role> Login_role;

mutex mathchingMutex;
map<int,prt_Filed> Filedmap;