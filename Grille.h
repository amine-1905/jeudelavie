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

    // Méthode pour initialiser la grille avec des états booléens pour chaque cellule
    void initialiser(const std::vector<std::vector<bool>>& etats);

    // Méthode pour afficher l'état actuel de la grille
    void afficher() const;

    // Méthode pour mettre à jour la grille selon les règles du jeu de la vie
    void mettreAJour();

    // Méthode pour compter le nombre de voisins vivants d'une cellule donnée
    int compterVoisinsVivants(int x, int y) const;

    // Méthodes pour obtenir les dimensions de la grille
    int getLignes() const;
    int getColonnes() const;

    // Méthode pour obtenir la matrice des cellules (utile pour accéder à l'état de chaque cellule)
    const std::vector<std::vector<Cellule>>& obtenirCellules() const { return cellules; }
};

#endif // GRILLE_H

