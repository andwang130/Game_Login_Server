//
// Created by wj on 18-10-5.
//
#include "User.h"
void User::add_User(string name, string pswd)
{
    name_=name;
    pswd_=pswd;
}
User::User()
{

}
User::User(string name, string pswd):
name_(name),
pswd_(pswd)
{

}