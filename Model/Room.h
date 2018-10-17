//
// Created by wj on 18-10-17.
//

#ifndef LOGINSERVER_ROOM_H
#define LOGINSERVER_ROOM_H

#include "Play.h"
#include "../commds.h"
#include "../base/timeQueue/TimeQueue.h"
typedef std::shared_ptr<Play> play_prt;
typedef std::shared_ptr<Timer> timer_prt;
class Room
{
public:
    std::map<CoonPrt,play_prt> plays_;
    int ready_num;
    timer_prt  room_timer;

};


#endif //LOGINSERVER_ROOM_H
