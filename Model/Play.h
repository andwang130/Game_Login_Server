//
// Created by wj on 18-10-17.
//

#ifndef LOGINSERVER_PLAY_H
#define LOGINSERVER_PLAY_H

#include <iostream>
class Play {

public:

    Play();
    std::string name;
    int heroid; //选择的英雄
    bool toroom; //是否进入房间
    int click_hero;//点击的英雄
    int index;//位置
    int Ranks;//队伍
};


#endif //LOGINSERVER_PLAY_H
