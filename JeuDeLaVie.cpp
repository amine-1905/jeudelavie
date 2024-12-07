#include "JeuDeLaVie.h"
#include <fstream>
#include <iostream>

// Constructeur : initialise la grille en fonction du fichier
JeuDeLaVie::JeuDeLaVie(const std::string& cheminFichier) : grille(0, 0), iterations(0) {
    chargerEtatInitial(cheminFichier);
}

// Méthode pour démarrer la simulation
void JeuDeLaVie::demarrerSimulation() {
    for (int i = 0; i < iterations; ++i) {
        grille.afficher();
        grille.mettreAJour();
    }
}

// Méthode pour charger l'état initial de la grille depuis un fichier
void JeuDeLaVie::chargerEtatInitial(const std::string& cheminFichier) {
    std::ifstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << std::endl;
        return;
    }

    int l, c; // Nombre de lignes et colonnes
    fichier >> l >> c;
    grille = Grille(l, c); // Assurez-vous que Grille a un constructeur qui accepte les dimensions

    // Utilisation de std::vector<int> temporairement pour lire les données
    std::vector<std::vector<int>> etatsTemp(l, std::vector<int>(c));
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            fichier >> etatsTemp[i][j];
        }
    }

    // Convertir les données lues en booléens et initialiser la grille
    std::vector<std::vector<bool>> etats(l, std::vector<bool>(c));
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            etats[i][j] = (etatsTemp[i][j] == 1);
        }
    }
    grille.initialiser(etats); // Initialiser la grille avec les états

    fichier.close();
}

// Méthode pour sauvegarder l'état actuel de la grille dans un fichier
void JeuDeLaVie::sauvegarderEtat(const std::string& cheminFichier) {
    std::ofstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << std::endl;
        return;
    }

    fichier << grille.getLignes() << " " << grille.getColonnes() << std::endl;
    // Accédez aux cellules de la grille et enregistrez leur état
    for (const auto& ligne : grille.getCellules()) {
        for (const auto& cellule : ligne) {
            fichier << (cellule.obtenirEtat() ? 1 : 0) << " ";
        }
        fichier << std::endl;
    }

    fichier.close();
}

