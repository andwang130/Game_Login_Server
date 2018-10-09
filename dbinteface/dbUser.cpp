//
// Created by wj on 18-10-8.
//

#include "dbUser.h"

int dbUser::add_User(MUser &user)
{
    mysqlpp::Query query=coon->query("INSERT INTO User(name, pswd, phone,email,createDate) SELECT %1q, %2q,%3q,%4q,%5q FROM dual WHERE not exists (select * from User where User.name = %6q)");
    query.parse();//开启模板查询
    query.template_defaults[1]=user.name_.c_str();
    query.template_defaults[2]=user.pswd_.c_str();
    query.template_defaults[3]=user.phone_.c_str();
    query.template_defaults[4]=user.email_.c_str();
    query.template_defaults[5]=Datetime::get_dateTime().c_str();
    query.template_defaults[6]=user.name_.c_str();
    mysqlpp::SimpleResult simpleResult=query.execute();
    if(simpleResult)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
std::shared_ptr<MUser>  dbUser::get_User(string &name)
{
    mysqlpp::Query query=coon->query("select * from User where name=%1q");
    query.parse();
    query.template_defaults[1]=name.c_str();
    mysqlpp::StoreQueryResult result=query.store();
    std::shared_ptr<MUser>  mUser;
    if(result.num_rows()>0)
    {
        mUser->name_=result[0]["name"].c_str();
        mUser->pswd_=result[0]["pswd"].c_str();
        mUser->email_=result[0]["email"].c_str();
        mUser->pswd_=result[0]["phone"].c_str();
        mUser->userid=result[0]["userid"];
        return mUser;
    }
    return mUser;
}


