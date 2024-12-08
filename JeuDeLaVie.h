#ifndef JEUDELAVIE_H
#define JEUDELAVIE_H

#include "Grille.h"
#include "Fichier.h"
#include "InterfaceGraphique.h"
#include <string>

enum class ModeAffichage {
    CONSOLE,
    GRAPHIQUE
};

class JeuDeLaVie {
private:
    Grille grille;
    int maxIterations;
    ModeAffichage mode;
    float iterationTime; // Temps entre itérations en mode graphique

public:
    JeuDeLaVie(const std::string& fichierEntree, int iterations);
    JeuDeLaVie(int hauteur, int largeur, float iterationTime);

    void executerConsole(const std::string& fichierSortie);
    void demarrerSimulationGraphique();
};

#endif // JEUDELAVIE_H
