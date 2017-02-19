#ifndef STRING1_H
#define STRING1_H

/**
 * \file string1.h (UTF-8 kódolású fájl)
 *
 * Dinamikus String létrehozása C-ben.
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
 *   1 - Elkészítette a crateStringFromCstr függvényt.
 *   2 - Elkészítette a createStringFromString függvényt is.
 *   3 - Elkészítette a addString2String függvényt is.
 *   4 - Elkészítette a addChar2String függvényt is.
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
 * @param s0  - pointer a String-re
 * @param ch - a karakter amiből elkészíti a Stringet
 */
void createStringFromChar(struct String *s0, char ch);

/**
 * String felszabadítása
 * Ha dinamikus memóriát használunk, gondoskodni kell a lefoglalt terület felszabadításról is.
 * Feltételezzük, hogy csak létező (inicializált) Stringre használjuk.
 * @param s  - pointer a String-re
 */
void disposeString(struct String *s0);

/**
 * Stringet készít nullával lezárt karaktersorozatból (C-stringből)
 * Feltételezzük, hogy a String nem létezik még (pData és len inicializálatlan).
 * Ha elfogy a memória, akkor assert error
 * @param s0 - pointer a String-re
 * @param p  - pointer a C stringre (feltételezhetjük, hogy nem NULL)
 */
void createStringFromCstr(struct String *s0, const char *p);

/**
 * Stringet készít egy Stringből
 * Feltételezzük, hogy a String nem létezik még (pData és len inicializálatlan).
 * Ha elfogy a memória, akkor assert error
 * @param s0  - pointer a String-re
 * @param s1  - pointer a másik Stringre (Feltételezzük, hogy ez létezik!)
 */
void createStringFromString(struct String *s0, const struct String *s1);

/**
 * Két Stringet fûz össze.
 * Az eredményt egy harmadikba (visszatérési érték) írja.
 * Feltételezzük, hogy a paraméterként megadott Stringek léteznek
 * Ha elfogy a memória, akkor assert error
 * @param s0  - pointer az egyik String-re
 * @param s1  - pointer a másik String-re
 * @return új string: A két string összefûzve.
 */
struct String addString2String(const struct String *s0, const struct String *s1);

/**
 * String végéhez karaktert ad.
 * Az eredményt egy harmadikba (visszatérési érték) írja.
 * Feltételezzük, hogy a paraméterként megadott String létezik
 * Ha elfogy a memória, akkor assert error
 * @param s0 - pointer a String-re
 * @param ch - a karakter amit hozzáfűz
 * @return új string
 */
struct String addChar2String(const struct String *s0, char ch);

/**
 * Egy megadott indexű elemmel tér vissza.
 * Feltételezzük, hogy a paraméterként megadott String létezik
 * Hibás index esetén assert error
 * @param s0  - pointer a String-re
 * @param idx - index
 * @return idx indexű karakter
 */
char charAtString(const struct String *s0, unsigned int idx);

/**
 * Kiírunk egy stringet
 * Feltételezzük, hogy a paraméterként megadott String létezik
 * @param s0  - pointer a String-re
 */
void printString(const struct String *s0);

/**
 * Kiírunk egy stringet (debug célokra)
 * Feltételezzük, hogy a paraméterként megadott String létezik
 * @param s0  - pointer a String-re
 */
void printStringDbg(const struct String *s0);

#endif
