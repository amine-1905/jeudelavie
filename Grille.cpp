#include "Grille.h"
#include <iostream>

Grille::Grille(int h, int l) : hauteur(h), largeur(l) {
    cellules.resize(hauteur, std::vector<Cellule>(largeur, Cellule(false)));
}

int Grille::getHauteur() const { return hauteur; }
int Grille::getLargeur() const { return largeur; }

void Grille::initialiser(const std::vector<std::vector<bool>>& etats) {
    for (int i = 0; i < hauteur && i < (int)etats.size(); ++i) {
        for (int j = 0; j < largeur && j < (int)etats[i].size(); ++j) {
            cellules[i][j].setVivante(etats[i][j]);
        }
    }
}

bool Grille::estVivante(int x, int y) const {
    if (x < 0 || x >= hauteur || y < 0 || y >= largeur) {
        return false;
    }
    return cellules[x][y].estVivante();
}

void Grille::setEtat(int x, int y, bool etat) {
    if (x >= 0 && x < hauteur && y >= 0 && y < largeur) {
        cellules[x][y].setVivante(etat);
    }
}

int Grille::compterVoisinsVivants(int x, int y) const {
    int voisinsVivants = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) continue;
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < hauteur && ny >= 0 && ny < largeur) {
                if (cellules[nx][ny].estVivante()) {
                    voisinsVivants++;
                }
            }
        }
    }
    return voisinsVivants;
}

void Grille::miseAJour() {
    std::vector<std::vector<Cellule>> nouvelleGrille = cellules;

    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            int voisins = compterVoisinsVivants(i, j);
            bool actuel = cellules[i][j].estVivante();

            if (actuel && (voisins < 2 || voisins > 3)) {
                nouvelleGrille[i][j].setVivante(false);
            }
            else if (!actuel && voisins == 3) {
                nouvelleGrille[i][j].setVivante(true);
            }
        }
    }

    cellules = nouvelleGrille;
}

bool Grille::estIdentique(const Grille& autre) const {
    if (hauteur != autre.hauteur || largeur != autre.largeur) return false;
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            if (cellules[i][j].estVivante() != autre.cellules[i][j].estVivante()) {
                return false;
            }
        }
    }
    return true;
}

void Grille::afficherConsole() const {
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            std::cout << (cellules[i][j].estVivante() ? "1 " : "0 ");
        }
        std::cout << "\n";
    }
}
