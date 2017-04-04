/**
 * \file gen_array_iter3.hpp
 *
 * Generikus tömb iterátorral v3.
 *  Elõadáson bemutatott kód módosított változata.
 */
#ifndef GEN_ARRAY_ITER3
#define GEN_ARRAY_ITER3

#include <stdexcept>

/**
 * Fix méretû generikus tömb.
 * @param T - tárolt adattípus
 * @param maxsiz - maximális méret
 */
template<class T, size_t maxsiz = 6>
class Array {
    size_t siz;				// adatok tényleges mennyisége
	T t[maxsiz];            // elemek (adatok) tömbje
public:
    /// minden implicit tagfüggvény jó, nem kell átdefiniálni
    class iterator;	        // elõdeklaráció

	/// default és kontans értékkel feltöltõ konstruktor
	/// @param n - méret
	/// @param value - érték, amivel feltölt
	explicit Array(size_t n = 0, const T& value = T()) : siz(0) {
        while (siz < n && siz < maxsiz)
            t[siz++] = value;
    }

    /// konstruktor sorozatból
    /// @param first - sorozat eljére mutat
    /// @param last - utolsó elem után
    template <class InputIterator>
    Array(InputIterator first, InputIterator last) : siz(0) {
		while (first != last && siz < maxsiz)	// átmásolunk, amíg lehet
			t[siz++] = *first++;
    }

	/// létrehoz egy iterátort és az elejére állítja
	/// @return - iterátor az adatsorozat elejére
    iterator begin() {
        return iterator(*this);		// ld. iterátor konstruktor
    }

	/// létrehoz egy iterátort és az utolsó elem után állítja
	/// @return - iterátor az adatsorozat végére
    iterator end() {
        return iterator(*this, siz);// ld. iterátor konstruktor
    }

	/// Elemek tényleges száma
	/// @return - ténylegesen tárolt elemek száma
	size_t size() const { return siz; }

	/// Tömb maximális kapacitása
	/// @return - tömb maximális kapacitása
	size_t capacity() const { return maxsiz; }

	/// at
	/// @param i - index
	/// @return - i. elem referenciája, vagy out_of_range hiba
	T& at(size_t i) {
		if (i >= maxsiz) throw std::out_of_range("Array.at(): hibas index");
		if (i >= siz) siz = i+1; // növeljük a tényleges méretet
		return t[i];
	}
	/// at konstans változata.
	/// konstans esetén nem változhat a méret
	/// @param i - index
	/// @return i. elem referenciája, vagy out_of_range hiba
	const T at(size_t i) const {
		if (i >= siz) throw std::out_of_range("Array.at(): hibas index");
		return t[i];
	}

	/// iterator osztály
	/// input/output (STL::ForwardIterator) iterátorként használható
	class iterator {
        Array *p;	// tároljuk, hogy melyik az objektumhoz tartozik az iterátor
		size_t idx;	// tároljuk az aktuális index értéket
    public:

        /// default konstruktor
        iterator() :p(0), idx(0) {}

        /// konstuktor, egy konkrét objektum ix-edik elemére mutat
        /// @param a - a konkrét objektum
        /// @param ix - ide állítja az indexet
        iterator(Array& a, size_t ix = 0)
            : p(&a),                // az objektumra mutat
            idx(ix) {}              // erre az elemre áll

        /// pre-inkremens
        iterator& operator++() {
            if (idx != p->siz) ++idx;   // nem engedjük túllépni
            return *this;
        }

        /// post-inkremens
        iterator operator++(int){
            iterator tmp=*this;
            if (idx != p->siz) idx++;
            return tmp;
        }

        /// egyenlõtlenség
        /// @param i - jobboldali operandus
        bool operator!=(const iterator &i) {
            return(idx != i.idx);
        }

        /// egyenlõség
        /// @param i - jobboldali operandus
		bool operator==(const iterator &i) {
            return !operator!=(i);
        }

        /// indirekció
        T& operator*() {
            if (idx != p->siz) return p->t[idx];
            else throw std::runtime_error("Hibas indirekcio");
        }

        /// indirekció (nyil)
        T* operator->() {
            return &operator*();
        }

    };  // iterator osztály vége

	/// Virtuális destruktor.
	/// Most nem használjuk, de egy generikus osztály késõbbi
	/// felhasználási módja kevésbé látszik.
	virtual ~Array() {}
}; // generikus tömb vége

#endif
