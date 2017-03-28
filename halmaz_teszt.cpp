/*
 * \file halmaz_teszt.cpp
 *
 */

#define TESTLEVEL 3
/**
 * TESTLEVEL == 0 est�n az �n �ltal k�sz�tett Set sablon l�tez�s�t teszteli.
 * TESTLEVEL == 1 eset�n a Set m�k�d�s�t teszteli n�h�ny alapt�pussal.
 * TESTLEVEL >= 2 eset�n a Set sablont a Point oszt�llyal teszteli.
 * TESZLEVEL >= 3 eset�n az �n �ltal k�sz�tett equal sablont teszteli
 * TEZSLEVEL == 4 eset�n az �n �ltal k�sz�tett equal specializ�ci�j�t teszteli
   (Point Y koordin�t�ja nem vesz r�szt a hasonl�t�sban)
*/


#include <iostream>
#include <stdexcept>

#include "gtest_lite.h"
#include "integer.h"
#include "point.h"
#include "myset.hpp"


int main() {

#if TESTLEVEL == 0
    {
    /// Csak azt vizsg�lja, hogy a sablon p�ld�nyos�that�-e, keletkeznek-e az el��rt tagf�ggv�nyek,
    /// �s a keletkezett k�d lefordul-e.
    Set<int> int_set;
    hasMember(&Set<int>::insert);    // az hasMember m�k�d�s�t nem fontos meg�rtenie
    hasMember(&Set<int>::isElement); // csak a p�ld�nyos�t�sban seg�t
    hasMember(&Set<int>::size);
    Set<char> char_set;
    hasMember(&Set<char>::insert);
    hasMember(&Set<char>::isElement);
    hasMember(&Set<char>::size);
    }
#endif  // TESTLEVEL == 0

#if TESTLEVEL >= 1
    /// insert �s isElement tesztel�se int-re
    TEST(int, insert) {
        Set<int> s0;
        s0.insert(1);
        s0.insert(2);
        EXPECT_TRUE(s0.isElement(1)) << "== Betettuk, de nincs benne! ==\n";
        EXPECT_TRUE(s0.isElement(2)) << "== Betettuk, de nincs benne! ==\n";
        EXPECT_FALSE(s0.isElement(0)) << "== Nem tettuk be, de benne van! ==\n";
        EXPECT_EQ(2, s0.size()) << "== Nem jo meretet! ***\n";
        s0.insert(1);
        EXPECT_EQ(2, s0.size()) << "== Azonos elem utan nem jo a meretet! ==\n";
    } END

    /// kiv�tel dob�s tesztel�se int-re
    TEST(int, exception) {
        Set<int, 1> s0;
        EXPECT_NO_THROW(s0.insert(1));
        EXPECT_THROW(s0.insert(2), std::exception);
    } END

    /// insert �s isElement tesztel�se char-ra
    TEST(char, insert) {
        Set<char> s0;
        s0.insert('a');
        EXPECT_TRUE(s0.isElement('a'));
        EXPECT_FALSE(s0.isElement('b'));
    } END

    /// insert �s isElement tesztel�se Integer-re
    TEST(Integer, insert) {
        Set<Integer> s0;
        s0.insert(Integer(1));
        EXPECT_TRUE(s0.isElement(Integer(1)));
        EXPECT_FALSE(s0.isElement(Integer(120)));
    } END
#endif // TESTLEVEL > 1

#if TESTLEVEL >= 2
    TEST(Point, insert) {
        Set<Point> s0;
        s0.insert(Point(1));
        EXPECT_TRUE(s0.isElement(Point(1)));
        EXPECT_FALSE(s0.isElement(Point(100)));
    } END
#endif // TESTLEVEL >= 2

#if TESTLEVEL >= 3
    TEST(int, equal) {
        int a = 1, b = 1;
        EXPECT_TRUE(equal(a, b));
        EXPECT_FALSE(equal(a, 2));
    } END
#endif // TESTLEVEL >=3


#if TESTLEVEL == 3
    TEST(Point, equal) {
        Point a, b, c(0,1), d(1,1), e(1,0);
        EXPECT_TRUE(equal(a, b));
        EXPECT_FALSE(equal(a, c));
        EXPECT_FALSE(equal(a, d));
        EXPECT_FALSE(equal(a, e));
    } END
#endif // TESTLEVEL == 3

#if TESTLEVEL == 4
    TEST(Point, Xequal) {
        Point a, b, c(0,1), d(1,1), e(1,0);
        EXPECT_TRUE(equal(a, b));
        EXPECT_TRUE(equal(a, c));
        EXPECT_FALSE(equal(a, d));
        EXPECT_FALSE(equal(a, e));
    } END
#endif // TESTLEVEL == 4

    return 0;
}
