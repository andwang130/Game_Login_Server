//
// Created by wj on 18-10-5.
//
#include "User.h"

//

void MUser::add_User(string name, string pswd)
{
    name_=name;
    pswd_=pswd;
}
MUser::MUser()
{

}
MUser::MUser(string name,string pswd,string phone,string email):
name_(name),
pswd_(pswd),
phone_(phone),
email_(email)
{

}