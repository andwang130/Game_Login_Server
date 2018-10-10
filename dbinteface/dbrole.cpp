//
// Created by wj on 18-10-9.
//

#include "dbrole.h"
void  dbrole::getrole(int userid,Role &role)
{

    mysqlpp::Query query=coon->query("select * from Role where userid=%1");
    query.parse();
    query.template_defaults[1]=userid;
    mysqlpp::StoreQueryResult result =query.store();

    if(result.num_rows()>0)
    {
        role.userid_=result[0]["userid"];
        role.money_=result[0]["money"];
        role.exp_=result[0]["exp"];
        role.rolename_=string(result[0]["rolename"]);
        role.roleid_=result[0]["roleid"];
        role.level_=result[0]["level"];
    }


    
}

int dbrole::addrole(Role role)
{
//    roleid INT(4) NOT NULL AUTO_INCREMENT primary key,
//    rolename VARCHAR(32) NOT NULL,
//            exp INT NOT NULL,
//            money INT NOT NULL,
//            level INT NOT NULL,
//            createDate DATETIME NOT NULL
    mysqlpp::Query query=coon->query("INSERT INTO Role(rolename, exp, money,createDate,userid,level) SELECT %1q,%2,%3,%4q,%5,%6 FROM dual WHERE not exists (select * from Role where Role.rolename = %7q)");
    query.parse();
    query.template_defaults[1]=role.rolename_.c_str();
    query.template_defaults[2]=role.exp_;
    query.template_defaults[3]=role.money_;
    query.template_defaults[4]=Datetime::get_dateTime().c_str();
    query.template_defaults[5]=role.userid_;
    query.template_defaults[6]=role.level_;
    query.template_defaults[7]=role.rolename_.c_str();
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