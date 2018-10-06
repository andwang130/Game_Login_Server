//
// Created by wj on 18-10-5.
//

#include <sys/user.h>

#ifndef LOGINSERVER_COMMDS_H
#define LOGINSERVER_COMMDS_H



#include <iostream>
#include "Net/Tcpcoonetion.h"

typedef ZL::Net::TcpcoontionPrt CoonPrt;
struct protocol_
{
    int16_t model;
    int16_t model2;
    int32_t coomd;
    std::string data;
};

namespace Login_model
{
   const  unsigned int level1=1;  //一级指令

    namespace  to_login
    {
       const int level2=1; //二级指令

       namespace coomd
       {
           const int Login=1;  //三级
           const int Register=2;
       }
    }


}
#endif //LOGINSERVER_COMMDS_H