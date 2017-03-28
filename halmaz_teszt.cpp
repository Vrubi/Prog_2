/*
 * \file halmaz_teszt.cpp
 *
 */

#define TESTLEVEL 3
/**
 * TESTLEVEL == 0 estén az Ön által készített Set sablon létezését teszteli.
 * TESTLEVEL == 1 esetén a Set mûködését teszteli néhány alaptípussal.
 * TESTLEVEL >= 2 esetén a Set sablont a Point osztállyal teszteli.
 * TESZLEVEL >= 3 esetén az Ön által készített equal sablont teszteli
 * TEZSLEVEL == 4 esetén az Ön által készített equal specializációját teszteli
   (Point Y koordinátája nem vesz részt a hasonlításban)
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
    /// Csak azt vizsgálja, hogy a sablon példányosítható-e, keletkeznek-e az elõírt tagfüggvények,
    /// és a keletkezett kód lefordul-e.
    Set<int> int_set;
    hasMember(&Set<int>::insert);    // az hasMember mûködését nem fontos megértenie
    hasMember(&Set<int>::isElement); // csak a példányosításban segít
    hasMember(&Set<int>::size);
    Set<char> char_set;
    hasMember(&Set<char>::insert);
    hasMember(&Set<char>::isElement);
    hasMember(&Set<char>::size);
    }
#endif  // TESTLEVEL == 0

#if TESTLEVEL >= 1
    /// insert és isElement tesztelése int-re
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

    /// kivétel dobás tesztelése int-re
    TEST(int, exception) {
        Set<int, 1> s0;
        EXPECT_NO_THROW(s0.insert(1));
        EXPECT_THROW(s0.insert(2), std::exception);
    } END

    /// insert és isElement tesztelése char-ra
    TEST(char, insert) {
        Set<char> s0;
        s0.insert('a');
        EXPECT_TRUE(s0.isElement('a'));
        EXPECT_FALSE(s0.isElement('b'));
    } END

    /// insert és isElement tesztelése Integer-re
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
