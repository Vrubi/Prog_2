#ifndef SABLONOK_HPP_INCLUDED
#define SABLONOK_HPP_INCLUDED
#include <iostream>
using namespace std;

template <typename T>
void printEach(T eleje, T vege, ostream &os=cout, const char& sep=", ") {
    while (eleje != vege)
        os << *eleje++ << sep;
}

#endif // SABLONOK_HPP_INCLUDED
