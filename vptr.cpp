/*************************************************************************
	> File Name: vptr.cpp
	> Author: 
	> Mail: 
	> Created Time: Tuesday, March 14, 2017 PM04:20:08 HKT
 ************************************************************************/

#include<iostream>
using namespace std;


class Base 
{
public:
    Base(int num) : mNum(num) {}
    void print();
    virtual void printVptr();
    virtual void printVptr2();
protected:
    int mNum;
};
void Base::print()
{
    cout << "Base::print " << mNum << endl;
}
void Base::printVptr()
{
    cout << "virtual Base::print " << mNum << endl;
}
void Base::printVptr2()
{
    cout << "virtual Base::print2 " << mNum << endl;
}


// ---------------------------------------- child 
class Child : public Base
{
public:
    Child(int num) : Base(num) {}
    virtual void printVptr();
    virtual void printVptr2();
};
void Child::printVptr()
{
    cout << "virtual Child::print " << mNum << endl;
}
void Child::printVptr2()
{
    cout << "virtual Child::print2 " << mNum << endl;
}

int main()
{
    Base b(33);
    Child c(55);
    Base *ptrB = &c;

    typedef void(*func)(void);
    //*((func*)(*(int*)(&c)))();
    //((func)*((long*)*(long*)(&c)))();
    //((func)*((long*)(*(long*)(&c)+0)))();
    //((func)*((long*)(*(long*)(&c)+1)))();
    //((func)*((int*)(*(int*)(&c)+0)))();
    //((func)*((int*)(*(int*)(&c)+1)))();
    
    cout << sizeof(void*) << sizeof(long) << endl; 
    //ptrB->printVptr();
    //ptrB->Base::printVptr();
    //cout << "size int " << sizeof(int) << endl;
    //cout << "size Base Child " << sizeof(Base) << " " << sizeof(Child) << endl;
    return 0;
}

