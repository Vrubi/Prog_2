/**
 * \file main.c (UTF-8 kódolású fájl)
 *
 * C nyelven létrehozott String modul kipróbálása.
 * Ha jól valósította meg a modul függvényeit akkor
 * A progam a következő sorokat írja a standard kimenetre:
 * [1], x|
 * [4], alma|
 * a
 * [4], alma|
 * [5], xalma|
 * [8], almaalma|
 * [6], xalmaA|
 */

#include <stdio.h>      /// Kiíratáshoz
/// malloc, new felüldefiniálásával készített memóriaszivárgás és konzisztencia ellenőrző
#include "memtrace.h"

#include "string1.h"     /// String modulunk fejlécállománya

/**
 *  Egyszerű program a függvények kipróbálásához-
 *  A printString próbáját elhagytuk.
 */
int main() {
    /// Stringek deklarációja. Azért statikus, hogy 0 kezdőértéket kapjanak a pointerek
    /// Így a program végén levő dispose nem fog elszállni a létre nem hozott stringekre.
    /// EZ CSAK EGSZERŰSÍTÉS, a továbbiakban nem fogjuk kihasználni.
    static struct String a, b, c, d, e; // Stringek deklarációja
    //
    createStringFromChar(&a, 'x');      // most hozzuk létre az adatát
    printStringDbg(&a);	                /// Ezt kellene látni: [1], x|
    //
#if ELKESZULT >= 1
    createStringFromCstr(&b, "alma");
    printStringDbg(&b);                 /// Ezt kellene látni: [4], alma|
    printf("%c\n", charAtString(&b, 3));/// Ezt kellene látni: a
#endif
    //
#if ELKESZULT >= 2
    createStringFromString(&c, &b);
    printStringDbg(&c);                 /// Ezt kellene látni: [4], alma|
#endif
    //
#if ELKESZULT >= 3
    d = addString2String(&a, &b);       /// Össezfűzzük a két stringet
    printStringDbg(&d);                 /// Ezt kellene látni: [5], xalma|
    e = addString2String(&b, &c);
    printStringDbg(&e);                 /// Ezt kellene látni: [8], almaalma|
#endif
    //
#if ELKESZULT >=4
    disposeString(&e);                  /// e-t másra akarjuk használni, felszabadítjuk
    e = addChar2String(&d, 'A');        /// Ezt kellene látni: [6], xalmaA|
    printStringDbg(&e);
#endif
    //
    disposeString(&e);
    disposeString(&d);
    disposeString(&c);
    disposeString(&b);
    disposeString(&a);
    return 0;
}

