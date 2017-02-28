/**
 * \file string1.c (UTF-8 kódolású fájl)
 *
 * Dinamikus String létrehozása C-ben.
 * A példa a C++ osztály fogalmának megértését készíti elő.
 * Az egységesség kedvéért minden String paramétert pointerrel adtunk át.
 * A kód kihasználja, hogy a c90-es szabványtól a free(NULL) használata legális.
 */

#ifdef _MSC_VER
 /* MSC ne adjon figyelmeztető üzenetet a stringkezelő függvényekre. */
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>              // Kiíratáshoz
#include <stdlib.h>             // malloc miatt
#include <string.h>             // Stringműveletekhez
#include <assert.h>             // hibakezeléshez

/// malloc, new felüldefiniálásával készített memóriaszivárgás és konzisztencia ellenőrző
#include "memtrace.h"           // a standard headerek után kell lennie

#include "string1.h"            /// saját string header

/**
 * Stringet készít egy karakterből
 * Feltételezzük, hogy a String nem létezik még (pData és len inicializálatlan).
 * Ha elfogy a memória, akkor assert error
 * @param s0  - pointer a String-re
 * @param ch - a karakter amiből elkészíti a Stringet
 */
void createString(String &s0, char ch) {
    /// Meghatározzuk a hosszát
    s0.len = 1;
    /// Lefoglalunk a helyet a hossznak + a lezáró nullának
    s0.pData = (char*)malloc(s0.len+1);
    assert(s0.pData != NULL);   // nincs jobb ötletünk a hibajelzésre; (később lesz)
    /// Betesszük a karaktert
    s0.pData[0] = ch;
    s0.pData[1] = '\0';

/// A memóriahibák figyelését tesztelendő csúnyán beleírunk a memóriába
    //s0->pData[-4] = '\0';
}

/**
 * String felszabadítása
 * Ha dinamikus memóriát használunk, gondoskodni kell a lefoglalt terület felszabadításról is.
 * Feltételezzük, hogy csak létező (inicializált) Stringre használjuk.
 * @param s  - pointer a String-re
 */
void disposeString(struct String &s0) {
    free(s0.pData);		// felszabadítjuk
}

#if ELKESZULT >= 1
/// EZ AZ ELSŐ FV., AMIT KI KELL EGÉSZÍTENIE!
/// Ha kiegészítette, állítsa az ELKESZULT azonosító értékét 1-re !  (#define ELKESZULT 1)
/**
 * Stringet készít nullával lezárt karaktersorozatból (C-stringből)
 * Feltételezzük, hogy a String nem létezik még (pData és len inicializálatlan).
 * Ha elfogy a memória, akkor assert error
 * @param s0 - pointer a String-re
 * @param p  - pointer a C stringre (feltételezhetjük, hogy nem NULL)
 */
void createString(struct String &s0, const char *p) {
    // Meghatározzuk a hosszát
    s0.len = strlen(p);
    // Helyet foglalunk
    s0.pData = (char*)malloc(s0.len+1);
    assert(s0.pData != NULL);
    // Bemásoljuk a stringet, ami le van zárva 0-val így használható az strcpy is
    strcpy(s0.pData, p);
}
#endif // ELKESZULT >= 1

#if ELKESZULT >= 2
/// EZ A MÁSODIK FV., AMIT KI KELL EGÉSZÍTENIE!
/// Ha kiegészítette, állítsa az ELKESZULT azonosító értékét 2-re !  (#define ELKESZULT 2)
/**
 * Stringet készít egy Stringből
 * Feltételezzük, hogy a String nem létezik még (pData és len inicializálatlan).
 * Ha elfogy a memória, akkor assert error
 * @param s0  - pointer a String-re
 * @param s1  - pointer a másik Stringre (Feltételezzük, hogy ez létezik!)
 */
void createString(String& s, const String& s1) {
    // Meghatározzuk a hosszát
    s.len = strlen(s1.pData);
    // Helyet foglalunk
    s.pData = (char*)malloc(s.len+1);
    assert(s.pData != NULL);
    // Bemásoljuk a stringet, ami le van zárva 0-val így használható az strcpy is
    strcpy(s.pData, s1.pData);
}
#endif // ELKESZULT >=2


#if ELKESZULT >= 3
/// EZ A HARMADIK FV., AMIT KI KELL EGÉSZÍTENIE!
/// Ha kiegészítette, állítsa az ELKESZULT azonosító értékét 3-ra !  (#define ELKESZULT 3)
/**
 * Két Stringet fűz össze.
 * Az eredményt egy harmadikba (visszatérési érték) írja.
 * Feltételezzük, hogy a paraméterként megadott Stringek léteznek
 * Ha elfogy a memória, akkor assert error
 * @param s0  - pointer az egyik String-re
 * @param s1  - pointer a másik String-re
 * @return új string: A két string összefûzve.
 */
struct String addString(const String &s0, const String &s1) {
    struct String res;		// ide kerül az eredmény
    // Meghatározza az új string hosszát
    res.len = strlen(s0.pData) + strlen(s1.pData);
    // Helyet foglalunk
    res.pData = (char*)malloc(res.len+1);
    assert(res.pData != NULL);
    // Az elejére bemásolja az első stringet
    strcpy(res.pData, s0.pData);
    // Bemásolja a második stringet.
    strcat(res.pData, s1.pData);
    return res;		// visszatér az eredménnyel
}
#endif // ELKESZULT >= 3

#if ELKESZULT >= 4

/**
 * String végéhez karaktert ad.
 * Az eredményt egy harmadikba (visszatérési érték) írja.
 * Feltételezzük, hogy a paraméterként megadott String létezik
 * Ha elfogy a memória, akkor assert error
 * @param s0 - pointer a String-re
 * @param ch - a karakter amit hozzáfűz
 * @return új string
 *
 * Ez a függvény visszavezeti a feladatot a korábbiakra.
 * Ezért ezt elkészítettük, de a megvalósításba ún. memória szivárgás
 * hiba csúszott
 */


struct String addString(const String &s0, char ch){
   struct String res, temp;
    createString(temp, ch);    /// char-ból string
    res = addString(s0, temp);

    free(temp.pData);
    return res;
}

#endif // ELKESZULT >= 4

/**
 * Egy megadott indexű elemmel tér vissza.
 * Feltételezzük, hogy a paraméterként megadott String létezik
 * Hibás index esetén assert error
 * @param s0  - pointer a String-re
 * @param idx - index
 * @return idx indexű karakter
 */
char charAtString(const struct String *s0, unsigned int idx) {
    assert(idx < s0->len);
    return s0->pData[idx];
}

/**
 * Kiírunk egy stringet
 * Feltételezzük, hogy a paraméterként megadott String létezik
 * @param s0  - pointer a String-re
 */
void printString(const struct String *s0) {
    printf("%s", s0->pData);
}

/**
 * Kiírunk egy stringet (debug célokra)
 * Feltételezzük, hogy a paraméterként megadott String létezik
 * @param s0  - pointer a String-re
 */
void printStringDbg(const struct String &s0) {
    printf("[%d], %s|\n", s0.len, s0.pData);
}
