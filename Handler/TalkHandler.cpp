//
// Created by wj on 18-10-18.
//

#include "TalkHandler.h"
#include "../protobuf_maegss/User.pb.h"

TalkHandler::TalkHandler(const CoonPrt coonPrt, protocol_ &aProtocol):BaseHandler(coonPrt,aProtocol)
{

    switch(aProtocol_.coomd)
    {
        case talk::send::coomd::send_all:
        {
            send_all();
            break;
        }
        case talk::send::coomd::send_room:
        {
            send_room_all();
            break;
        }
        case talk::send::coomd::send_tem:
        {
            send_room_tem();
            break;
        }
        default:
        {
            break;
        }

    }
}
void TalkHandler::send_room_tem()
{
    send_room(SEND_TEM);
}

void TalkHandler::send_room_all()
{
    send_room(SEND_ROOM);
}
void TalkHandler::send_room(int flag)
{
    User::re_message_room message_room;
    if(!message_room.ParseFromString(aProtocol_.data))
    { return;}
    int roomid=message_room.roomid();

    User::send_message message;
    message.set_message(message_room.message());

    std::lock_guard<std::mutex> lk(roomMutex);
    auto ite=roommap.find(roomid);
    if(ite==roommap.end())
    { return;}

    auto plays=ite->second->plays_;

    auto my_play=plays.find(coonPrt_);
    if(my_play==plays.end())
    { return;}

    message.set_name(my_play->second->name);
    std::string buf=std::move(message.SerializeAsString());
    if(flag==SEND_ROOM) {
        for (auto play:plays) {
            tosend(5, 1, 1, buf, play.first);
        }
    }
    else if(flag==SEND_TEM)
    {
        for (auto play:plays) {
            if(play.second->Ranks==my_play->second->Ranks)
            {
            tosend(5, 1, 1, buf, play.first);
            }
        }
    }

}
//向所有已经登录的角色发送消息
void TalkHandler::send_all()
{

    User::re_message_all message_all;
    if(!message_all.ParseFromString(aProtocol_.data))
    { return; }
    User::send_message message;

    message.set_message(message_all.message());
    std::lock_guard<std::mutex> lk(roleMutex);
    //获得该连接的角色
    auto role_ite=Login_role.find(coonPrt_);
    if(role_ite==Login_role.end())
    { return;}

    message.set_name(role_ite->second->rolename_);

    std::string buf=std::move(message.SerializeAsString());
    for(auto ite:Login_role)
    {
        tosend(5,1,1,buf,ite.first);
    }
}