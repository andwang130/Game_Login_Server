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
    void into_room();

    void cilck_hero();

    void select_hero();

    void getroom();
};


#endif //LOGINSERVER_SELECTHERO_H
