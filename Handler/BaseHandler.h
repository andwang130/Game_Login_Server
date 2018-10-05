//
// Created by wj on 18-10-5.
//

#ifndef LOGINSERVER_BASEHANDLER_H
#define LOGINSERVER_BASEHANDLER_H

#include "../commds.h"
#include "../Net/Tcpcoonetion.h"

class BaseHandler {

public:
    BaseHandler(const CoonPrt coonPrt,protocol &aProtocol);

protected:
    const CoonPrt coonPrt_;
    protocol aProtocol_;
};


#endif //LOGINSERVER_BASEHANDLER_H
