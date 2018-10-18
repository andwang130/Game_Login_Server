//
// Created by wj on 18-10-18.
//

#ifndef LOGINSERVER_TALKHANDELR_H
#define LOGINSERVER_TALKHANDELR_H


#include "BaseHandler.h"

const int SEND_TEM=1;
const int SEND_ROOM=2;
class TalkHandler: public BaseHandler
{
public:
    TalkHandler(const CoonPrt coonPrt,protocol_ &aProtocol);
private:
    void send_all();
    void send_room_tem();
    void send_room_all();
    void send_room(int flag);
};


#endif //LOGINSERVER_TALKHANDELR_H
