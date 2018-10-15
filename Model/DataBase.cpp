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

void baseRemove(const CoonPrt &coonPrt)
{
std::lock_guard<std::mutex> lk(mathchingMutex);

std::lock_guard<std::mutex> rolk(roleMutex);

std::lock_guard<std::mutex> uslk(Mutex);

    removeFiledmap(coonPrt);

    removeLogin_role(coonPrt);

    removeLogin_User(coonPrt);

}
void removeFiledmap(const CoonPrt &coonPrt)
{
    auto role=Login_role.find(coonPrt);
    int fieldid=role->second->Fieldid_;
    auto field=Filedmap.find(fieldid)->second;
    field->players_.erase(coonPrt);

}

void removeLogin_role(const CoonPrt &coonPrt)
{
    Login_role.erase(coonPrt);
}

void removeLogin_User(const CoonPrt &coonPrt)
{
    Login_User.erase(coonPrt);
}