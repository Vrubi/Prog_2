#include "nem_oo.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace sajat{
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
    int atoi(const char *p, int base){
        const char *neptun = "";
        int res = 0;
        int i=0;

        while (p[i] != ' ' && p[i] != '\0'){
            if (!(isdigit(p[i])) ||  ((p[i]- '0') >= base)) {
                throw neptun;
                return(0);
            }
            res *= base;
            res += p[i] - '0';
            i++;
        }
        return res;
    }



    /**
     * Sajat strcat.
     * Két cstrring összefûzése
     * Dinamikusan foglal helyet
     * @param p1   - pointer az elsõ stringre
     * @param p2   - pointer az másik stringre
     * @return     - dinamikusan foglalt terület címe, ahova az eredmény kerül (hívónak kell felszabadítania)
     */
    char *strcat(const char *p1, const char *p2){
     char* res=NULL;
     res=new char[strlen(p1)+strlen(p2)+10];
     strcpy(res, p1);
     std::strcat(res, p2);
     return res;
    }


    /**
     * swap
     * Megcseréli a paramétereit
     * @param r1   - referencia az egyik adatra
     * @param r2   - referencia a másik adatra
     */
    void swap(int& r1, int& r2){
    int tmp = r1;
    r1 = r2;
    r2 = tmp;
    }


    /**
     * unique
     * A paraméterként kapott két pointer közötti karaktersorozatból kihagyja az egymás után ismétlõdõ
     * karaktereket (char). A sorozatot az eredeti helyén hagyja!
     * @param first - pointer az adatok kezdetére
     * @param last  - pointer, ami az utolsó adat után mutat
     * @return      - pointer, ami az új sorozat utolsó adata után mutat (a kihagyással rövidült a sorozat)
     */
    char* unique(char *first, char *last){
        char* k = first+1;
        char *i = first+1;
        while(i!=last){
            if(*i==*(i-1)){
                i++;
            }else{
                *k=*i;
                k++;
                i++;
            }
        }
        *(k)='\0';
        return k;
    }
}
