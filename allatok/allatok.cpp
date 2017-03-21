#include <iostream>
#include <string>
#include "memtrace.h"

using std::cout;
using std::cin;
using std::endl;

/// mivel még nincs kész a saját String osztályunk
typedef std::string String;

class Allat {
    String nev;
protected:
    enum { tele, ures } bendo;  /// elérhetõ a leszármazottból
public:
    Allat(const char *nev) : nev(nev), bendo(ures) { }
    const String getNev() const { return nev; }
    virtual void jatszik(Allat*& pajtas) = 0; /// tisztán virtuális
    virtual void hangotAd() { cout << nev << ": ";}
    virtual ~Allat() { cout<< "~" << nev << endl; }
};

class Majom : public Allat {
public:
    Majom(const char *knev) : Allat(knev) { }
    void jatszik(Allat*& pajtas) {
        this->hangotAd();
        pajtas->hangotAd();
    }
    void hangotAd() {
        Allat::hangotAd();
        cout << "Mak" << endl;
    }
    ~Majom() { cout << "MakMak "; }
};

class Tigris : public Allat {
public:
    Tigris(const char *knev) : Allat(knev) { }

    /// Pointerre adunk referenciát. így tudjuk módosítani.
    void jatszik(Allat*& pajtas) {
        if (bendo == ures) {
            cout << "Ehes tigris harap: ";
            delete pajtas;
            pajtas = NULL;  /// trükk, így nem kell tudni a fõprogramban,
                            /// melyik obj., szûnt már meg
            bendo = tele;
        } else {
            cout << "Jol lakott tigris jatszik: ";
            pajtas->hangotAd();
        }
    }
    void hangotAd() {
        Allat::hangotAd();
        cout << "HRRR" << endl;
    }
};

class CirkusziTigris : private Tigris {
public:
    CirkusziTigris(const char *knev) : Tigris(knev) { }
    void hangotAd() {
        Allat::hangotAd();
        cout << "Tigris szeret ugralni" << endl;
    }
};

int main() {
  Allat *sirkan = new Tigris("Sir Kan");
  Allat *csita = new Majom("Csita");
  Allat *kingkong = new Majom("King Kong");
  cout << "-= Csita jatszik =-" << endl;
  csita->jatszik(kingkong);
  csita->jatszik(sirkan);
  cout << "-= Sir Kan jatszik =-" << endl;
  sirkan->jatszik(csita);
  sirkan->jatszik(kingkong);
  cout << "-= Attrakcio =-" << endl;
  CirkusziTigris *tigris = new CirkusziTigris("Tigris");
  tigris->hangotAd();
  cout << "-= Itt a vege =-" << endl;
  /// Minden dinamikus területet felszabadítunk.
  /// A már felszabadított objektumok pointereit nulláztuk,
  /// így nincs többszörös felszabadítás.
  delete sirkan;
  delete csita;
  delete kingkong;
  delete tigris;
  return 0;
}
