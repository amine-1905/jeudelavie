#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include "Cellule.h"

class Grille {
private:
    int hauteur;
    int largeur;
    std::vector<std::vector<Cellule>> cellules;

    int compterVoisinsVivants(int x, int y) const;

public:
    Grille(int h = 0, int l = 0);

    int getHauteur() const;
    int getLargeur() const;

    void initialiser(const std::vector<std::vector<bool>>& etats);
    bool estVivante(int x, int y) const;
    void setEtat(int x, int y, bool etat);
    void miseAJour();
    bool estIdentique(const Grille& autre) const;
    void afficherConsole() const;
};

#endif // GRILLE_H

