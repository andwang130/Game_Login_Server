//
// Created by wj on 18-10-9.
//

#ifndef LOGINSERVER_ROLE_H
#define LOGINSERVER_ROLE_H

#include <iostream>
using  namespace std;
class Role {
public:
    Role(std::string rolename,int exp,int money,int level,int userid,int roleid);
    Role();
    std::string rolename_;
    int exp_;
    int money_;
    int level_;
    int userid_;
    int roleid_;
    int Fieldid_;
};
#endif //LOGINSERVER_ROLE_H
