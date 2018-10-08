//
// Created by wj on 18-10-5.
//

#include "LoginHandler.h"
#include "../commds.h"
#include "../protobuf_maegss/User.porto.pb.h"
#include "../Model/DataBase.h"
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
    std::string pswd=reLogin.pasw();
    std::string name=reLogin.name();

    protocol_ newprotocol;
    newprotocol.fin=0;
    newprotocol.model=1;
    newprotocol.model2=0;
    newprotocol.coomd=1;
    int flag=0;//0成功，-1失败。-2未注册
    {
        std::lock_guard<std::mutex> lk(Mutex);
        auto ite=UserMap.find(name);
        if(ite==UserMap.end())
        {
            flag=-2;
        } else
        {
            if(ite->second->name_==name&&ite->second->pswd_==pswd)
            {
                flag=0;
            } else
            {
                flag=-1;
            }
        }
    }
    User::RqLogin rqLogin;
    rqLogin.set_code(flag);
    std::string buf=newprotocol.get_byte();
    coonPrt_->sendloop(buf);
}

void LoginHandler::register_()
{

    User::ReRegister reRegister;
    reRegister.ParseFromString(aProtocol_.data);
    std::string name=reRegister.name();
    std::string pswd=reRegister.pswd();
    std::string phone=reRegister.phone();
    std::string email=reRegister.email();

    std::string buf;

    protocol_ newprotocol;
    newprotocol.fin=0;
    newprotocol.model=1;
    newprotocol.model2=0;
    newprotocol.coomd=2;

    int flag=0;//注册成功。1失败
    {
        std::lock_guard<std::mutex> lk(Mutex);  //锁
        if (UserMap.find(name) == UserMap.end()) {

            //未注册的用护
            //添加到注册用户当中
            prt_User new_user(new MUser(name, pswd, phone, email));
            UserMap[name] = new_user;


        } else {
            flag = -1;
        }
    }
    User::RqRegister rqRegister;
    rqRegister.set_code(flag);
    newprotocol.data=reRegister.SerializeAsString();
    buf=newprotocol.get_byte();
    coonPrt_->sendloop(buf);


}