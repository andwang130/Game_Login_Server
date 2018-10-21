//
// Created by wj_de on 18-10-8.
//
#include "config.h"
mysqlpp::ConnectionPool * mysqlPool =new MysqlPool(db,ip,user,pswd,port,max_size);

const hero FUWANG(0,"fuwang","xxxxxxx");

const hero NVWANFG(1,"nvwang","xxxxxxx");

const vector<hero> HERO_LIST={FUWANG,NVWANFG};
const map<char *,int> Fight_ip_port={{"127.0.0.1",8081}};