//
// Created by wj on 18-10-5.
//

#include "LoginHandler.h"
#include "../commds.h"
LoginHandler::LoginHandler(const CoonPrt coonPrt, protocol &aProtocol):BaseHandler(coonPrt,aProtocol)
{
    if(aProtocol.coomd==Login_model::to_login::coomd::Login)
    {
        login();
    }
    if(aProtocol.coomd==Login_model::to_login::coomd::Register)
    {
        register_();
    }
}
void LoginHandler::login()
{

}

void LoginHandler::register_()
{

}