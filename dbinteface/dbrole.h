//
// Created by wj on 18-10-9.
//

#ifndef LOGINSERVER_DBROLE_H
#define LOGINSERVER_DBROLE_H

#include "../Model/Role.h"
#include "dbBase.h"
class dbrole: public dbBase {
public:
    Role getrole();
    Role getrole(int userid);
    int addrole(Role role);
private:
};


#endif //LOGINSERVER_DBROLE_H
