#ifndef _UNCOPYABLE_H__
#define _UNCOPYABLE_H__

/*
    为了拒绝编译器默认提供的函数，可将相应的成员函数声明为private并且不予实现
    当需要组织一个类对象被拷贝时，可以让这个类继承Uncopybale
    结合单例模式实现
*/

class Uncopyable
{
// 允许对象构造和析构
public:
    Uncopyable() {};
    ~Uncopyable() {};

// 阻止copy和赋值操作
private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};

#endif