#include <cstring>
#include <cctype>
#include "nem_oo.h"

/**
 * \file nem_oo_teszt.cpp
 * (UTF-8 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * FELADATOK:
 *  1. Ebben a fájlban valósítsa meg a nem_oo.h állományban deklarált függvényeket!
 *
 * Ügyeljen a helyes névtér használatra!
 *   Tipp: Használja a scope operátort, vagy nyisson névteret!
 */

 namespace sajat {
 /**
 * Saját atoi.
 * Számjegyeket tartalmazó karaktersorozat átalakítása int-re.
 * Helyes számjegysorozat végét white space, vagy sztring vége ('\0') jelzi.
 *   Ha a számjegysorozatban olyan számjegy, vagy betű fordul elő,
 *   ami nem érvényes az adott számrendszerben, az hiba.
 *   Pl. hármas számrendszerben nem fordulhat elő a 3-as számjegy, de az A betű sem.
 * Hiba esetén egy const char* típusú kivételt kell dobni, melynek értéke
 * az Ön neptun azonosítója!
 * @param p    - pointer a sztringre
 * @param base - számrendszer alapja (0-10)
 * @return     - base számrendszerben értelmezett szám
 */
 int atoi(const char *p, int base){
    if (p == nullptr || base < 2 || base > 10) {
        throw "DNV8L7";  
    }

    // bool negativ = false;
    // if (*p == '-') { 
    //     negativ = true;
    //     ++p;
    // }

    int eredmeny = 0;
    while (*p != '\0' && !std::isspace(*p)) {  
        if (*p < '0' || *p >= '0' + base) {
            throw "DNV8L7";  
        }

        int szamjegy = *p - '0'; 
        eredmeny = eredmeny * base + szamjegy; 
        ++p;
    }

    // return negativ ? -eredmeny : eredmeny;
    return eredmeny;
}

/**
 * Sajat strcat.
 * Két C stílusú sztring (nullával lezárt karaktersorozat) összefűzése
 * A függvény dinamikusan foglal helyet az eredménynek.
 * @param p1   - pointer az első sztringre
 * @param p2   - pointer az másik sztringre
 * @return     - dinamikusan foglalt terület címe, ahova az eredmény kerül (hívónak kell felszabadítania)
 */
char *strcat(const char *p1, const char *p2){
    int hossz1 = strlen(p1);
    int hossz2 = strlen(p2);
    int hossz = hossz1 + hossz2;

    char *eredmeny = (char*)malloc(sizeof(char) * (hossz + 1));
    if (!eredmeny) return NULL; // Ellenőrizzük a foglalást

    for (int i = 0; i < hossz1; i++) {
        eredmeny[i] = p1[i];
    }

    for (int i = 0; i < hossz2; i++) {
        eredmeny[hossz1 + i] = p2[i];
    }

    eredmeny[hossz] = '\0'; // Lezáró karakter
    return eredmeny;
}

/**
 * unique
 * A paraméterként kapott két pointer közötti karaktersorozatból kihagyja az egymás után ismétlődő
 * karaktereket (char). A sorozatot az eredeti helyén hagyja!
 * @param first - pointer az adatok kezdetére
 * @param last  - pointer, ami az utolsó adat után mutat
 * @return      - pointer, ami az új sorozat utolsó adata után mutat (a kihagyással rövidült a sorozat)
 */
char *unique(char *first, char *last){
    char *uj_vege = first;  
    for (char *p = first + 1; p < last; ++p) {
        if (*p != *uj_vege) {  
            *(++uj_vege) = *p; 
        }
    }
    return uj_vege + 1;
}
}
