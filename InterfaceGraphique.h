#ifndef INTERFACEGRAPHIQUE_H
#define INTERFACEGRAPHIQUE_H

#include <SFML/Graphics.hpp>
#include "Grille.h"

class InterfaceGraphique {
private:
    sf::RenderWindow fenetre;
    Grille& grille;
    const int tailleCellule = 20;

public:
    InterfaceGraphique(Grille& grille);
    void afficher();
    void gererEvenements();
    void lancerSimulation();
};

#endif // INTERFACEGRAPHIQUE_H

