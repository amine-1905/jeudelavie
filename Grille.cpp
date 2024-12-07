#include "Grille.h"
#include <iostream>

// Constructeur : initialise une grille vide avec le nombre de lignes et de colonnes
Grille::Grille(int l, int c) : lignes(l), colonnes(c) {
    cellules.resize(lignes, std::vector<Cellule>(colonnes)); // Remplissage de la grille avec des cellules par défaut
}

// Méthode pour initialiser la grille avec des états booléens pour chaque cellule
void Grille::initialiser(const std::vector<std::vector<bool>>& etats) {
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            cellules[i][j] = Cellule(etats[i][j]); // Remplissage des cellules avec l'état donné (vivant ou mort)
        }
    }
}

// Méthode pour afficher l'état actuel de la grille
void Grille::afficher() const {
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            std::cout << (cellules[i][j].obtenirEtat() ? "1 " : "0 ");
        }
        std::cout << std::endl;
    }
}

// Méthode pour mettre à jour la grille selon les règles du jeu de la vie
void Grille::mettreAJour() {
    std::vector<std::vector<Cellule>> nouvelleGrille = cellules; // Copie de la grille pour effectuer les changements sans affecter l'itération

    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            int voisinsVivants = compterVoisinsVivants(i, j); // Compter les voisins vivants

            if (cellules[i][j].obtenirEtat()) {
                if (voisinsVivants < 2 || voisinsVivants > 3) {
                    nouvelleGrille[i][j].definirEtat(false); // La cellule meurt
                }
            } else {
                if (voisinsVivants == 3) {
                    nouvelleGrille[i][j].definirEtat(true); // La cellule devient vivante
                }
            }
        }
    }

    cellules = nouvelleGrille; // Mise à jour de la grille
}

// Méthode pour compter le nombre de voisins vivants autour d'une cellule donnée
int Grille::compterVoisinsVivants(int x, int y) const {
    int voisinsVivants = 0;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue; // Ignorer la cellule elle-même

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < lignes && ny >= 0 && ny < colonnes) {
                if (cellules[nx][ny].obtenirEtat()) {
                    voisinsVivants++; // Incrémenter le compteur si le voisin est vivant
                }
            }
        }
    }

    return voisinsVivants; // Retourner le nombre de voisins vivants
}

// Méthode pour obtenir le nombre de lignes de la grille
int Grille::getLignes() const {
    return lignes; // Retourne le nombre de lignes de la grille
}

// Méthode pour obtenir le nombre de colonnes de la grille
int Grille::getColonnes() const {
    return colonnes; // Retourne le nombre de colonnes de la grille
}

// Méthode pour obtenir la matrice des cellules
const std::vector<std::vector<Cellule>>& Grille::getCellules() const {
    return cellules; // Retourne la matrice des cellules
}

