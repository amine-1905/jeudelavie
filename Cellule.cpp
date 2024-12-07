#include "Cellule.h"

Cellule::Cellule(bool etat) : etat(etat) {}

void Cellule::definirEtat(bool nouvelEtat) {
    etat = nouvelEtat;
}

bool Cellule::obtenirEtat() const {
    return etat;
}

bool Cellule::calculerNouvelEtat(int voisinsVivants) const {
    if (etat) {
        return (voisinsVivants == 2 || voisinsVivants == 3);
    } else {
        return (voisinsVivants == 3);
    }
}

