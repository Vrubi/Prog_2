/*
 * \file integer.h
 */

#ifndef INTEGER_H
#define INTEGER_H


/// Integer oszt�ly.
/// A konverzi�s oper�torok �s a C automatikus konverzi�s szab�lyai
/// miatt �gy haszn�lhat� mint egy int.
class Integer {
    int adat;
public:
    Integer(int i = 0) :adat(i) {}  /// konstruktor �s egyben konverzi�s oper�tor
    operator int&() { return adat; }/// cast
    operator int() const { return adat; } /// const cast
};

#endif // INTEGER_H
