#ifndef JEUDELAVIE_H
#define JEUDELAVIE_H

#include "Grille.h"
#include <string>

class JeuDeLaVie {
private:
    Grille grille;
    int iterations;

public:
    JeuDeLaVie(const std::string& cheminFichier);
    void demarrerSimulation();
    void chargerEtatInitial(const std::string& cheminFichier);
    void sauvegarderEtat(const std::string& cheminFichier);
};

#endif // JEUDELAVIE_H
