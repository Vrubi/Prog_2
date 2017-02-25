#ifndef RESISTOR_H
#define RESISTOR_H

/**
 * Ohmikus ellenállás
 */
class Resistor {
    double R;              	// az ellenállás értéke ohmban
    static double defR;  	// ellenállások alapértelmezett értéke ohmban
                            // ezt a statikus adattagot külön meg kell valósítani
                            // az osztályon kívül.
public:

    /// Kontstruktor.
    /// R alapértelmezett értéket (defR-t) kap
    Resistor();

    /// Kontstruktor.
    /// @param r - ellenállás értéke [ohm]
    Resistor(double r);

    /// Default ellenállásérték beállítása
    /// @param r - ellenállás értéke [ohm]
    static void setDef(double r);

    /// Ellenállás értékének lekérdezése.
    /// @return - ellenállás értéke [ohm]
    double getR() const {
        return R;
    }

    /// Két ellenállás soros kapcsolása.
    /// @param r - ellenállás
    /// @return  - eredõ ellenállás
    Resistor operator+(const Resistor& r) const;

    /// Két ellenállás párhuzamos kapcsolása.
    /// @param r - ellenállás
    /// @return  - eredõ ellenállás
    Resistor operator%(const Resistor& r) const;

};

/// Többszörös: n darab egyforma r ellenállás összege (soros kapcsolása).
/// @param n - darabszám
/// @param r - ellenállás
/// @return  - eredõ ellenállás
Resistor operator*(int n, const Resistor& r);

#endif

