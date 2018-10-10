//
// Created by wj on 18-10-10.
//

#ifndef LOGINSERVER_MATCHINGHANDLER_H
#define LOGINSERVER_MATCHINGHANDLER_H


#include "BaseHandler.h"

class matchingHandler: BaseHandler {


public:
    matchingHandler(const CoonPrt coonPrt, protocol_ &aProtocol);
private:
    //开始匹配
    void playmatching();
    //匹配完成
    void completion(int fieldID);

    //等待其他玩家进入匹配
    void entering(int fieldID);
    static int index;

};



#endif //LOGINSERVER_MATCHINGHANDLER_H
