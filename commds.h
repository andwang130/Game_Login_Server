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


        int len=13+data.size();
        std::string new_string;
        new_string.resize(len);
        char buf[len];
        memset(buf,0,len);
        int index=0;
        memcpy(&*new_string.begin(),&fin, sizeof(fin));

        index+= sizeof(fin);
        //本机字节序转换网络字节序
        int bodySize=htobe32(data.size());
        memcpy(&*new_string.begin()+index,&bodySize, sizeof(bodySize));
        index+= sizeof(len);
        model=htobe16(model);
        memcpy(&*new_string.begin()+index,&model, sizeof(model));
        index+= sizeof(model);

        model2=htobe16(model2);
        memcpy(&*new_string.begin()+index,&model2, sizeof(model2));
        index+= sizeof(model2);


        coomd=htobe32(coomd);
        memcpy(&*new_string.begin()+index,&coomd, sizeof(coomd));
        index+= sizeof(coomd);
        memcpy(&*new_string.begin()+index,&*data.begin(),data.size());

        std::cout<<new_string.size()<<std::endl;
        return std::move(new_string);

    }
};

namespace Login_model
{
   const short level1=1;  //一级指令

    namespace  to_login
    {
       const short level2=1; //二级指令

       namespace coomd
       {
           const int Login=1;  //三级 登录模块
           const int Register=2;//注册模块

       }
    }
}
namespace role
{
    const short level1=2;
    namespace roleinfo
    {
        const short level2=1;
        namespace coomd
        {
            const int Getrole=1; //获得角色信息
            const int Setrole=2;//修改角色信息

            const int Addrole=3;//增加一个角色


        }


    }

}

#endif //LOGINSERVER_COMMDS_H