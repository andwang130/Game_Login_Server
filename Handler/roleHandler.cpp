//
// Created by wj on 18-10-9.
//

#include "roleHandler.h"
#include "../dbinteface/dbrole.h"
#include "../protobuf_maegss/User.pb.h"

using namespace std;
roleHandler::roleHandler(const CoonPrt coonPrt, protocol_ &aProtocol):BaseHandler(coonPrt,aProtocol)
{

    switch(aProtocol_.coomd)
    {
        case role::roleinfo::coomd::Addrole:
            addrole();
            break;
        case role::roleinfo::coomd::Getrole:
            getrole();
            break;
        case role::roleinfo::coomd::Setrole:
            setrole();
            break;

    }
}
//
void roleHandler::setrole()
{



}


//获得角色信息
void roleHandler::getrole()
{
    protocol_ newprotocol;

    newprotocol.fin=0;
    newprotocol.model=2;
    newprotocol.model2=1;
    newprotocol.coomd=1;

    User::Rqrole rqrole;

    prt_User prt_user=login_ve();

    Role role;
    if(prt_user!= nullptr)
    {
        dbrole db_role;
        db_role.getrole(prt_user->userid,role);
        {
            std::lock_guard<std::mutex> lk(roleMutex);
            Login_role[coonPrt_]=std::make_shared<Role>(role);

        }

    }

    cout<<role.rolename_<<endl;
    rqrole.set_rolename(role.rolename_);
    rqrole.set_exp(role.exp_);
    rqrole.set_money(role.money_);
    rqrole.set_level(role.level_);

    newprotocol.data=rqrole.SerializeAsString();
    std::string buf=newprotocol.get_byte();
    coonPrt_->sendloop(buf);





}
void roleHandler::addrole()
{


    protocol_ newprotocol;
    newprotocol.fin=0;
    newprotocol.model=2;
    newprotocol.model2=1;
    newprotocol.coomd=3;

    prt_User prt_user=login_ve();

    User::addrole add_role;


    User::rqcode rq_code;
    if(prt_user!= nullptr)
    {
        Role role;

        add_role.ParseFromString(aProtocol_.data);

        role.rolename_=add_role.rolename();
        role.userid_=prt_user->userid;
        dbrole db_role;

        int ret=db_role.addrole(role);

        rq_code.set_code(ret);

    }
    else
    {
        rq_code.set_code(-3);
    }
    newprotocol.data=rq_code.SerializeAsString();
    std::string buf=newprotocol.get_byte();
    coonPrt_->sendloop(buf);

}

prt_User roleHandler::login_ve()
{
    std::lock_guard<std::mutex> lk(Mutex);

    prt_User User= nullptr;
    auto ite =Login_User.find(coonPrt_);

    if(ite==Login_User.end())
    {
        return User;
    }
    else
    {
        User=ite->second;
        return User;
    }




}