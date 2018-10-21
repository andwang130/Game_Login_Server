//
// Created by wj on 18-10-5.
//

#ifndef LOGINSERVER_INTERMEDIARY_H
#define LOGINSERVER_INTERMEDIARY_H

#endif //LOGINSERVER_INTERMEDIARY_H
//中间类，根据指令调用handler
#include "commds.h"
#include "Net/Tcpcoonetion.h"
#include "Handler/LoginHandler.h"
#include "Handler/roleHandler.h"
#include "Handler/matchingHandler.h"
#include "Handler/SelectHero.h"
#include "Handler/TalkHandler.h"
using namespace ZL;
using namespace ZL::Net;
inline void intermeadiary(const TcpcoontionPrt connprt,protocol_ &aProtocol_)
{

    switch (aProtocol_.model)
    {
        case Login_model::level1:
        {
            LoginHandler loginHandler(connprt, aProtocol_);
            break;
        }
        case role::level1:
        {
            roleHandler roleHandler1(connprt,aProtocol_);
            break;
        }
        case matching::level1:
        {
            matchingHandler matchingHandler_(connprt,aProtocol_);
            break;
        }
        case selecthore::level1:
        {
            SelectHero selectHero(connprt,aProtocol_);
            break;
        }
        case talk::level1:
        {
            TalkHandler talkHandler(connprt,aProtocol_);
            break;
        }


        default:
        {
            cout<<aProtocol_.data<<endl;
            protocol_ new_protocol_;
            new_protocol_.fin=0;
            new_protocol_.model=10;
            new_protocol_.model2=10;
            new_protocol_.coomd=10;
            new_protocol_.data="Loing_server";
            connprt->sendloop(new_protocol_.get_byte());
        }


    }

}