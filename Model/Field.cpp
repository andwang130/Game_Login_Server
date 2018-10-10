//
// Created by wj on 18-10-10.
//

#include "Field.h"
void Field::addPlayer(const CoonPrt coonPrt, const prt_Role prt_role)
{
    players_[coonPrt]=prt_role;

}
void Field::setsize(int num)
{
    sizemax=num;
}