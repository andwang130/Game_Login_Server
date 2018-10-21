//
// Created by wj_de on 18-10-21.
//

#include "ToFigthHandler.h"
#include "../protobuf_maegss/to_Fight.pb.h"
ToFigthHandler::ToFigthHandler(const CoonPrt coonPrt, protocol_ &aProtocol):BaseHandler(coonPrt,aProtocol)
{
    switch (aProtocol.coomd)
    {
        case 1:
        {
            rq_Figth_init();
            break;
        }
    }

}
void ToFigthHandler::rq_Figth_init()
{
    to_Figth::rq_Fight_init rq_fight_init_;
    if(!rq_fight_init_.ParseFromString(aProtocol_.data))
    {
        return;
    }

    int fightid=rq_fight_init_.fight_id();

    std::string ip=rq_fight_init_.ip();

    int port=rq_fight_init_.port();

    prt_room prtroom_;
    {
        std::lock_guard<std::mutex> lk(roomMutex);
        auto ite=roommap.find(rq_fight_init_.roomid());
        if(ite==roommap.end())
        { return;}
        prtroom_=ite->second;
    }
    for(to_Figth::Fight_play * play_figth :rq_fight_init_.add_fight_plays())
    {
        for(auto play_room:prtroom_->plays_)
        {
            if(play_room.second->index==play_figth->index())
            {
                std::string buf;
                rq_Fight_init_user(fightid,ip,port,play_figth->play_id(),buf);
                send_fight_inti_user(play_room.first,buf);
            }
        }
    }
}

void ToFigthHandler::rq_Fight_init_user(int fight_id,std::string &ip, int port,int play_id,std::string &buf)
{
    to_Figth::rq_Fight_init_user rq_fight_init_user_;

    rq_fight_init_user_.set_ip(ip);

    rq_fight_init_user_.set_fight_id(fight_id);

    rq_fight_init_user_.set_port(port);

    rq_fight_init_user_.set_play_id(play_id);
    buf=std::move(rq_fight_init_user_.SerializeAsString());

}
void ToFigthHandler::send_fight_inti_user(CoonPrt &coonPrt,std::string &messsage)
{

    tosend(5,1,8,messsage,coonPrt);

}
