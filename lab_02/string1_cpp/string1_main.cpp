/**
 * \file string1_main.cpp (UTF-8 kódolású fájl)
 *
 * C++ nyelvre átírt dinamikus String működését teszteli.
 * Ha jól oldotta meg a feladatot, akkor a program a következő
 * sorokat írja a standard kimenetre:
 * [1], x|
 * [4], alma|
 * [4], alma|
 * [5], xalma|
 * [8], almaalma|
 * [6], xalmaA|
 *
 */

#ifdef _MSC_VER
/// MSC ne adjon figyelmeztető üzenetet a stringkezelő függvényekre.
  #define _CRT_SECURE_NO_WARNINGS
#endif

/**
 *
 * A példa a dinamikus memória használatánál előforduló hibákat
 * a labor útmutatóban ismertetett memtrace módszerrel ellenőrzi.
 *
 * Az ellenőrzés aktivizálásához minden fájl elején definiálni kell
 * a MEMTRACE makrót. Ezt célszerű fordítási opcióként megadni.
 * (ld. a labor útmotatójában)
 */

#include <cstring>          /// Stringműveletekhez

/// malloc, new felüldefiniálásával készített memóriaszivárgás és konzisztencia ellenőrző
#include "memtrace.h"       /// a standard headerek után kell lennie

#include "string1.h"


/**
 *  A C változathoz hasonló program a függvények kipróbálásához
 *  A charAtString és a printString próbáját elhagytuk.
 */
int main() {
    static String a,b,c,d,e;/// statikus trükk. Most utoljára élünk ezzel a trükkel.

    createString(a, 'x');               // most hozzuk létre az adatát
    printStringDbg(a);	                /// Ezt kellene látni: [1], x|
#if ELKESZULT == 0
    /// A következő két sorban bemutatjuk, hogy hogyan lehet egy
    /// memória terület tartalmét kiíratni a mem_dump segíségével.
    printf("\nEz csak egy pelda, hogy hogyan irathato ki a memoria tartalma\n");
    printf("Nezze meg ezt a tartalmat a debugger segitsegevel is!\n\n");
    memtrace::mem_dump(&a, sizeof(a));  /// kiírja a struktúrát
    memtrace::mem_dump(a.pData,a.len+1);/// kiírjuk az adatterület
    printf("\nTegyen torespontot ide, es a debugger segitsegevel irassa ki a tartalmat!\n");

#endif
    //
#if ELKESZULT >= 1
    createString(b, "alma");            /// b-be alma-t teszünk
    printStringDbg(b);                  /// Ezt kellene látni: [4], alma|
#endif
    //
#if ELKESZULT >= 2
    createString(c, b);                 /// b String-ből c
    printStringDbg(c);                  /// Ezt kellene látni: [4], alma|
#endif
    //
#if ELKESZULT >= 3
    d = addString(a, b);                /// Összefűzzük a két stringet
    printStringDbg(d);                  /// Ezt kellene látni: [5], xalma|
    e = addString(b, c);
    printStringDbg(e);                  /// Ezt kellene látni: [8], almaalma|
#endif
    //
#if ELKESZULT >=4
    disposeString(e);                   /// e-t másra akarjuk használni, felszabadítjuk
    e = addString(d, 'A');              /// Ezt kellene látni: [6], xalmaA|
    printStringDbg(e);
#endif
    //
    disposeString(e);
    disposeString(d);
    disposeString(c);
    disposeString(b);
    disposeString(a);
    return 0;
}

