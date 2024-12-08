#include "Fichier.h"
#include <fstream>
#include <iostream>

bool Fichier::lireEtatInitial(const std::string& cheminFichier,
    std::vector<std::vector<bool>>& etats,
    int& hauteur, int& largeur) {
    std::ifstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << "\n";
        return false;
    }

    fichier >> hauteur >> largeur;
    if (hauteur <= 0 || largeur <= 0) {
        std::cerr << "Erreur : Dimensions invalides dans le fichier.\n";
        return false;
    }

    etats.resize(hauteur, std::vector<bool>(largeur, false));
    int val;
    for (int i = 0; i < hauteur; ++i) {
        for (int j = 0; j < largeur; ++j) {
            if (!(fichier >> val)) {
                std::cerr << "Erreur : Données insuffisantes dans le fichier.\n";
                return false;
            }
            etats[i][j] = (val == 1);
        }
    }

    fichier.close();
    return true;
}

void Fichier::ecrireEtat(const std::string& cheminFichier,
    const std::vector<std::vector<bool>>& etats) {
    std::ofstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'écrire dans le fichier " << cheminFichier << "\n";
        return;
    }

    int h = (int)etats.size();
    int l = (h > 0) ? (int)etats[0].size() : 0;
    fichier << h << " " << l << "\n";
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < l; ++j) {
            fichier << (etats[i][j] ? 1 : 0) << " ";
        }
        fichier << "\n";
    }

    fichier.close();
}
