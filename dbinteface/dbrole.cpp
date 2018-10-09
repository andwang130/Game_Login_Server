//
// Created by wj on 18-10-9.
//

#include "dbrole.h"
Role dbrole::getrole()
{

    
}

int dbrole::addrole(Role role)
{
    mysqlpp::Query query=coon->query("INSERT INTO Role(rolename, exp, money,createDate,userid) SELECT %1q, %2,%3,%4,%5 FROM dual WHERE not exists (select * from Role where Role.rolename = %6q)");
    query.parse();
    query.template_defaults[1]=role.roleName_.c_str();
    query.template_defaults[2]=role.exp_;
    query.template_defaults[3]=role.money_;
    query.template_defaults[4]=Datetime::get_dateTime().c_str();
    query.template_defaults[5]=role.userid_;
    mysqlpp::SimpleResult result=query.execute();
    if(result)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}