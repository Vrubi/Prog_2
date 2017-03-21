#ifndef STRING_H
#define STRING_H
/**
 * \file string2.h
 *
 * Ez a fájl tartalmazza a
 *   - String osztály deklarációját
 *   - az inline függvényeket. Ha valamit inline-ként akar megvalósítani,
 *     akkor azt ebbe a fájlba írja! Tipikusan a rövid kódokat szokás
 *     inline-két megvalósítani (pl: c_str).
 *     Más függvényeket ill. definíciókat ne írjon a .h fájlba!
 *
 * A C-ben megírt (string1.c) függvények most tagfüggvényekké váltak, és
 *   eltűnt az első paraméterük (s0) (ebből lett a this).
 * A nevük is megváltozott, mert most már az összetartozást, és a
 *   paraméterek típusára való utalást már nem a név hordozza, hanem az osztály.
 * A createString... alakú függvényekből konstruktorok keletkeztek.
 * A disposeString destruktorrá alakult át.
 * Egyes műveletvégző függvényekből pedig operátor függvény lett.
 */

/**
 * Az Ön feladata ebben fájlban deklarálni és a string2.cpp fájlban pedig
 * megvalósítani (definiálni) az osztály egyes függvényeit úgy, hogy az az alábbi
 * követelményeknek eleget tegyen.
 *
 * Ahogyan halad a megvalósítással egyre több tesztesetet kell lefuttatni,
 * ezért az ELKESZULT makró értéket folyamatosan növelje a feladatsorszámoknak
 * megfelelően!
 *
 * Tanulságos a megvalósítás előtt már a megnövelt értékkel is lefordítani
 * a programot, és elemezni a kapott hibajelzést.
 *
 */



/**
 * \section fel Feladat:
 * A tantermi gyakorlatokon, valamint a 2. laborgyakorlaton is foglalkoztunk egy
 * olyan sztring (String) adatszerkezet és a rajta műveleteket végző függvények
 * megtervezésével/implementálásával ami dinamikusan tárol és annyi memóriát foglal
 * amennyi a tároláshoz szükséges.
 *
 * Ezeket és a tanultakat felhasználva a string2.h és a string2.cpp állományokban
 * definiáljon ill. implementáljon egy olyan sztring (String) osztályt C++ nyelven, ami
 * dinamikusan tárol és rendelkezik az alábbi tulajdonságokkal!
 *
 *  1  A paraméter nélkül hívható konstruktora üres sztringet hozzon étre!
 *  2. Van olyan tagfüggvénye ( c_str() ), ami C-sztringgel, azaz nullával lezárt
 *     karaktersorozatra mutató pointerrel (const char *) tér vissza.
 *  3. Van olyan konstruktora, ami karakterből hoz létre sztringet.
 *  4. Van olyan konstruktora, ami C-sztringből (const char*) hoz létre sztringet.
 *  5. Az osztályból létrehozott objektum legyen átadható értékparaméterként!
 *  6. Támogassa a többszörös értékadást (b = a = a)!
 *  7. Legyenek olyan operátorai (operator+), amivel a sztring végéhez sztringet
 *     és karaktert is lehet fűzni!
 *  8. Lehessen karakterhez is sztringet fűzni a + operátorral!
 *  9. A tárolt a karakterek legyenek elérhetőek a szokásos módon indexeléssel!
 *     Az indexeléssel elért elem legyen használható balértékként is!
 *     A konstans objektumok is legyenek indexelhetők.
 *     Az indexelés operátor hiba esetén dobjon const char * kivételt!
 * 10. Készítsen olyan << operátort, amivel egy sztring kiírható egy ostream típusú
 *     objektumra!
 *
 * Szorgalmi feladatok:
 * 11. Készítsen olyan fűzhető >> operátort, amivel be tud olvasni egy szót egy sztring-be!
 *     A beolvasó működjön úgy, mint a scanf %s, azaz a szó végét white space határolja!
 *     A szó eleji white space karaktereket pedig el kell dobni.
 *    *Megj: az istream wshite space kezelése a flags() tagfüggvénnyel szabályozható
 * 12. Próbálja ki az ékezetes karakterek rendezését is! Ehhez elkészítettünk egy
 *     egyszerű kódrészletet ami qsort() függvényt használ.
 *     Értse meg a rendez.cpp fájlban levő kód működését és futtassa a programot!
 * 13. A setlocale függvényhívás beállítja a karakterek és sztringek összehasonlításához
 *     szükséges nyelvi környezetet (LC_COLLATE) próbálja ki! Változott a rendezési
 *     sorrend?
 */

#include <iostream>
/**
 * Header fájlokból megfontoltan kell include-ot használni.
 * Névteret azonban nem célszerű kinyitni, mert annak hatása zavaró lehet
 * ott ahol ez a header include-olva lesz.
 */

#ifndef MEMTRACE
#error "definialja projekt szinten a MEMTARCE makrot!"
#endif // MEMTRACE

/**
 * A String osztály.
 * A 'pData'-ban vannak a karakterek (a lezáró nullával együtt), 'len' a hossza.
 * A hosszba nem számít bele a lezáró nulla.
 */
class String {
    char *pData;         ///< pointer az adatra
    unsigned int len;    ///< hossz lezáró nulla nélkül
public:
/// Kiírunk egy Stringet (debug célokra)
/// Ezt a tagfüggvényt elkészítettük, hogy használja a hibák felderítéséhez.
/// Igény szerint módosítható
/// @param txt - nullával lezárt szövegre mutató pointer.
///              Ezt a szöveget írjuk ki a debug információ előtt.
    void printDbg(const char *txt = "") const {
        std::cout << txt << "[" << len << "], "
                  << (pData ? pData : "(NULL)") << '|' << std::endl;
    }

/// Az első két feladatot előre megoldottuk, de lehet, hogy nem jól.
/// Az üres sztring reprezentációja nem szerencsés, mert így NULL pointerré
/// konvertál a c_str(), ami külön kezelést igényel a későbbiekben.
/// Ezt a teszt program sem fogadja el.
/// Gondolja végig, és változtassa meg!
/// Két lehetőség van:
///     a) nem NULL pointert tárol, hanem ténylegesen üres szringet.
///     b) NULL-t tárol, de a c_str() üres sztringet ad vissza helyette
/// Bármelyik megoldás jó, mert ez az osztály belügye.

#define ELKESZULT 7
    /// Default konstruktor:
    String() :pData(0),len(0) {}

    /// C-stringet ad vissza
    const char* c_str() const {
        if (pData==NULL)
            return "";
        else
            return pData;
    }

    String(const char c);
    ~String();
    String(const char *str);
    String(const String& str);
    String operator=(String str);
    char& operator[](int idx);
    const String operator+(const String str);
};

#endif
