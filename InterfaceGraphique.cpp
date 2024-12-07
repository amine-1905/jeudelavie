#include "InterfaceGraphique.h"
#include "Grille.h"
#include <SFML/Graphics.hpp>

InterfaceGraphique::InterfaceGraphique(Grille& grille)
    : fenetre(sf::VideoMode(800, 600), "Jeu de la Vie"), grille(grille) {
    fenetre.setFramerateLimit(30);
}

void InterfaceGraphique::afficher() {
    fenetre.clear();

    // Accès aux cellules via obtenirCellules()
    const auto& cellules = grille.obtenirCellules();
    int lignes = grille.getLignes();
    int colonnes = grille.getColonnes();

    // Afficher chaque cellule en fonction de son état
    for (int y = 0; y < lignes; ++y) {
        for (int x = 0; x < colonnes; ++x) {
            sf::RectangleShape cell(sf::Vector2f(20, 20));
            cell.setPosition(x * 20, y * 20);

            if (cellules[y][x].obtenirEtat()) {
                cell.setFillColor(sf::Color::Green);  // Cellule vivante
            } else {
                cell.setFillColor(sf::Color::Black);  // Cellule morte
            }

            fenetre.draw(cell);
        }
    }

    fenetre.display();
}

void InterfaceGraphique::gererEvenements() {
    sf::Event event;
    while (fenetre.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            fenetre.close();
    }
}

void InterfaceGraphique::lancerSimulation() {
    while (fenetre.isOpen()) {
        gererEvenements();
        grille.mettreAJour();
        afficher();
        sf::sleep(sf::milliseconds(100));  // Temps entre chaque itération
    }
}

