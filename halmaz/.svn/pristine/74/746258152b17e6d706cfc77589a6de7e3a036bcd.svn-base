/*
 * \file integer.h
 */

#ifndef INTEGER_H
#define INTEGER_H


/// Integer osztály.
/// A konverziós operátorok és a C automatikus konverziós szabályai
/// miatt úgy használható mint egy int.
class Integer {
    int adat;
public:
    Integer(int i = 0) :adat(i) {}  /// konstruktor és egyben konverziós operátor
    operator int&() { return adat; }/// cast
    operator int() const { return adat; } /// const cast
};

#endif // INTEGER_H
