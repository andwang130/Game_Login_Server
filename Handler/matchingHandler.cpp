//
// Created by wj on 18-10-10.
//

#include "matchingHandler.h"
matchingHandler::matchingHandler(const CoonPrt coonPrt, protocol_ &aProtocol):BaseHandler(coonPrt,aProtocol)
{
    switch (aProtocol.coomd)
    {
        case matching::matching_::coomd::play:
        {
            playmatching();
        }

    }
}