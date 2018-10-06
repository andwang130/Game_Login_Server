//
// Created by wj on 18-10-5.
//

#include "LoginHandler.h"
#include "../commds.h"
#include "../protobuf_maegss/User.porto.pb.h"
LoginHandler::LoginHandler(const CoonPrt coonPrt, protocol_ &aProtocol):BaseHandler(coonPrt,aProtocol)
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
    User::ReLogin reLogin;
    reLogin.ParseFromString(aProtocol_.data);
    std::cout<<reLogin.pasw()<<std::endl;
    std::cout<<reLogin.name()<<std::endl;
}

void LoginHandler::register_()
{

}