//
// Created by wj on 18-10-10.
//

#include "matchingHandler.h"
#include "../protobuf_maegss/User.pb.h"
#include "../base/timeQueue/TimeQueue.h"
int matchingHandler::index=0;
matchingHandler::matchingHandler(const CoonPrt coonPrt, protocol_ &aProtocol):BaseHandler(coonPrt,aProtocol)
{
    switch (aProtocol.coomd)
    {
        case matching::matching_::coomd::play:
        {
            playmatching();
            break;
        }
        case matching::matching_::coomd::confirm:
        {
            confirm();
            break;
        }


    }
}
void matchingHandler::playmatching()
{
    User::matching matching_;
    matching_.ParseFromString(aProtocol_.data);
    int num=matching_.peoplenum();
    std::lock_guard<mutex> lk(mathchingMutex);
    if(Filedmap.empty())
    {

        create_field(num);

    }
    else
    {
        for(auto ite:Filedmap)
        {
            if(num==ite.second->sizemax&&ite.second->state== false)
            {
                {
                    std::lock_guard<mutex> lk(roleMutex);
                    auto role_ite=Login_role.find(coonPrt_);
                    if(role_ite==Login_role.end())
                    { return;;}
                    prt_Role role_prt=role_ite->second;
                    ite.second->addPlayer(coonPrt_,role_prt);
                    ite.second->nowNum++;

                    role_prt->Fieldid_=ite.first;
                    if(ite.second->nowNum==ite.second->sizemax)
                    {
                        ite.second->state= true;
                        completion(ite.first);
                    }
                    else
                    {
                        entering(ite.first);
                    }

                }
            }
        else
            {

                create_field(num);
            }
        }

    }
}

void matchingHandler::confirm()
{

    std::lock_guard<mutex> mathlk(mathchingMutex);

    int fieldid;
    prt_Filed prt_Filed_;
    {
        std::lock_guard<mutex> lk(roleMutex);
        auto role=Login_role.find(coonPrt_);
        if(role==Login_role.end())
        {
            return;
        }
        fieldid = role->second->Fieldid_;
    }
    auto ite=Filedmap.find(fieldid);

    if(ite==Filedmap.end())
    {
        return;
    }
    prt_Filed_=ite->second;
    prt_Filed_->confirmedNum++;

    if(prt_Filed_->confirmedNum==prt_Filed_->sizemax)
    {
        User::room_id room_id_;
        room_id_.set_id(fieldid);

        protocol_ newprotocol;
        newprotocol.model=3;
        newprotocol.model2=1;
        newprotocol.coomd=7;
        newprotocol.data=room_id_.SerializeAsString();
        std::string byte=newprotocol.get_byte();


        {
            std::lock_guard<std::mutex> lk(roomMutex);
            Room room;
            int ranks=1;
            int index=0;
            for (auto ite:prt_Filed_->players_)
            {

                Play play;
                play.index=(ranks-1)*5+index;
                play.Ranks=ranks;
                play.name=ite.second->rolename_;
                if(index%prt_Filed_->sizemax==0)
                {
                    ranks++;
                    index=0;
                }


                    index++;
                
                room.plays_[ite.first] = std::make_shared<Play>(play);
                ite.first->sendloop(byte);
            }
            //创建一个房间
            roommap[ite->first]=std::make_shared<Room>(room);
        }
    }


}
//添加一个房间
void matchingHandler::create_field(int num)
{

    Field field;
    field.nowNum=1;
    field.confirmedNum=0;
    field.setsize(num);
    {
        std::lock_guard<mutex> lk(roleMutex);
        prt_Role role_prt=Login_role.find(coonPrt_)->second;
        field.addPlayer(coonPrt_,role_prt);
        role_prt->Fieldid_=index;

    }
    Filedmap[index]=std::make_shared<Field>(field);
    index++;

}
void waitmatching(int fieldid)
{

    cout<<"关闭一个房间"<<endl;
    std::lock_guard<std::mutex> lk(mathchingMutex);
    auto field_ite=Filedmap.find(fieldid);
    if(field_ite==Filedmap.end())
    { return;}
    auto field=field_ite->second;
    if(field->confirmedNum!=field->sizemax)
    {
        User::rqcode rqcode_;
        rqcode_.set_code(6);
        protocol_ newprotocol_;
        newprotocol_.model=3;
        newprotocol_.model2=1;
        newprotocol_.fin=0;
        newprotocol_.coomd=1;
        newprotocol_.data=rqcode_.SerializeAsString();
        std::string byte=newprotocol_.get_byte();
        for(auto ite:field->players_)
        {

            ite.first->sendloop(byte);
        }
    }

        Filedmap.erase(fieldid);



}
void matchingHandler::completion(int fieldID)
{
    protocol_ newprotocol;
    newprotocol.model=3;
    newprotocol.model2=1;
    newprotocol.coomd=1;
    newprotocol.fin=0;

    User::rqcode rqcode_;
    rqcode_.set_code(4);
    newprotocol.data=rqcode_.SerializeAsString();
    std::string buf=newprotocol.get_byte();
    auto ite=Filedmap.find(fieldID);

    {
        std::lock_guard<std::mutex> lk(roomMutex);
        Room room;

        for (auto new_ite:ite->second->players_) {
            Play play;
            room.plays_[coonPrt_] = std::make_shared<Play>(play);
            //通知该房间的用户完成匹配开始确认
            new_ite.first->sendloop(buf);
        }

        //创建一个房间
        roommap[ite->first]=std::make_shared<Room>(room);
    }
    TimeQueue *timeQueue=TimeQueue::getTimeQueue();
    itimerspec itimerspec_;

    itimerspec_.it_value.tv_sec=30;
    itimerspec_.it_value.tv_nsec=0;
    itimerspec_.it_interval.tv_nsec=0;
    itimerspec_.it_interval.tv_sec=0;
    //定时任务30秒后执行
    Timer timer(std::bind(waitmatching,fieldID),itimerspec_,0);
    timeQueue->addTimer(std::make_shared<Timer>(timer));
}

void matchingHandler::entering(int fieldID)
{

    protocol_ newprotocol;
    newprotocol.model=3;
    newprotocol.model2=1;
    newprotocol.coomd=1;
    newprotocol.fin=0;

    User::rqcode rqcode_;
    rqcode_.set_code(5);
    newprotocol.data=rqcode_.SerializeAsString();
    std::string buf=newprotocol.get_byte();

    //计入匹配等待
    coonPrt_->sendloop(buf);


}

