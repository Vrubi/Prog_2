/**
 * \file string2_test.cpp
 *
 * Tesztprogram az String osztály teszteléséhez.
 *
 */

#include <iostream>
#include <sstream>
#include <clocale>
#if defined(WIN32) || defined(_WIN32)
# include <windows.h>
#endif

#include "memtrace.h"     // a standard header-ek után kell lennie
#include "string2.h"
#include "rendez.h"
#include "gtest_lite.h"

using std::cout;
using std::cin;
using std::endl;


int main() {
/**
 *  1. A paraméter nélkül hívható konstruktora üres sztringet hozzon étre!
 */
#if ELKESZULT >= 1
    TEST(Elkeszult1, construct) {
      String ures;
      ures.printDbg("Ures sztring: ");   // debug kiíratás
      SUCCEED() << "Hurra! Van egy sztringem, de nem biztos, hogy ures!" << endl;
    } END
#endif

/**
 *  2. Van olyan tagfüggvénye ( c_str() ), ami C-sztringgel, azaz nullával lezárt
 *     karaktersorozatra mutató pointerel (const char *) tér vissza.
 */
#if ELKESZULT >= 2
    TEST(Elkeszult2, emptyStr) {
      String ures;
      EXPECT_STR_EQ("", ures.c_str()) << "Nem ures sztring jott letre" << endl;
    } END
#endif

/**
 * 3. Van olyan konstruktora, ami karakterből hoz létre sztringet.
 */
#if ELKESZULT >= 3
    TEST(Elkeszult3, fromChr) {
      char ch = 'a';
      String a(ch);
      EXPECT_STR_EQ("a", a.c_str()) << "Karakterbol sztring letrehozasa nem silerult!" << endl;
      String b('a');    // konstansból is megy?
      EXPECT_STR_EQ("a", b.c_str()) << "Karakterbol sztring letrehozasa nem silerult!" << endl;
    } END
#endif

/**
 *  4. Van olyan konstruktora, ami C-sztringből (const char*) hoz létre sztringet.
 */
#if ELKESZULT >= 4
    TEST(Elkeszult4, FromCstr) {
      char *hello = const_cast<char*>("Hello sztring"); // const attribútum eltüntetése erőszakkal
      String a(hello);
      EXPECT_STR_EQ(hello, a.c_str()) << "C-szringbol string letrehozasa nem silerult!" << endl;
      const char *p = hello;
      String b(p);      // konstansból is megy?
      EXPECT_STR_EQ(hello, b.c_str()) << "C-szringbol string letrehozasa nem silerult!" << endl;
    } END
#endif

/**
 *  5. Az osztályból létrehozott objektum legyen átadható értékparaméterként!
 */
#if ELKESZULT >= 5
    TEST(Elkeszult5, ctor) {
      String a("Hello sztring");
      String b = a;
      EXPECT_STR_EQ("Hello sztring", a.c_str()) << "Masolo kontsr. elromlott a forras?" << endl;
      EXPECT_STR_EQ("Hello sztring", b.c_str()) << "Baj van a masolo konstruktorral" << endl;
      const String c = a;
      String d = c;     // konstansból is megy?
      EXPECT_STR_EQ("Hello sztring", d.c_str()) << "Baj van a masolo konstruktorral" << endl;
    } END
#endif

/**
 *  6. Támogassa a többszörös értékadást (b = a = a)!
 */
#if ELKESZULT >= 6
    TEST(Elkeszult6, opAssign) {
      String a("Hello sztring");
      String b("Duma1"), c("Duma2");
      EXPECT_STR_NE(a.c_str(), b.c_str());
      a = a;
      EXPECT_STR_EQ("Hello sztring", a.c_str()) << "Baj van az ertekadassal" << endl;
      c = b = a;
      EXPECT_STR_EQ("Hello sztring", a.c_str()) << "Ertekadasnal elromlott a frorras?" << endl;
      EXPECT_STR_EQ("Hello sztring", b.c_str()) << "Ertekadas nem sikerult!" << endl;
      EXPECT_STR_EQ("Hello sztring", c.c_str()) << "Ertekadas nem sikerult!" << endl;
      const String d("Konst");
      c = d;        // konstansból is megy?
      EXPECT_STR_EQ(d.c_str(), c.c_str()) << "Ertekadas nem sikerult!" << endl;
    } END
#endif

/**
 *  7. Legyenek olyan operátorai (operator+), amivel a sztring végéhez sztringet
 *     és karaktert lehet fűzni!
 */
#if ELKESZULT >= 7
    TEST(Elkeszult7, strPlusStr) {
      String a("Hello ");
      String b("sztring");
      String c;
      c = a + b;
      EXPECT_STR_EQ("Hello sztring", c.c_str()) << "Nem sikerult a + String muvelet!" << endl;
      EXPECT_STR_EQ("Hello ", a.c_str()) << "A + muvelet elrontja a bal oldalt?" << endl;
      EXPECT_STR_EQ("sztring", b.c_str()) << "A + muvelet elrontja a jobb oldalt?" << endl;
      const String a1 = a, b1 = b;
      String c1;
      c1 = a1 + b1;          // konstansból is megy?
      EXPECT_STR_EQ("Hello sztring", c1.c_str()) << "Nem sikerult a + String muvelet!" << endl;
    } END

    TEST(Elkeszult7, strPlusChr) {
      String a("Hello ");
      String b;
      b = a + 'B';
      EXPECT_STR_EQ("Hello B", b.c_str()) << "Nem sikerult a + char muvelet!" << endl;
      EXPECT_STR_EQ("Hello ", a.c_str()) << "A + muvelet elrontja a bal oldalt?" << endl;
      const String a1 = a;
      String b1;
      b1 = a1 + 'B';          // konstansból is megy?
      EXPECT_STR_EQ("Hello B", b1.c_str()) << "Nem sikerult a + char muvelet!" << endl;
      EXPECT_STR_EQ("Hello ", a1.c_str()) << "A + muvelet elrontja a bal oldalt?" << endl;

    } END
#endif

/**
 *  8. Lehessen karakterhez is sztringet fűzni a + operátorral!
 */
#if ELKESZULT >= 8
    TEST(Elkeszult8, chrPlusStr) {
      String a("ello");
      String b;
      char h = 'H';
      b = h + a;
      EXPECT_STR_EQ("Hello", b.c_str()) << "Nem sikerult char + Str muvelet!" << endl;
      EXPECT_STR_EQ("ello", a.c_str()) << "A + muvelet elrontja a jobb oldalt?" << endl;
      String b1;
      b1 = 'H' + a;  // konstanssal is megy?
      EXPECT_STR_EQ("Hello", b.c_str()) << "Nem sikerult char + Str muvelet!" << endl;
    } END
#endif

/**
 *  9. A tárolt a karakterek legyenek elérhetőek a szokásos módon indexeléssel!
 *     Az indexeléssel elért elem legyen használható balértékként is!
 *     A konstans objektumok is legyenek indexelhetők.
 *     Az indexelés operátor hiba esetén dobjon const char * kivételt!
 */
#if ELKESZULT >= 9
    TEST(Elkeszult9, index) {
      String a("Hello 678");
      EXPECT_NO_THROW(a[0]);
      EXPECT_NO_THROW(a[7]);
      EXPECT_NO_THROW(a[8]);
      EXPECT_THROW(a[9], const char *);
      EXPECT_THROW(a[-1], const char *);
      EXPECT_EQ('7', a[7]);
      a[7] = '.';
      EXPECT_EQ('.', a[7]);
    } END
#endif

/**
 * 10. Készítsen olyan << operátort, amivel egy sztring kiírható egy ostream típusú
 *     objektumra!
 */
#if ELKESZULT >= 10
    TEST(Elkeszult10, extract) {
      String a("Hello sztring");
      std::stringstream ss;
      ss << a;
      EXPECT_STR_EQ("Hello sztring", ss.str().c_str());
    } END
#endif

/**
 * 11. Készítsen olyan fűzhető >> operátort, amivel be tud olvasni egy szót egy sztring-be!
 *     A beolvasó működjön úgy, mint a scanf %s, azaz a szó végét white space határolja!
 *     A szó eleji white space karaktereket pedig el kell dobni.
 *    *Megj: az istream wshite space kezelése a flags() tagfüggvénnyel szabályozható
 */
 #if ELKESZULT >= 11
    TEST(Elkeszult11, insert) {
      String a("Hello   sztring \n Lajos12");
      std::stringstream ss;
      ss << a;
      String in1, in2, in3;
      ss >> in1 >> in2;         // füzhetőne kell lenni
      while (ss >> in3);        // csak kicsit gonosz teszt !
      EXPECT_STR_EQ("Hello", in1.c_str());
      EXPECT_STR_EQ("sztring", in2.c_str());
      EXPECT_STR_EQ("Lajos12", in3.c_str());
    } END
#endif

/**
 * 12. Próbálja ki az ékezetes karakterek rendezését is! Ehhez elkészítettünk egy
 *     egyszerű kódrészletet ami qsort() függvényt használ.
 *     Értse meg a rendez.cpp fájlban levő kód működését és futtassa a programot!
 */
#if ELKESZULT == 12
    rendez();
#endif

/**
 * 13. A setlocale függvényhívás beállítja a karakterek és sztringek összehasonlításához
 *     szükséges nyelvi környezetet (LC_COLLATE) próbálja ki! Változott a rendezési
 *     sorrend?
 */
#if ELKESZULT >= 13
    cout << endl;
    /// beállítja az op.rendszer által használt nyelvi környezetet, amit feltételezünk, hogy magyar
    cout << "Nyelvi beallitas: " << setlocale(LC_ALL, "") << endl;

 #if defined(WIN32) || defined(_WIN32)
    /// Windows alatt egyéb varázslatra is szükség van ...
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
 #endif
    rendez();
#endif
    return 0;
}
