//
// Created by wj on 18-10-9.
//
#include "Role.h"
Role::Role(string rolename, int exp, int money, int level,int userid,int roleid):
roleName_(rolename),
exp_(exp),
money_(money),
level_(level),
userid_(userid),
roleid_(roleid)
{

}

Role::Role()
{
    roleName_="";
    exp_=0;
    money_=0;
    level_=0;
    userid_=0;
    roleid_=0;
}