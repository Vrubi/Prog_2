/**
 * \file gen_array_iter3.hpp
 *
 * Generikus t�mb iter�torral v3.
 *  El�ad�son bemutatott k�d m�dos�tott v�ltozata.
 */
#ifndef GEN_ARRAY_ITER3
#define GEN_ARRAY_ITER3

#include <stdexcept>

/**
 * Fix m�ret� generikus t�mb.
 * @param T - t�rolt adatt�pus
 * @param maxsiz - maxim�lis m�ret
 */
template<class T, size_t maxsiz = 6>
class Array {
    size_t siz;				// adatok t�nyleges mennyis�ge
	T t[maxsiz];            // elemek (adatok) t�mbje
public:
    /// minden implicit tagf�ggv�ny j�, nem kell �tdefini�lni
    class iterator;	        // el�deklar�ci�

	/// default �s kontans �rt�kkel felt�lt� konstruktor
	/// @param n - m�ret
	/// @param value - �rt�k, amivel felt�lt
	explicit Array(size_t n = 0, const T& value = T()) : siz(0) {
        while (siz < n && siz < maxsiz)
            t[siz++] = value;
    }

    /// konstruktor sorozatb�l
    /// @param first - sorozat elj�re mutat
    /// @param last - utols� elem ut�n
    template <class InputIterator>
    Array(InputIterator first, InputIterator last) : siz(0) {
		while (first != last && siz < maxsiz)	// �tm�solunk, am�g lehet
			t[siz++] = *first++;
    }

	/// l�trehoz egy iter�tort �s az elej�re �ll�tja
	/// @return - iter�tor az adatsorozat elej�re
    iterator begin() {
        return iterator(*this);		// ld. iter�tor konstruktor
    }

	/// l�trehoz egy iter�tort �s az utols� elem ut�n �ll�tja
	/// @return - iter�tor az adatsorozat v�g�re
    iterator end() {
        return iterator(*this, siz);// ld. iter�tor konstruktor
    }

	/// Elemek t�nyleges sz�ma
	/// @return - t�nylegesen t�rolt elemek sz�ma
	size_t size() const { return siz; }

	/// T�mb maxim�lis kapacit�sa
	/// @return - t�mb maxim�lis kapacit�sa
	size_t capacity() const { return maxsiz; }

	/// at
	/// @param i - index
	/// @return - i. elem referenci�ja, vagy out_of_range hiba
	T& at(size_t i) {
		if (i >= maxsiz) throw std::out_of_range("Array.at(): hibas index");
		if (i >= siz) siz = i+1; // n�velj�k a t�nyleges m�retet
		return t[i];
	}
	/// at konstans v�ltozata.
	/// konstans eset�n nem v�ltozhat a m�ret
	/// @param i - index
	/// @return i. elem referenci�ja, vagy out_of_range hiba
	const T at(size_t i) const {
		if (i >= siz) throw std::out_of_range("Array.at(): hibas index");
		return t[i];
	}

	/// iterator oszt�ly
	/// input/output (STL::ForwardIterator) iter�tork�nt haszn�lhat�
	class iterator {
        Array *p;	// t�roljuk, hogy melyik az objektumhoz tartozik az iter�tor
		size_t idx;	// t�roljuk az aktu�lis index �rt�ket
    public:

        /// default konstruktor
        iterator() :p(0), idx(0) {}

        /// konstuktor, egy konkr�t objektum ix-edik elem�re mutat
        /// @param a - a konkr�t objektum
        /// @param ix - ide �ll�tja az indexet
        iterator(Array& a, size_t ix = 0)
            : p(&a),                // az objektumra mutat
            idx(ix) {}              // erre az elemre �ll

        /// pre-inkremens
        iterator& operator++() {
            if (idx != p->siz) ++idx;   // nem engedj�k t�ll�pni
            return *this;
        }

        /// post-inkremens
        iterator operator++(int){
            iterator tmp=*this;
            if (idx != p->siz) idx++;
            return tmp;
        }

        /// egyenl�tlens�g
        /// @param i - jobboldali operandus
        bool operator!=(const iterator &i) {
            return(idx != i.idx);
        }

        /// egyenl�s�g
        /// @param i - jobboldali operandus
		bool operator==(const iterator &i) {
            return !operator!=(i);
        }

        /// indirekci�
        T& operator*() {
            if (idx != p->siz) return p->t[idx];
            else throw std::runtime_error("Hibas indirekcio");
        }

        /// indirekci� (nyil)
        T* operator->() {
            return &operator*();
        }

    };  // iterator oszt�ly v�ge

	/// Virtu�lis destruktor.
	/// Most nem haszn�ljuk, de egy generikus oszt�ly k�s�bbi
	/// felhaszn�l�si m�dja kev�sb� l�tszik.
	virtual ~Array() {}
}; // generikus t�mb v�ge

#endif
