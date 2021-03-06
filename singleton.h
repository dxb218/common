#ifndef _SINGLETON_H__
#define _SINGLETON_H__

#include "common_header.h"
#include "uncopyable.h"

/*
    参考自《linux多线程服务端编程》
    berif:线程安全的singlton的实现(仅限于linux)，利用pthread_once函数保证只生成一个对象

    int pthread_once(pthread_once_t *once_control, void (*init_routine) (void))；
    功能：本函数使用初值为PTHREAD_ONCE_INIT的once_control变量保证init_routine()函数在本进程执行序列中仅执行一次。

*/

template <typename T>
class Singleton:Uncopyable
{
private:
    Singleton();
    ~Singleton();
    static void Init(){m_instance = new T();};

private:
    static T* m_instance;
    static pthread_once_t m_once;

public:
    static T* GetInstance()
    {
        pthread_once(&m_once,Init);
        return m_instance;
    };
};


template <typename T>
pthread_once_t Singleton<T>::m_once = PTHREAD_ONCE_INIT;

template <typename T>
T* Singleton<T>::m_instance = NULL;

#endif