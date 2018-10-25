//
// Created by wj on 18-10-17.
//

#include "SelectHero.h"
#include "../protobuf_maegss/User.pb.h"
#include "../protobuf_maegss/to_Fight.pb.h"
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
        case selecthore::select::coomd::cilck:
        {
            cilck_hero();
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
    User::cilck_hero cilck_hero_;
    if(!cilck_hero_.ParseFromString(aProtocol_.data))
    { return; }

    std::lock_guard<std::mutex> lk(roomMutex);
    auto ite=roommap.find(cilck_hero_.room_id());
    if(ite==roommap.end())  //房间不存在
    { return;}

    auto play_ite=ite->second->plays_.find(coonPrt_);
    if(play_ite==ite->second->plays_.end()) //不在该房间
    {return;}

    play_prt play_prt_=play_ite->second;
    int id=cilck_hero_.heroid();
    if(play_prt_->heroid==-1&&std::find(ite->second->hero_in.begin(),ite->second->hero_in.end(),id)==ite->second->hero_in.end())
    {
        play_prt_->click_hero=id;
    } else
    {
        return;
    }


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


    User::to_room to_room_;
    if(!to_room_.ParseFromString(aProtocol_.data))
    { return; }

    std::lock_guard<std::mutex> lk(roomMutex);
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

    gethero(buf);
    //返回所有英雄信息
    tosend(4,1,5,buf);

}


//一个用户确定选择了英雄，修改该用户的英雄id,对所用用户群发该用户的状态
void SelectHero::select_hero()
{
    User::select_hero select_hero_;
    if(!select_hero_.ParseFromString(aProtocol_.data))
    { return; }

    std::lock_guard<std::mutex> lk(roomMutex);

    auto ite=roommap.find(select_hero_.room_id());
    if(ite==roommap.end())
    { return;}

    auto play_ite=ite->second->plays_.find(coonPrt_);
    if(play_ite==ite->second->plays_.end())
    {return;}
    play_prt play_prt_=play_ite->second;

    //为选择英雄，而且有一个点击的英雄
    if(play_prt_->heroid==-1&&play_prt_->click_hero!=-1&&std::find(ite->second->hero_in.begin(),ite->second->hero_in.end(),play_prt_->click_hero)==ite->second->hero_in.end())
    {
        play_prt_->heroid=play_prt_->click_hero;
        ite->second->hero_in.push_back(play_prt_->heroid);
        ite->second->ready_num+=1;
    } else
    {
        return;
    }
    std::string buf;
    set_role_hore(play_prt_,buf);
    group_message(4,1,3,buf,ite->second->plays_,coonPrt_);

    //给自己发，确认选择
    tosend(4,1,2,buf);
    if(ite->second->ready_num==ite->second->plays_.size())
    {
        ready_all(ite->first,ite->second);
    }
}

//所有人全部选择英雄选择英雄
void SelectHero::ready_all(int roomid,prt_room &room)
{

    std::string buf;
    get_toFigth_servers_init(room->plays_,roomid,buf);

    protocol_ newprotocol;
    newprotocol.model=10;
    newprotocol.model2=1;
    newprotocol.coomd=1;
    newprotocol.fin=0;
    newprotocol.data=buf;

    Figth_servers[roomid%Figth_servers.size()]->send(newprotocol.get_byte());

}
void SelectHero::get_toFigth_servers_init(std::map<CoonPrt,play_prt> &playmap,int roomid,std::string &buf)
{
    to_Figth::Figth_init figth_init;
    for(auto ite:playmap)
    {   to_Figth::play *pyal_=figth_init.add_plays();
        pyal_->set_index(ite.second->index);
        pyal_->set_ranks(ite.second->Ranks);
        pyal_->set_rolename(ite.second->name);
        pyal_->set_heroid(ite.second->heroid);
        cout<<ite.second->heroid<<endl;
    }
    figth_init.set_roomid(roomid);

    std::cout<<figth_init.DebugString()<<std::endl;

    buf=std::move(figth_init.SerializeAsString());

}
void SelectHero::gethero(std::string &buf)
{

    User::hero_all hero_all;
    for(int i=0;i<HERO_LIST.size();i++)
    {
       User::hero *new_hero=hero_all.add_hero_list();
        new_hero->set_heroid(HERO_LIST[i].id_);
        new_hero->set_heroname(HERO_LIST[i].name_);
        new_hero->set_describe(HERO_LIST[i].describe_);
    }

    buf=std::move(hero_all.SerializeAsString());

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
        role_hore_->set_heroid(play_prt1->heroid);
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
    role_hore_.set_heroid(play_prt1->heroid);
    buf=std::move(role_hore_.SerializeAsString());
}

