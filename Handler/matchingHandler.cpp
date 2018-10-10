//
// Created by wj on 18-10-10.
//

#include "matchingHandler.h"
#include "../protobuf_maegss/User.pb.h"
int matchingHandler::index=0;
matchingHandler::matchingHandler(const CoonPrt coonPrt, protocol_ &aProtocol):BaseHandler(coonPrt,aProtocol)
{
    switch (aProtocol.coomd)
    {
        case matching::matching_::coomd::play:
        {
            playmatching();
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

        Field field;
        field.setsize(num);
        {
            std::lock_guard<mutex> lk(roleMutex);
            field.addPlayer(coonPrt_,Login_role.find(coonPrt_)->second);

        }
        Filedmap[index]=std::make_shared<Field>(field);
        index++;

    }
    else
    {
        for(auto ite:Filedmap)
        {
            if(num==ite.second->sizemax&&ite.second->state== false)
            {
                {
                    std::lock_guard<mutex> lk(roleMutex);
                    ite.second->addPlayer(coonPrt_,Login_role.find(coonPrt_)->second);
                    ite.second->nowNum++;

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
        }

    }
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
    for(auto new_ite:ite->second->players_)
    {
        //通知该房间的用户完成匹配开始确认
        new_ite.first->sendloop(buf);
    }
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

