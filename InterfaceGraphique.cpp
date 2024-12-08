#include "InterfaceGraphique.h"
#include <iostream>

InterfaceGraphique::InterfaceGraphique(Grille& grille, float iterationTime)
    : grille(grille), iterationTime(iterationTime), simulationLancee(false) {
    unsigned int width = grille.getLargeur() * 20;
    unsigned int height = grille.getHauteur() * 20;
    fenetre.create(sf::VideoMode(width, height), "Jeu de la Vie");
    fenetre.setFramerateLimit(30);
}

void InterfaceGraphique::lancerSimulation() {
    while (fenetre.isOpen()) {
        gererEvenements();

        if (simulationLancee && clock.getElapsedTime().asSeconds() >= iterationTime) {
            Grille ancienne = grille;
            grille.miseAJour();
            clock.restart();

            if (grille.estIdentique(ancienne)) {
                std::cout << "Grille stable, arrêt de la simulation.\n";
                simulationLancee = false;
            }
        }

        fenetre.clear(sf::Color::White);
        afficherGrille();
        fenetre.display();
    }
}

void InterfaceGraphique::afficherGrille() {
    int cellSize = 20;

    for (int x = 0; x < grille.getHauteur(); ++x) {
        for (int y = 0; y < grille.getLargeur(); ++y) {
            sf::RectangleShape cell(sf::Vector2f((float)cellSize - 1, (float)cellSize - 1));
            cell.setPosition((float)(y * cellSize), (float)(x * cellSize));
            cell.setFillColor(grille.estVivante(x, y) ? sf::Color::Green : sf::Color::Black);
            fenetre.draw(cell);
        }
    }
}

void InterfaceGraphique::gererEvenements() {
    sf::Event event;
    while (fenetre.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            fenetre.close();
        }

        // Si on clique sur la souris (gauche) avant de lancer la simulation
        if (!simulationLancee && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            int cellSize = 20;
            int y = event.mouseButton.x / cellSize;
            int x = event.mouseButton.y / cellSize;
            if (x >= 0 && x < grille.getHauteur() && y >= 0 && y < grille.getLargeur()) {
                bool actuel = grille.estVivante(x, y);
                grille.setEtat(x, y, !actuel);
            }
        }

        // Appuyer sur espace pour lancer la simulation
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            simulationLancee = true;
            clock.restart();
        }

        // Appuyer sur Echap pour fermer la fenêtre
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            fenetre.close();
        }
    }
}
