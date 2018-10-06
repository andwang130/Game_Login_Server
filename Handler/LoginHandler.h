//
// Created by wj on 18-10-5.
//

#ifndef LOGINSERVER_LOGINHANDLER_H
#define LOGINSERVER_LOGINHANDLER_H

#include "BaseHandler.h"
class LoginHandler: public BaseHandler
{
public:
LoginHandler(const CoonPrt coonPrt ,protocol_ &aProtocol);
private:
    void login();
    void register_();
};


#endif //LOGINSERVER_LOGINHANDLER_H
