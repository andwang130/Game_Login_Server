//
// Created by wj_de on 18-10-21.
//

#ifndef LOGINSERVER_TOFIGTHHANDLER_H
#define LOGINSERVER_TOFIGTHHANDLER_H

#include "BaseHandler.h"

class ToFigthHandler: public BaseHandler
{
public:
    ToFigthHandler(const CoonPrt coonPrt, protocol_ &aProtocol);

private:
    void rq_Figth_init();
    void rq_Fight_init_user(int fight_id,std::string &ip, int port,int play_id,std::string &buf);
    void send_fight_inti_user(CoonPrt &coonPrt,std::string &messsage)
};


#endif //LOGINSERVER_TOFIGTHHANDLER_H
