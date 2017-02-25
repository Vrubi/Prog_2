/**
 * Ohmikus ellenállást megvalósitó osztály megvalósítása
 */
#include "resistor.h"

//Itt kell megvalósítani a resistor.h-ban deklarált
//nem inline függvényeket.
//A Jportára ezt a fajlt kell feltölteni.

double Resistor::defR=88;
Resistor::Resistor():R(defR){}
Resistor::Resistor(double r):R(r){}
void Resistor::setDef(double r){defR=r;}

Resistor Resistor::operator+(const Resistor& r) const{
    return Resistor(this->R + r.R);
}

Resistor Resistor::operator%(const Resistor& r)const{
    return Resistor(1/(1/this->R + 1/r.R));
}

Resistor operator*(int n, const Resistor& r){
    if (n<=0)
        throw "JEX651";
    double res=0;
    for(int i=1;i<=n;++i)
        res += r.getR();
    return Resistor(res);
}
