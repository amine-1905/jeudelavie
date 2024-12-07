#ifndef CELLULE_H
#define CELLULE_H

class Cellule {
private:
    bool etat; // �tat actuel de la cellule (vivante ou morte)

public:
    Cellule(bool etat = false);       // Constructeur
    void definirEtat(bool nouvelEtat); // Change l'�tat de la cellule
    bool obtenirEtat() const;         // Renvoie l'�tat de la cellule
    bool calculerNouvelEtat(int voisinsVivants) const; // D�termine le nouvel �tat
};

#endif // CELLULE_H

