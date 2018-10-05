//
// Created by wj on 18-10-2.
//

#ifndef NET_CURRENTTHREAD_H
#define NET_CURRENTTHREAD_H
#include <stdint.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
namespace CurrentThread
{
    // internal
    __thread int t_cachedTid = 0;
    __thread char t_tidString[32];
    __thread int t_tidStringLength = 6;
    __thread const char* t_threadName = "unknown";
    pid_t gettid()
    {
        return static_cast<pid_t>(::syscall(SYS_gettid));
    }
    void cacheTid()
    {
        if (t_cachedTid == 0)
        {
            t_cachedTid =gettid();
            t_tidStringLength =snprintf(t_tidString, sizeof t_tidString, "%5d ", t_cachedTid);
        }
    }
    inline int tid()
    {
        if (__builtin_expect(t_cachedTid == 0, 0))
        {
            cacheTid();
        }
        return t_cachedTid;
    }

    inline const char* tidString() // for logging
    {
        return t_tidString;
    }

    inline int tidStringLength() // for logging
    {
        return t_tidStringLength;
    }

    inline const char* name()
    {
        return t_threadName;
    }

    bool isMainThread();

    void sleepUsec(int64_t usec);
}
#endif //NET_CURRENTTHREAD_H
