#include "JeuDeLaVie.h"
#include <iostream>
#include <thread>
#include <chrono>

JeuDeLaVie::JeuDeLaVie(const std::string& fichierEntree, int iterations)
    : grille(0, 0), maxIterations(iterations), mode(ModeAffichage::CONSOLE), iterationTime(0.5f) {
    std::vector<std::vector<bool>> etats;
    int h, l;
    if (!Fichier::lireEtatInitial(fichierEntree, etats, h, l)) {
        std::cerr << "Impossible de charger l'état initial.\n";
    }
    else {
        grille = Grille(h, l);
        grille.initialiser(etats);
    }
}

JeuDeLaVie::JeuDeLaVie(int hauteur, int largeur, float iterationTime)
    : grille(hauteur, largeur), maxIterations(100), mode(ModeAffichage::GRAPHIQUE), iterationTime(iterationTime) {
    // Grille vide au départ, mode graphique.
}

void JeuDeLaVie::executerConsole(const std::string& fichierSortie) {
    std::cout << "État initial :\n";
    grille.afficherConsole();

    Grille ancienne = grille;
    for (int it = 0; it < maxIterations; ++it) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        grille.miseAJour();
        std::cout << "\n--- Itération " << it + 1 << " ---\n";
        grille.afficherConsole();

        if (grille.estIdentique(ancienne)) {
            std::cout << "Aucun changement détecté, arrêt.\n";
            break;
        }
        ancienne = grille;
    }

    // Sauvegarde de l'état final
    std::vector<std::vector<bool>> etatFinal(grille.getHauteur(), std::vector<bool>(grille.getLargeur(), false));
    for (int i = 0; i < grille.getHauteur(); ++i) {
        for (int j = 0; j < grille.getLargeur(); ++j) {
            etatFinal[i][j] = grille.estVivante(i, j);
        }
    }
    Fichier::ecrireEtat(fichierSortie, etatFinal);
}

void JeuDeLaVie::demarrerSimulationGraphique() {
    InterfaceGraphique interfaceGraphique(grille, iterationTime);
    interfaceGraphique.lancerSimulation();
}
