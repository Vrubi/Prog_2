/**
 * \file nem_oo_teszt.cpp (latin2 kodolasu fajl)
 *
 * A C++ nem OO b�v�t�seinek gyakorl�s�hoz.
 *
 * FELADAT:
 *  Val�s�tsa meg a nem_oo.h �llom�nyban deklar�lt f�ggv�nyeket!
 *  Ellen�rizze azok m�k�d�s�t az al�bbi tesztprogrammal.
 *
 * Szorgalmi feladat (nem ellen�rzi a jporta):
 *  A tesztprogram egy r�szletet mutat arra, hogy helyes nyelvi
 *  be�ll�t�sokkal �kezetes sz�veget is �ssze lehet hasonl�tani.
 *
 *  Az �kezetes sz�veg kezel�s�hez tov�bbi seg�ts�get itt tal�l:
 *  http://infocpp.iit.bme.hu/ekezetes
 *
 */
#include <iostream>
#include <cstring>
#include <locale>               /// �kezetek kezel�s�hez kell
#if defined(WIN32) || defined(_WIN32)
    #include <windows.h>        /// ez is
#endif

#include "nem_oo.h"

using std::cout;
using std::cin;
using std::endl;

/**
 * Szorgalmi feladathoz.
 * �sszehasonl�t k�t null�val lez�rt stringet �s ki�rja az eredm�nyt
 * Az �sszehasonl�t� f�ggv�nyt param�terk�nt kapja.
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
 * Ezt a tesztprogramot futtatja a (C)JPORTA �gy, hogy az _DEBUG nincs be�ll�tva
 */
int main() {
#ifndef CPORTA      /// (C)Jporta-n nem akarjuk ezt a r�szt futtatni.
      const char *duma1 = "�d�m";
      const char *duma2 = "B�la";

      cout << "Lekerdezzuk a locale pillanatnyi beallitasat: " << setlocale(LC_ALL, NULL) << endl;
      cout << "strcmp: ";
      printOrderOf(duma1, duma2, strcmp);
      cout << "strcoll: ";
      printOrderOf(duma1, duma2, strcoll);

      /// Alap�rtelmezett k�rnyezet be�ll�t�sa (rem�lhet�leg latin2).
      /// Ha nem latin2, akkor az �kezetes ki�r�sok nem j�l l�tszanak,
      /// mert ez a f�jl latin2 k�dol�s�
      cout << endl << "A be�ll�tott k�rnyzeti locale: " << setlocale(LC_ALL, "") << endl;
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
      cout << "\natoi kipr�b�l�sa:" << endl;
#endif // _DEBUG
       cout << sajat::atoi("100") << endl;     /// 10-es sz�mrendszerben: 100
       cout << sajat::atoi("100", 8) << endl;  /// 8-asban: 64
       cout << sajat::atoi("100", 2) << endl;  /// 2-esben: 4

       /// kipr�b�ljuk az strcat-ot:
#ifdef _DEBUG
      cout << "\nstrcat kipr�b�l�sa:" << endl;
#endif // _DEBUG
       char *str = sajat::strcat("Ez egy kurta sor.\n", "Ez meg hosszabb sorocska.\n");
       cout << str;
       delete[] str;                /// Nek�nk kell felszabad�tani!

       // kipr�b�ljuk a swap-et
       int a = 1;
       int b = 2;
       sajat::swap(a, b);            /// referenci�t v�r: nem kell &!
       cout << "a=" << a << " b=" << b << endl; // megcser�lte ?

       // kipr�b�ljuk a unique-ot
       char test[] = "ssszia C+++++ + !";     /// sok ism�tl�d� kar.

       cout << test << endl;
#ifdef _DEBUG
       cout << "\nuniq el�tt\n";
       memtrace::mem_dump(&test, sizeof(test));
#endif // _DEBUG
       char *p = sajat::unique(test, test+strlen(test));
#ifdef _DEBUG
       cout << "\nuniq ut�n p: " << (void*)p << endl;
       memtrace::mem_dump(&test, sizeof(test));
#endif // _DEBUG
       *p = 0;                      /// p az �j sorozat v�g�re mutat
       cout << test << endl;;

       /// itt egy nagyobb pr�ba k�vetkezik a standard inputr�l
       const int SORHOSSZ = 100;
       int base = 9;				/// ebben a sz�mrendszerben v�rjuk az els� sort
#ifdef _DEBUG
       cout << "Sz�mot v�runk (base: " << base << "):";
#endif // _DEBUG
       char buf1[SORHOSSZ];
       while (cin.getline(buf1, SORHOSSZ)) {    /// am�g van adat
          char buf2[SORHOSSZ];
          buf2[0] = 0;
#ifdef _DEBUG
          cout << "K�vetkez� sor: ";
#endif // _DEBUG
          cin.getline(buf2, SORHOSSZ);
          str = sajat::strcat(buf1, buf2);      /// k�tsoronk�nt �sszef�zz�k az inputot
          cout << str << endl;                  /// ki�rjuk
          delete[] str;                         /// nem kell tov�bb a string
          int val = sajat::atoi(buf1, base); 	/// �talak�t�s base rendszerb�l
#ifdef _DEBUG
          cout << "A sz�m �talak�tva: ";
#endif // _DEBUG
          cout << val << endl; 			        /// ki�rjuk
          base  = val % 9 + 2;			        /// ebben a sz�mrendszerben v�rjuk legk�zelebb
#ifdef _DEBUG
          cout << "Sz�mot v�runk (base: " << base << "):";
#endif // _DEBUG
       }
    } catch (const char *p) {
        cout << "const char* kivetel jott: " << p << endl;
    } catch (...) {
        cout << "Baj van: Nem vart kivetel jott" << endl;
    }
    return 0;
}

