/**
 * \file komplex.cpp
 *
 * Komplex osztályt megvalósító függvények definíciója
 *
 * Folytassa a megvalósítást a complex.h fájlban levő
 * feladatoknak megfelelően!
 *
 */

// Valószínű, hogy a kiíráshoz majd kell
#include <iostream>
// ... és ez is.
#include <iomanip>
// Valószínű, hogy az abszolútértékhez majd kell.
#include <cmath>
// Ebben van a Komplex osztály, és néhány globális függvény deklarációja
#include "komplex.h"
//using namespace std;  // ha nagyon kell, akkor csak itt nyissuk ki a névteret

// 0, 1 és 2 paraméteres konstruktor
// Figyelje meg, hogy a default argumentumokat CSAK a deklarációnál
// adtuk meg!
Komplex::Komplex(double r, double im) {
    re = r; // ha nincs névütközés, nem kell kiírni a this-t
    this->im = im;
}

// Előre elkészített tagfüggvények

#if ELKESZULT >= 3
// 3. feladathoz (ELKESZULT 3)
// összehasonlítás
bool Komplex::operator==(const Komplex& rhs_k) const{
    return (this->im==rhs_k.im && this->re == rhs_k.re);
}
/// Egyenlőtlenség vizsgálat
/// @param rhs_k - jobb oldali operandus (Komplex)
/// @return hamis - ha a képzeets és a valós rész is azonos, egyébként false
bool Komplex::operator!=(const Komplex& rhs_k) const {  // visszavezetjük az egyenlőség vizsgálatra
    return !(*this == rhs_k);
}
#endif

Komplex Komplex::operator+(const Komplex& rhs_k) const{
    return Komplex(this->re + rhs_k.re,this->im + rhs_k.im);
}

Komplex Komplex::operator+(double rhs_d) const{
    return Komplex(this->re + rhs_d,this->im);
}

Komplex operator+(double rhs_d,const Komplex& rhs_k){
    return Komplex(rhs_k.getRe() + rhs_d, rhs_k.getIm());
}

#if ELKESZULT >= 5
// 5. feladathoz (ELKESZULT 5)
// a += művelet viszont módosítja önmagát!
/// Komplex + double
/// @param rhs_d - jobb oldali operandus (double)
/// @return eredeti (bal oldali) objektum ref., amihez hozzáadtuk rhd_d-t
Komplex& Komplex::operator+=(double rhs_d) {
    re += rhs_d;
    return *this;
}

Komplex& Komplex::operator+=(const Komplex& rhs_k){
    this->re+=rhs_k.re;
    this->im+=rhs_k.im;
    return *this;
}
#endif

// TODO: A hiányzó tag- és globális függvények itt következnek

