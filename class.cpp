/*************************************************************************
	> File Name: class.cpp
	> Author: 
	> Mail: 
	> Created Time: Thursday, June 08, 2017 AM10:09:55 HKT
 ************************************************************************/

#include<iostream>
using namespace std;



#if 1
/**
 *测试内部类
 */
//当作public来用
class Base
{
public:
    //Base() : impl_(new Base::Impl) {}
    void fun() {std::cout << "base::fun" << std::endl;}
public:
    class Impl;
    Impl *impl_;
};
class Base::Impl : public Base
{
};


//当作private来用
class Base1
{
public:
    //Base() {impl_ = new Base::Impl();}
    //Base() : impl_(new Base::Impl) {}
    Base1();
    void fun() {std::cout << "base1::fun" << std::endl;}
private:
    class Impl;
    Impl *impl_; //那么Impl类不能继承自Base1
};
class Base1::Impl
{
};
Base1::Base1()
{
    impl_ = new Base1::Impl;
}
void fun()
{
    //Base1::Impl obj; //‘class Base1::Impl’ is private

    Base1 *ptr1 = new Base1();
    ptr1->fun();

    Base *ptr = new Base();
    ptr->fun();

}
#endif


#if 0
/**
 * 测试类中的枚举
 */
class Base
{
public:
   enum STATE { UNINITIALIZED, STARTING, STARTED, JOINING, STOPPING, STOPPED };
};
void fun()
{
    Base::STATE state;
    state = Base::UNINITIALIZED;
    std::cout << state << std::endl;
}
#endif

    

//g++ -ggdb3 -O0 class.cpp
int main()
{
    fun();
    return 0;
}

