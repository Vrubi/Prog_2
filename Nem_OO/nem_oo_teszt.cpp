/**
 * \file nem_oo_teszt.cpp (latin2 kodolasu fajl)
 *
 * A C++ nem OO bõvítéseinek gyakorlásához.
 *
 * FELADAT:
 *  Valósítsa meg a nem_oo.h állományban deklarált függvényeket!
 *  Ellenõrizze azok mûködését az alábbi tesztprogrammal.
 *
 * Szorgalmi feladat (nem ellenõrzi a jporta):
 *  A tesztprogram egy részletet mutat arra, hogy helyes nyelvi
 *  beállításokkal ékezetes szöveget is össze lehet hasonlítani.
 *
 *  Az ékezetes szöveg kezeléséhez további segítséget itt talál:
 *  http://infocpp.iit.bme.hu/ekezetes
 *
 */
#include <iostream>
#include <cstring>
#include <locale>               /// ékezetek kezeléséhez kell
#if defined(WIN32) || defined(_WIN32)
    #include <windows.h>        /// ez is
#endif

#include "nem_oo.h"

using std::cout;
using std::cin;
using std::endl;

/**
 * Szorgalmi feladathoz.
 * Összehasonlít két nullával lezárt stringet és kiírja az eredményt
 * Az összehasonlító függvényt paraméterként kapja.
 */
typedef int (*cmp_t)(const char *, const char *);
void printOrderOf(const char *s1, const char *s2, cmp_t cmp) {
     char ch = '=';
     int ret = cmp(s1, s2);
     if (ret < 0)
        ch = '<';
     else if (ret > 0)
        ch = '>';
     cout << s1 << " " << ch << " " << s2 << endl;
}

/**
 * Ezt a tesztprogramot futtatja a (C)JPORTA úgy, hogy az _DEBUG nincs beállítva
 */
int main() {
#ifndef CPORTA      /// (C)Jporta-n nem akarjuk ezt a részt futtatni.
      const char *duma1 = "Ádám";
      const char *duma2 = "Béla";

      cout << "Lekerdezzuk a locale pillanatnyi beallitasat: " << setlocale(LC_ALL, NULL) << endl;
      cout << "strcmp: ";
      printOrderOf(duma1, duma2, strcmp);
      cout << "strcoll: ";
      printOrderOf(duma1, duma2, strcoll);

      /// Alapértelmezett környezet beállítása (remélhetõleg latin2).
      /// Ha nem latin2, akkor az ékezetes kiírások nem jól látszanak,
      /// mert ez a fájl latin2 kódolású
      cout << endl << "A beállított környzeti locale: " << setlocale(LC_ALL, "") << endl;
#if defined(WIN32) || defined(_WIN32)
      SetConsoleCP(1250);           /// Windows alatt ez is kell
      SetConsoleOutputCP(1250);
#endif
      cout << "strcmp: ";
      printOrderOf(duma1, duma2, strcmp);
      cout << "strcoll: ";
      printOrderOf(duma1, duma2, strcoll);
#endif // CPORTA

    try {
#ifdef _DEBUG
      cout << "\natoi kipróbálása:" << endl;
#endif // _DEBUG
       cout << sajat::atoi("100") << endl;     /// 10-es számrendszerben: 100
       cout << sajat::atoi("100", 8) << endl;  /// 8-asban: 64
       cout << sajat::atoi("100", 2) << endl;  /// 2-esben: 4

       /// kipróbáljuk az strcat-ot:
#ifdef _DEBUG
      cout << "\nstrcat kipróbálása:" << endl;
#endif // _DEBUG
       char *str = sajat::strcat("Ez egy kurta sor.\n", "Ez meg hosszabb sorocska.\n");
       cout << str;
       delete[] str;                /// Nekünk kell felszabadítani!

       // kipróbáljuk a swap-et
       int a = 1;
       int b = 2;
       sajat::swap(a, b);            /// referenciát vár: nem kell &!
       cout << "a=" << a << " b=" << b << endl; // megcserélte ?

       // kipróbáljuk a unique-ot
       char test[] = "ssszia C+++++ + !";     /// sok ismétlõdõ kar.

       cout << test << endl;
#ifdef _DEBUG
       cout << "\nuniq elõtt\n";
       memtrace::mem_dump(&test, sizeof(test));
#endif // _DEBUG
       char *p = sajat::unique(test, test+strlen(test));
#ifdef _DEBUG
       cout << "\nuniq után p: " << (void*)p << endl;
       memtrace::mem_dump(&test, sizeof(test));
#endif // _DEBUG
       *p = 0;                      /// p az új sorozat végére mutat
       cout << test << endl;;

       /// itt egy nagyobb próba következik a standard inputról
       const int SORHOSSZ = 100;
       int base = 9;				/// ebben a számrendszerben várjuk az elsõ sort
#ifdef _DEBUG
       cout << "Számot várunk (base: " << base << "):";
#endif // _DEBUG
       char buf1[SORHOSSZ];
       while (cin.getline(buf1, SORHOSSZ)) {    /// amíg van adat
          char buf2[SORHOSSZ];
          buf2[0] = 0;
#ifdef _DEBUG
          cout << "Következõ sor: ";
#endif // _DEBUG
          cin.getline(buf2, SORHOSSZ);
          str = sajat::strcat(buf1, buf2);      /// kétsoronként összefûzzük az inputot
          cout << str << endl;                  /// kiírjuk
          delete[] str;                         /// nem kell tovább a string
          int val = sajat::atoi(buf1, base); 	/// átalakítás base rendszerbõl
#ifdef _DEBUG
          cout << "A szám átalakítva: ";
#endif // _DEBUG
          cout << val << endl; 			        /// kiírjuk
          base  = val % 9 + 2;			        /// ebben a számrendszerben várjuk legközelebb
#ifdef _DEBUG
          cout << "Számot várunk (base: " << base << "):";
#endif // _DEBUG
       }
    } catch (const char *p) {
        cout << "const char* kivetel jott: " << p << endl;
    } catch (...) {
        cout << "Baj van: Nem vart kivetel jott" << endl;
    }
    return 0;
}

