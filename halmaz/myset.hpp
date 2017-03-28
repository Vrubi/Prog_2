#ifndef MYSET_HPP_INCLUDED
#define MYSET_HPP_INCLUDED
#include<stdbool.h>

template<class T, unsigned int s=10>
class Set{
    T *t;
    int db;
public:
    Set():t(new T[s]),db(0){}
    ~Set(){delete[] t;}
    int size(){return db;}
    bool isElement(T elem){
        for(int i=0;i<db;++i)
            if (t[i]==elem)
                return true;
        return false;
    }
    void insert(T elem){
        if(db==s)
            throw std::out_of_range("");
        if(!isElement(elem))
            t[db++]=elem;

    }
    bool equal(T a,T b){
        if(a==b)
            return true;
    return false;
    }
};

#endif // MYSET_HPP_INCLUDED
