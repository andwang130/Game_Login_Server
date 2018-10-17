//
// Created by wj on 18-10-17.
//

#ifndef LOGINSERVER_SELECTHERO_H
#define LOGINSERVER_SELECTHERO_H


#include "BaseHandler.h"

class SelectHero : public BaseHandler
{
public:
    SelectHero(const CoonPrt coonPrt,protocol_ &aProtocol);

private:

    //进入房间
    void into_room();

    //点击一个英雄
    void cilck_hero();

    //选择英雄
    void select_hero();

    //获得房间所有信息
    void getroom(std::map<CoonPrt,play_prt> &playmap,std::string &buf);

    //群发
    void group_message(int model1,int model2,int coomd,std::string &data,std::map<CoonPrt,play_prt> &playmap);

    //群发，不对自己发
    void group_message(int model1,int model2,int coomd,std::string &data,std::map<CoonPrt,play_prt> &playmap,const CoonPrt coonPrt);

    //设置protobuf角色信息
    void  set_role_hore(play_prt &play_prt1,std::string &buf);


};


#endif //LOGINSERVER_SELECTHERO_H
