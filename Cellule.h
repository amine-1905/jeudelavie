#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
private:
    bool etat; // État actuel de la cellule (vivante ou morte)

public:
    Cellule(bool etat = false);       // Constructeur
    void definirEtat(bool nouvelEtat); // Change l'état de la cellule
    bool obtenirEtat() const;         // Renvoie l'état de la cellule
    bool calculerNouvelEtat(int voisinsVivants) const; // Détermine le nouvel état
};

#endif // CELLULE_H

