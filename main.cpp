#include "JeuDeLaVie.h"
#include <iostream>

int main() {
    std::cout << "Bienvenue dans le Jeu de la Vie!\n";
    std::cout << "Choisir le mode:\n";
    std::cout << "1 - Mode console\n";
    std::cout << "2 - Mode graphique\n";

    int choixMode;
    std::cin >> choixMode;

    if (choixMode == 1) {
        std::string fichierEntree = "input.txt";
        std::string fichierSortie = "resultat.txt";
        int nombreIterations = 100;
        JeuDeLaVie jeu(fichierEntree, nombreIterations);
        jeu.executerConsole(fichierSortie);
    }
    else if (choixMode == 2) {
        int hauteur = 40;
        int largeur = 40;
        float iterationTime = 0.5f; // Temps en secondes entre les itérations
        JeuDeLaVie jeu(hauteur, largeur, iterationTime);
        jeu.demarrerSimulationGraphique();
    }
    else {
        std::cout << "Choix invalide! Le programme va se terminer.\n";
    }

    return 0;
}

