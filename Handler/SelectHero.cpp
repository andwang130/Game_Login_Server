//
// Created by wj on 18-10-17.
//

#include "SelectHero.h"
#include "../protobuf_maegss/User.pb.h"
SelectHero::SelectHero(const CoonPrt coonPrt,protocol_ &aProtocol):BaseHandler(coonPrt,aProtocol)
{


    switch (aProtocol.coomd)
    {
        case selecthore::select::coomd::into:
        {
            into_room();
            break;
        }
        case selecthore::select::coomd::select:
        {
            select_hero();
            break;
        }
        default:
        {
            break;
        }


    }
}

void SelectHero::cilck_hero()
{
    std::lock_guard<std::mutex> lk(roomMutex);
    User::cilck_hero cilck_hero_;
    if(!cilck_hero_.ParseFromString(aProtocol_.data))
    { return; }

    auto ite=roommap.find(cilck_hero_.room_id());
    if(ite==roommap.end())
    { return;}

    auto play_ite=ite->second->plays_.find(coonPrt_);
    if(play_ite==ite->second->plays_.end())
    {return;}

    play_prt play_prt_=play_ite->second;
    play_prt_->click_hero=cilck_hero_.heroid();

    std::string buf;
    set_role_hore(play_prt_,buf);

    for(auto play_ite:ite->second->plays_)
    {
        if(play_ite.second->Ranks==play_prt_->Ranks)
        {
            tosend(4,1,3,buf,play_ite.first);
        }
    }


}


void SelectHero::into_room()
{


    std::lock_guard<std::mutex> lk(roomMutex);
    User::to_room to_room_;
    if(!to_room_.ParseFromString(aProtocol_.data))
    { return; }

    auto ite=roommap.find(to_room_.room_id());
    if(ite==roommap.end())
    { return;}

    auto play_ite=ite->second->plays_.find(coonPrt_);
    if(play_ite==ite->second->plays_.end())
    {return;}

    play_prt play_prt_=play_ite->second;
    play_prt_->toroom= true;
    std::string buf;
    set_role_hore(play_prt_,buf);

    group_message(4,1,3,buf,ite->second->plays_,coonPrt_);

    getroom(ite->second->plays_,buf);

    tosend(4,1,4,buf);


}


//一个用户确定选择了英雄，修改该用户的英雄id,对所用用户群发该用户的状态
void SelectHero::select_hero()
{


}
//一个用户进入了房间，需要获得所用用户的信息
void SelectHero::getroom(std::map<CoonPrt,play_prt> &playmap,std::string &buf)
{

    User::roominfo roominfo_;
    for(auto ite:playmap)
    {
        User::role_hore *role_hore_=roominfo_.add_role_list();
        play_prt play_prt1=ite.second;
        role_hore_->set_index(play_prt1->index);
        role_hore_->set_cilckhero(play_prt1->click_hero);
        role_hore_->set_ranks(play_prt1->Ranks);
        role_hore_->set_rolename(play_prt1->name);
        role_hore_->set_toroom(play_prt1->toroom);
    }
    buf=std::move(roominfo_.SerializeAsString());

}

void SelectHero::group_message(int model1,int model2,int coomd,std::string &data,std::map<CoonPrt,play_prt> &playmap)
{
    for(auto ite:playmap)
    {
        tosend(model1,model2,coomd,data,ite.first);
    }
}
void SelectHero::group_message(int model1,int model2,int coomd,std::string &data,std::map<CoonPrt,play_prt> &playmap,const CoonPrt coonPrt)
{
    for(auto ite:playmap)
    {
        if(ite.first!=coonPrt)
        {
            tosend(model1, model2, coomd, data, ite.first);
        }
    }
}
void SelectHero::set_role_hore(play_prt &play_prt1,std::string &buf)
{
    User::role_hore role_hore_;
    role_hore_.set_index(play_prt1->index);
    role_hore_.set_cilckhero(play_prt1->click_hero);
    role_hore_.set_ranks(play_prt1->Ranks);
    role_hore_.set_rolename(play_prt1->name);
    role_hore_.set_toroom(play_prt1->toroom);
    buf=std::move(role_hore_.SerializeAsString());
}