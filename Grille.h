#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include "Cellule.h"

class Grille {
private:
    int lignes;  // Nombre de lignes de la grille
    int colonnes;  // Nombre de colonnes de la grille
    std::vector<std::vector<Cellule>> cellules;  // Matrice de cellules

public:
    // Constructeur : initialise une grille vide avec le nombre de lignes et de colonnes
    Grille(int l, int c);

    // M�thode pour initialiser la grille avec des �tats bool�ens pour chaque cellule
    void initialiser(const std::vector<std::vector<bool>>& etats);

    // M�thode pour afficher l'�tat actuel de la grille
    void afficher() const;

    // M�thode pour mettre � jour la grille selon les r�gles du jeu de la vie
    void mettreAJour();

    // M�thode pour compter le nombre de voisins vivants d'une cellule donn�e
    int compterVoisinsVivants(int x, int y) const;

    // M�thodes pour obtenir les dimensions de la grille
    int getLignes() const;
    int getColonnes() const;

    // M�thode pour obtenir la matrice des cellules (utile pour acc�der � l'�tat de chaque cellule)
    const std::vector<std::vector<Cellule>>& obtenirCellules() const { return cellules; }
};

#endif // GRILLE_H

