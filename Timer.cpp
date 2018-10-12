//
// Created by wj on 18-10-12.
//

#include "Timer.h"
#include <unistd.h>
Timer::Timer(const TimerCallback &cb, itimerspec itimerspec__):
timerCallback_(cb),
itimerspec_(itimerspec__)
{
    timeFd=timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK);
    timerfd_settime(timeFd,0,&itimerspec_,NULL);
}
void Timer::stop()
{
    ::close(timeFd);
}
void Timer::start()
{
    timerCallback_();
}
int Timer::get_fd()
{
    return timeFd;
}