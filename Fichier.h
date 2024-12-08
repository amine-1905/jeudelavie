#ifndef FICHIER_H
#define FICHIER_H

#include <string>
#include <vector>

class Fichier {
public:
    static bool lireEtatInitial(const std::string& cheminFichier,
        std::vector<std::vector<bool>>& etats,
        int& hauteur, int& largeur);

    static void ecrireEtat(const std::string& cheminFichier,
        const std::vector<std::vector<bool>>& etats);
};

#endif // FICHIER_H
