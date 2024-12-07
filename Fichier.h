#ifndef FICHIER_H
#define FICHIER_H

#include <vector>
#include <string>
#include "Grille.h"

class Fichier {
public:
    static std::vector<std::vector<bool>> lireEtatInitial(const std::string& cheminFichier);
    static void ecrireEtat(const std::string& cheminFichier, const Grille& grille);
};

#endif // FICHIER_H
