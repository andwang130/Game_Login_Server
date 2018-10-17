//
// Created by wj on 18-10-17.
//

#include "SelectHero.h"
SelectHero::SelectHero(const CoonPrt coonPrt,protocol_ &aProtocol):BaseHandler(coonPrt,aProtocol)
{


    switch (aProtocol.coomd)
    {
        case selecthore::select::coomd::into:
        {
            into_room();
            break;
        }
        case selecthore::select::coomd::getroom:
        {
            getroom();
            break;
        }
        case selecthore::select::coomd::select:
        {
            select_hero();
            break;
        }
        default:
        {
            break;
        }


    }
}

void SelectHero::cilck_hero()
{

}

void SelectHero::into_room()
{

    std::lock_guard<std::mutex> lk(roleMutex);
    std::lock_guard<std::mutex> fieldlk(mathchingMutex);
    auto ite=Login_role.find(coonPrt_);

    if(ite==Login_role.end())
    {
        return;
    }

    prt_Role prt_role=ite->second;
    prt_role->toroom=true;
    int fieldid=prt_role->Fieldid_;

    auto field_ite=Filedmap.find(fieldid);
    if(field_ite==Filedmap.end())
    {
        return;
    }

    for(auto play_ite:field_ite->second->players_)
    {
        //发送进入消息
    }








}

void SelectHero::select_hero()
{

}

void SelectHero::getroom()
{

}