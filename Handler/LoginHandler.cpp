//
// Created by wj on 18-10-5.
//

#include "LoginHandler.h"
#include "../commds.h"
#include "../protobuf_maegss/User.pb.h"
#include "../Model/DataBase.h"
#include "../dbinteface/dbUser.h"
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
    std::string pswd=reLogin.pswd();
    std::string name=reLogin.name();

    protocol_ newprotocol;
    newprotocol.fin=0;
    newprotocol.model=1;
    newprotocol.model2=0;
    newprotocol.coomd=1;

    int flag=0;//0成功，-1失败。-2未注册
    dbUser dbuser;
    prt_User mUser=dbuser.get_User(name);
    if(mUser->name_.empty())
    {
        flag=-2;
    }
    else
    {
        if(mUser->name_==name&&mUser->pswd_==pswd)
        {
            flag=0;
            {
                std::lock_guard<mutex> lk(Mutex);
                Login_User[coonPrt_] = mUser;
            }

        } else
        {
            flag=-1;
        }
    }


    User::RqLogin rqLogin;
    rqLogin.set_code(flag);
    newprotocol.data=rqLogin.SerializeAsString();
    std::string buf=newprotocol.get_byte();
    coonPrt_->sendloop(buf);
}

void LoginHandler::register_()
{




    User::ReRegister reRegister;
    reRegister.ParseFromString(aProtocol_.data);
    MUser mUser;
    mUser.name_=std::move(reRegister.name());
    mUser.pswd_=std::move(reRegister.pswd());
    mUser.phone_=std::move(reRegister.phone());
    mUser.email_=std::move(reRegister.email());

    std::string buf;
    cout<<mUser.pswd_<<endl;


    int flag=0;

    dbUser dbuser;
    if(dbuser.add_User(mUser)==0)
    {
        flag=0;
    } else
    {
        flag=-1;
    }



    protocol_ newprotocol;
    newprotocol.fin=0;
    newprotocol.model=1;
    newprotocol.model2=0;
    newprotocol.coomd=2;


    User::RqRegister rqRegister;
    rqRegister.set_code(flag);
    cout<<"bytesize:"<<reRegister.ByteSize()<<endl;
    newprotocol.data=reRegister.SerializeAsString();
    buf=newprotocol.get_byte();

    coonPrt_->sendloop(buf);


}