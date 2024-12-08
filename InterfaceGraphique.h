#ifndef INTERFACEGRAPHIQUE_H
#define INTERFACEGRAPHIQUE_H

#include <SFML/Graphics.hpp>
#include "Grille.h"

class InterfaceGraphique {
private:
    Grille& grille;
    sf::RenderWindow fenetre;
    float iterationTime;
    bool simulationLancee;
    sf::Clock clock;

public:
    InterfaceGraphique(Grille& grille, float iterationTime = 0.5f);

    void lancerSimulation();

private:
    void afficherGrille();
    void gererEvenements();
};

#endif // INTERFACEGRAPHIQUE_H
