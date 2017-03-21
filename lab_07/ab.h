#ifndef AB_H_INCLUDED
#define AB_H_INCLUDED
#include <iostream>
using namespace std;

class A{
    int i_adat;
public:
    A(int i=0):i_adat(i){cout<<"\tA ctor i_adat="<<A::i_adat<<endl;}
    virtual ~A(){cout<<"\tA dtor i_adat="<<A::i_adat<<endl;}
//    A(const A&);
};

class B: public A{
    float f_adat;
public:
    B(int i=0,float f=0):A(i),f_adat(f){cout<<"\tB ctor f_adat="<<B::f_adat<<endl;}
    ~B(){cout<<"\tB dtor f_adat="<<B::f_adat<<endl;}
//    B(const B&);
};

//class C{
//public:
//    C(){cout<<"\tC ctor\n"<<endl;}
//    ~C(){cout<<"\tC dtor\n"<<endl;}
//};

#endif // AB_H_INCLUDED
