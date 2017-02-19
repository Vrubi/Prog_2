#ifndef NEM_OO_H
#define NEM_OO_H
/**
 * file nem_oo.h (latin2 kodolasu fajl)
 *
 * A C++ nem OO bõvítéseinek gyakorlásához.
 *
 */

#include "memtrace.h"

namespace sajat {	/// saját névtér

/**
 * Saját atoi.
 * Számjegysorozat átalakítása int-re
 * A számjegysorozat végét white space, vagy string vége ('\0') jelzi.
 * Ha a számjegysorozatban olyan számjegy, vagy betû fordul elõ,
 * ami nem érvényes az adott számrendszerben, az hiba.
 * Hiba esetén egy const char* típusú kivételt kell dobni, melynek értéke
 * az neptun azonosítója!
 * @param p    - pointer a stringre
 * @param base - számrendszer alapja (0-10)
 * @return     - base számrendszerben értelmezett szám
 */
int atoi(const char *p, int base = 10);

/**
 * Sajat strcat.
 * Két cstrring összefûzése
 * Dinamikusan foglal helyet
 * @param p1   - pointer az elsõ stringre
 * @param p2   - pointer az másik stringre
 * @return     - dinamikusan foglalt terület címe, ahova az eredmény kerül (hívónak kell felszabadítania)
 */
char *strcat(const char *p1, const char *p2);

/**
 * swap
 * Megcseréli a paramétereit
 * @param r1   - referencia az egyik adatra
 * @param r2   - referencia a másik adatra
 */
void swap(int& r1, int& r2);

/**
 * unique
 * A paraméterként kapott két pointer közötti karaktersorozatból kihagyja az egymás után ismétlõdõ
 * karaktereket (char). A sorozatot az eredeti helyén hagyja!
 * @param first - pointer az adatok kezdetére
 * @param last  - pointer, ami az utolsó adat után mutat
 * @return      - pointer, ami az új sorozat utolsó adata után mutat (a kihagyással rövidült a sorozat)
 */
char *unique(char *first, char *last);

}		/// névtér vége

#endif


