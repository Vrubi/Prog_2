#ifndef NEM_OO_H
#define NEM_OO_H
/**
 * file nem_oo.h (latin2 kodolasu fajl)
 *
 * A C++ nem OO b�v�t�seinek gyakorl�s�hoz.
 *
 */

#include "memtrace.h"

namespace sajat {	/// saj�t n�vt�r

/**
 * Saj�t atoi.
 * Sz�mjegysorozat �talak�t�sa int-re
 * A sz�mjegysorozat v�g�t white space, vagy string v�ge ('\0') jelzi.
 * Ha a sz�mjegysorozatban olyan sz�mjegy, vagy bet� fordul el�,
 * ami nem �rv�nyes az adott sz�mrendszerben, az hiba.
 * Hiba eset�n egy const char* t�pus� kiv�telt kell dobni, melynek �rt�ke
 * az neptun azonos�t�ja!
 * @param p    - pointer a stringre
 * @param base - sz�mrendszer alapja (0-10)
 * @return     - base sz�mrendszerben �rtelmezett sz�m
 */
int atoi(const char *p, int base = 10);

/**
 * Sajat strcat.
 * K�t cstrring �sszef�z�se
 * Dinamikusan foglal helyet
 * @param p1   - pointer az els� stringre
 * @param p2   - pointer az m�sik stringre
 * @return     - dinamikusan foglalt ter�let c�me, ahova az eredm�ny ker�l (h�v�nak kell felszabad�tania)
 */
char *strcat(const char *p1, const char *p2);

/**
 * swap
 * Megcser�li a param�tereit
 * @param r1   - referencia az egyik adatra
 * @param r2   - referencia a m�sik adatra
 */
void swap(int& r1, int& r2);

/**
 * unique
 * A param�terk�nt kapott k�t pointer k�z�tti karaktersorozatb�l kihagyja az egym�s ut�n ism�tl�d�
 * karaktereket (char). A sorozatot az eredeti hely�n hagyja!
 * @param first - pointer az adatok kezdet�re
 * @param last  - pointer, ami az utols� adat ut�n mutat
 * @return      - pointer, ami az �j sorozat utols� adata ut�n mutat (a kihagy�ssal r�vid�lt a sorozat)
 */
char *unique(char *first, char *last);

}		/// n�vt�r v�ge

#endif


