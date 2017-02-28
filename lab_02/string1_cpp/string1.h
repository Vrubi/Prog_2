#ifndef STRING1_H
#define STRING1_H

/**
 * \file string1.h (UTF-8 kódolású fájl)
 *
 * Dinamikus String létrehozása C++-ban.
 */

#define ELKESZULT    0  /// értékeit l. alább
/**
 * Az ELKESZULT makró értékét annak megfelelően állítsa
 * 0,1,2,3 vagy 4 értékűre, hogy hol tart a feladat megoldásában!
 * Ha folyamatosan halad, akkor a kód mindig fordítható és futtatható lesz.
 * Így az egyes részek a teljes feladat befejezése nélkül is kipróbálhatók.
 *
 * ELKESZULT lehetséges értékei:
 *   0 - Nem egészített ki egyetlen hiányos függvényt sem.
 *   1 - Elkészítette a createString(String& const char*) függvényt.
 *   2 - Elkészítette a createString(String& const String&) függvényt.
 *   3   ELkészítette az addString(const String&, const String& b) függvényt
 *   4 - Elkészítette az addString(cont String&, chat) függvényt.
 */

/**
 * String struktúra
 * A pData által mutatott dinamikus területen vannak a karakterek (a lezáró nullával együtt).
 * A len mező a tényleges hossz, amibe nem számit bele a lezáró nulla.
 */
struct String {
    char *pData;        /// pointer az adatra
    unsigned int len;   /// hossz lezáró nulla nélkül
};

/**
 * Stringet készít egy karakterből
 * Feltételezzük, hogy a String nem létezik még (pData és len inicializálatlan).
 * Ha elfogy a memória, akkor assert error
 * @param s0  - referencia a String-re
 * @param ch - a karakter amiből elkészíti a Stringet
 */
void createString(String &s0, char ch);

/**
 * String felszabadítása
 * Ha dinamikus memóriát használunk, gondoskodni kell a lefoglalt terület felszabadításról is.
 * Feltételezzük, hogy csak létező (inicializált) Stringre használjuk.
 * @param s  - referencia a String-re
 */
void disposeString(String &s0);

/**
 * Stringet készít nullával lezárt karaktersorozatból (C-stringből)
 * Feltételezzük, hogy a String nem létezik még (pData és len inicializálatlan).
 * @param s0 - referencia a String-re
 * @param p  - pointer a C stringre (feltételezhetjük, hogy nem NULL)
 */
void createString(String &s0, const char *p);

/**
 * Stringet készít egy Stringből
 * Feltételezzük, hogy a String nem létezik még (pData és len inicializálatlan).
 * @param s0  - referencia a String-re
 * @param s1  - referencia a másik Stringre (Feltételezzük, hogy ez létezik!)
 */
void createString(String& s, const String& s1);

/**
 * Két Stringet fûz össze.
 * Az eredményt egy harmadikba (visszatérési érték) írja.
 * Feltételezzük, hogy a paraméterként megadott Stringek léteznek
 * @param s0  - referencia az egyik String-re
 * @param s1  - referencia a másik String-re
 * @return új string: A két string összefûzve.
 */
 String addString(const String &s0, const String& s1);

/**
 * String végéhez karaktert ad.
 * Az eredményt egy harmadikba (visszatérési érték) írja.
 * Feltételezzük, hogy a paraméterként megadott String létezik
 * @param s0 - referencia a String-re
 * @param ch - a karakter amit hozzáfűz
 * @return új string
 */
String addString(const String &s0, char ch);

/**
 * Egy megadott indexű elemmel tér vissza.
 * Feltételezzük, hogy a paraméterként megadott String létezik
 * Hibás index esetén assert error
 * @param s0  - referencia a String-re
 * @param idx - index
 * @return idx indexû karakter
 */
char charAtString(const String &s0, unsigned int idx);

/**
 * Kiírunk egy stringet
 * Feltételezzük, hogy a paraméterként megadott String létezik
 * @param s0  - referencia a String-re
 */
void printString(const String &s0);

/**
 * Kiírunk egy stringet (debug célokra)
 * Feltételezzük, hogy a paraméterként megadott String létezik
 * @param s0  - referencia a String-re
 */
void printStringDbg(const String &s0);

#endif
