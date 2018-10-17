//
// Created by wj on 18-10-9.
//

#ifndef LOGINSERVER_ROLE_H
#define LOGINSERVER_ROLE_H

#include <iostream>
using  namespace std;
class Role {
public:
    Role(std::string rolename,int exp,int money,int level,int userid,int roleid);
    Role();
    std::string rolename_; //角色名称
    int exp_;       //等级
    int money_;     //金钱
    int level_;     //等级
    int userid_;    //用户id
    int roleid_;   //角色id
    int Fieldid_;  //所属房间

};
#endif //LOGINSERVER_ROLE_H
