#include "Fichier.h"
#include <fstream>
#include <iostream>
#include <vector>
#include "Grille.h"

// Fonction pour lire l'état initial de la grille depuis un fichier
std::vector<std::vector<bool>> Fichier::lireEtatInitial(const std::string& cheminFichier) {
    std::ifstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << std::endl;
        exit(1); // Terminer l'exécution si le fichier ne peut pas être ouvert
    }

    int lignes, colonnes;
    fichier >> lignes >> colonnes; // Lire les dimensions de la grille

    // Utilisation de std::vector<int> pour lire les données d'état des cellules
    std::vector<std::vector<int>> etatsTemp(lignes, std::vector<int>(colonnes));

    // Lire les états des cellules du fichier
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            fichier >> etatsTemp[i][j]; // Lire l'état de chaque cellule (0 ou 1)
        }
    }

    // Convertir les états en booléens (1 devient true, 0 devient false) et retourner
    std::vector<std::vector<bool>> etats(lignes, std::vector<bool>(colonnes));
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            etats[i][j] = (etatsTemp[i][j] == 1); // Convertir 1 en true (vivant), 0 en false (mort)
        }
    }

    fichier.close(); // Fermer le fichier après la lecture
    return etats; // Retourner le vecteur d'états sous forme de booléens
}

// Fonction pour sauvegarder l'état actuel de la grille dans un fichier
void Fichier::ecrireEtat(const std::string& cheminFichier, const Grille& grille) {
    std::ofstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << cheminFichier << " pour écrire." << std::endl;
        exit(1); // Terminer l'exécution si le fichier ne peut pas être ouvert
    }

    // Sauvegarder les dimensions de la grille
    fichier << grille.getLignes() << " " << grille.getColonnes() << std::endl;

    // Sauvegarder l'état des cellules de la grille
    for (int i = 0; i < grille.getLignes(); ++i) {
        for (int j = 0; j < grille.getColonnes(); ++j) {
            fichier << (grille.getCellules()[i][j].obtenirEtat() ? 1 : 0) << " "; // Écrire 1 pour vivant, 0 pour mort
        }
        fichier << std::endl; // Saut de ligne après chaque ligne de la grille
    }

    fichier.close(); // Fermer le fichier après l'écriture
}

