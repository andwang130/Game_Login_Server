//
// Created by wj on 18-10-8.
//

#ifndef LOGINSERVER_CONFIG_H
#define LOGINSERVER_CONFIG_H

#include<dbinteface/mysqlpool.h>
const int port=3306;
const char *db="GmaeUser";
const char *ip="127.0.0.1";
const char *user="root";
const char *pswd="WANGJING130"
const max_size=10;
static MysqlPool mysqlPool=new MysqlPool(db,ip,user,pswd,port,max_size);
#endif //LOGINSERVER_CONFIG_H