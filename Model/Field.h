//
// Created by wj on 18-10-10.
//

#ifndef LOGINSERVER_FIELD_H
#define LOGINSERVER_FIELD_H

#include <iostream>
#include <memory>
#include <map>
#include "../commds.h"
using  namespace std;

class Player
{

public:
    Player(std::string rolename,std::string level,const CoonPrt coonPrt);
    std::string get_rolename();
    int get_level();
    CoonPrt get_coonprt();
private:
    std::string rolename_;
    int level_;
    const CoonPrt coonPrt_;
};
typedef std::shared_ptr<Player> prtPlayer;
class Field {
public:
    void addPlayer(const prtPlayer prt_player);
    void removePlauer(const CoonPrt coonPrt);
private:
    std::map<CoonPrt,prtPlayer> players_;
    bool state;
    int sizemax;

};



typedef std::shared_ptr<Field> prt_field;
#endif //LOGINSERVER_FIELD_H
