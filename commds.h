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
    int8_t fin;
    int16_t model;
    int16_t model2;
    int32_t coomd;
    std::string data;
    std::string  get_byte()
    {

        std::string new_string;

        int len=13+data.size();
        new_string.resize(len);
        char buf[len];
        int index=0;
        memcpy(buf,&fin, sizeof(fin));
        index+= sizeof(fin);

        memcpy(buf+index,&len, sizeof(len));
        index+= sizeof(len);

        memcpy(buf+index,&model, sizeof(model));
        index+= sizeof(model);

        memcpy(buf+index,&model2, sizeof(model2));
        index+= sizeof(model2);

        memcpy(buf+index,&coomd, sizeof(coomd));
        index+= sizeof(coomd);

        memcpy(buf+index,data.c_str(),data.size());
        new_string=buf;
        return std::move(new_string);

    }
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