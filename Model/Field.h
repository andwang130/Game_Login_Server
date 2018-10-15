//
// Created by wj on 18-10-10.
//

#ifndef LOGINSERVER_FIELD_H
#define LOGINSERVER_FIELD_H

#include <iostream>
#include <memory>
#include <map>
#include "Role.h"
#include "../commds.h"
using  namespace std;

typedef std::shared_ptr<Role> prt_Role;

class Field {
public:
    void addPlayer(const CoonPrt coonPrt,const prt_Role prt_role);
    void removePlauer(const CoonPrt coonPrt);
    void setsize(int num);
    std::map<CoonPrt,prt_Role> players_;
    bool state;  //状态
    int sizemax; //最大人数
    int nowNum; //当前人数
    int confirmedNum; //确任的人数

};



typedef std::shared_ptr<Field> prt_field;
#endif //LOGINSERVER_FIELD_H
