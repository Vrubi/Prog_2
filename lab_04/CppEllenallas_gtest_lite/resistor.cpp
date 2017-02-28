/**
 * Ohmikus ellenállást megvalósitó osztály megvalósítása
 */
#include "resistor.h"
#include <iostream>
#include <cmath>

//Itt kell megvalósítani a resistor.h-ban deklarált
//nem inline függvényeket.
//A Jportára ezt a fajlt kell feltölteni.

double Resistor::defR=88;

Resistor::Resistor():R(defR){std::cout<<"k";}

Resistor::Resistor(const Resistor& r):R(r.R){std::cout<<"k";} ///COPY CONTRUCTOR

Resistor::Resistor(double r):R(r){std::cout<<"k";}

void Resistor::setDef(double r){defR=r;std::cout<<"k";}

double Resistor::getU(double i) const{
    return this->R * i;
}

double Resistor::getI(double u) const{
    return u/this->R;
}

Resistor Resistor::operator=(const Resistor& r){
    return Resistor(this->R = r.R);
}

Resistor Resistor::operator+(const Resistor& r) const{
    return Resistor(this->R + r.R);
}

Resistor Resistor::operator%(const Resistor& r)const{
    return Resistor(1/(1/this->R + 1/r.R));
}

bool Resistor::operator==(const Resistor& r) const{
    return fabs(this->R - r.R)<0.0000001;
}

bool Resistor::operator!=(const Resistor& r) const{
    return !(this->R == r.R);
}

Resistor operator*(int n, const Resistor& r){
    if (n<=0)
        throw "JEX651";
    double res=0;
    for(int i=1;i<=n;++i)
        res += r.getR();
    return Resistor(res);
}
