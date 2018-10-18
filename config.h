//
// Created by wj on 18-10-8.
//

#ifndef LOGINSERVER_CONFIG_H
#define LOGINSERVER_CONFIG_H

#include "dbinteface/mysqlpool.h"
#include "base/MDatetime.h"

struct hero
{
    hero(int id,std::string name,std::string describe)
    {

        id_=id;
        name_=name;
        describe_=describe;
    }
    int id_;
    std::string name_;
    std::string describe_;
};
static const int port=3306;
static const char *db="Gamedb";
static const char *ip="127.0.0.1";
static const char *user="root";
static const char *pswd="WANGJING123";
static const int max_size=10;


extern mysqlpp::ConnectionPool * mysqlPool;

extern const hero FUWANG;

extern const hero NVWANFG;

extern const vector<hero> HERO_LIST;


#endif //LOGINSERVER_CONFIG_H