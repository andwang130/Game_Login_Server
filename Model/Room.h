//
// Created by wj on 18-10-17.
//

#ifndef LOGINSERVER_ROOM_H
#define LOGINSERVER_ROOM_H

#include <bits/shared_ptr.h>
#include "Play.h"
#include "../commds.h"

typedef std::shared_ptr<Play> play_prt;
class Room
{
public:
    int id;
    std::map<CoonPrt,play_prt> plays_;


};


#endif //LOGINSERVER_ROOM_H
