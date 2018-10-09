//
// Created by wj on 18-10-9.
//

#ifndef LOGINSERVER_ROLEHANDLER_H
#define LOGINSERVER_ROLEHANDLER_H


#include "BaseHandler.h"
class roleHandler:public BaseHandler
{

public:
    roleHandler(const CoonPrt coonPrt, protocol_ &aProtocol);

private:
    //新增一个角色
    void addrole();
    //修改一个角色
    void setrole();
    //获得角色的信息
    void getrole();

    //登录验证
    prt_User login_ve();


};


#endif //LOGINSERVER_ROLEHANDLER_H
