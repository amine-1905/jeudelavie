Jeu de la Vie


Jeu de la Vie est une implémentation en C++ du célèbre automate cellulaire conçu par le mathématicien John Conway. Ce projet propose deux modes d'affichage : un mode console pour visualiser l'évolution des cellules en texte, et un mode graphique utilisant la bibliothèque SFML pour une représentation visuelle interactive.

Table des Matières
Fonctionnalités
Structure du Projet
Dépendances
Installation
1. Cloner le Projet
2. Installer SFML
3. Configurer Dev-C++
Compilation
Utilisation
Mode Console
Mode Graphique
Exemple
Débogage
Contributions
Licence
Contact
Fonctionnalités
Deux Modes d'Affichage :
Console : Visualisation textuelle des cellules vivantes et mortes.
Graphique : Interface interactive avec SFML permettant de cliquer pour activer/désactiver des cellules.
Chargement et Sauvegarde :
Lecture : Importation de l'état initial depuis un fichier texte.
Écriture : Sauvegarde de l'état final de la grille dans un fichier texte.
Règles du Jeu de la Vie :
Application des règles de naissance et de mort des cellules pour chaque itération.
Structure du Projet
css
Copier le code
JeuDeLaVie/
├── include/
│   ├── Cellule.h
│   ├── Grille.h
│   ├── Fichier.h
│   ├── JeuDeLaVie.h
│   └── InterfaceGraphique.h
├── src/
│   ├── Cellule.cpp
│   ├── Grille.cpp
│   ├── Fichier.cpp
│   ├── JeuDeLaVie.cpp
│   ├── InterfaceGraphique.cpp
│   └── main.cpp
├── input.txt
└── README.md
include/ : Contient tous les fichiers d'en-tête (.h).
src/ : Contient tous les fichiers sources (.cpp).
input.txt : Fichier d'entrée contenant l'état initial de la grille.
README.md : Ce fichier.
Dépendances
Langage : C++17
Bibliothèques :
SFML (Simple and Fast Multimedia Library) pour l'affichage graphique.
Installation
1. Cloner le Projet
Clonez ce dépôt ou téléchargez-le en tant qu'archive ZIP et extrayez-le dans votre répertoire de travail préféré.

bash
Copier le code
git clone https://github.com/votre-utilisateur/JeuDeLaVie.git
2. Installer SFML
Téléchargement :

Rendez-vous sur le site officiel de SFML.
Téléchargez la version correspondant à votre compilateur (par exemple, GCC 7.3 MinGW (DW2) si vous utilisez Dev-C++ avec MinGW 7.3).
Extraction :

Extrayez le contenu de l'archive téléchargée dans un dossier, par exemple C:\SFML.
Copie des DLL :

Dans le dossier C:\SFML\bin, copiez les DLL nécessaires (sfml-graphics-2.dll, sfml-window-2.dll, sfml-system-2.dll, etc.) dans le même répertoire que votre exécutable après la compilation (jeu.exe), ou ajoutez C:\SFML\bin à votre variable d'environnement PATH.
3. Configurer Dev-C++
Ouvrir Dev-C++ :

Lancez Dev-C++ sur votre ordinateur.
Ajouter les Répertoires d'Inclure et de Lib SFML :

Allez dans Outils > Options du compilateur > Répertoires.
Sous Inclure, ajoutez le chemin vers le dossier include de SFML (par exemple, C:\SFML\include).
Sous Bibliothèques, ajoutez le chemin vers le dossier lib de SFML (par exemple, C:\SFML\lib).
Ajouter les Options du Compilateur et du Linker :

Allez dans Projet > Options du projet > Paramètres du compilateur.
Dans la section Paramètres supplémentaires du compilateur, ajoutez :
c
Copier le code
-std=c++17
Dans la section Linker, ajoutez les librairies SFML :
sql
Copier le code
-lsfml-graphics -lsfml-window -lsfml-system
Compilation
Créer un Nouveau Projet :

Ouvrez Dev-C++.
Allez dans Fichier > Nouveau > Projet.
Sélectionnez Console Application ou Empty Project.
Nommez votre projet (par exemple, JeuDeLaVie) et choisissez un emplacement approprié.
Ajouter les Fichiers Sources :

Une fois le projet créé, allez dans Projet > Ajouter un fichier existant.
Sélectionnez et ajoutez tous vos fichiers sources (Cellule.cpp, Grille.cpp, Fichier.cpp, JeuDeLaVie.cpp, InterfaceGraphique.cpp, main.cpp).
Compiler le Projet :

Cliquez sur Compiler & Exécuter ou appuyez sur F11.
Si la compilation réussit, un exécutable (jeu.exe) sera généré dans le dossier de sortie spécifié.
Utilisation
Mode Console
Préparation :

Assurez-vous que le fichier input.txt est présent dans le répertoire racine du projet.
Exécution :

Lancez jeu.exe.
Entrez 1 pour sélectionner le mode console.
Fonctionnement :

Le programme lira l'état initial depuis input.txt, effectuera les itérations spécifiées, affichera chaque état dans la console, et sauvegardera le résultat final dans resultat.txt.
Mode Graphique
Préparation :

Assurez-vous que les DLL SFML sont présentes dans le même dossier que jeu.exe.
Exécution :

Lancez jeu.exe.
Entrez 2 pour sélectionner le mode graphique.
Fonctionnement :

Une fenêtre SFML s'ouvrira affichant la grille.
Interaction :
Cliquer sur les Cellules : Activez ou désactivez l'état des cellules avant de lancer la simulation.
Barre d'Espace : Appuyez sur la barre d'espace pour démarrer la simulation.
La simulation évoluera automatiquement selon les règles du Jeu de la Vie.
Exemple
input.txt
Voici un exemple de fichier input.txt pour initialiser la grille :

Copier le code
5 10
0 0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 1 1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
Format :
La première ligne indique la hauteur et la largeur de la grille.
Les lignes suivantes représentent l'état initial des cellules (1 pour vivante, 0 pour morte).
Débogage
Si vous rencontrez des problèmes lors de la compilation ou de l'exécution, voici quelques conseils de débogage :

Messages d'Erreur :

Lisez attentivement les messages d'erreur pour identifier le fichier et la ligne où le problème se produit.
Vérifier les Inclusions :

Assurez-vous que tous les fichiers headers sont correctement inclus avec des guillemets doubles (" ") et non des crochets (< >).
Chemins Corrects :

Vérifiez que les chemins vers les fichiers headers et les bibliothèques SFML sont correctement configurés dans Dev-C++.
Gardes d'Inclusion :

Chaque fichier header doit avoir des gardes d'inclusion uniques pour éviter les inclusions multiples.
Compatibilité SFML :

Assurez-vous que la version de SFML correspond à celle de votre compilateur MinGW utilisé par Dev-C++.
DLL Manquantes :

Pour le mode graphique, assurez-vous que toutes les DLL SFML nécessaires sont présentes dans le même dossier que jeu.exe.
Nettoyer et Recompiler :

Parfois, nettoyer le projet (supprimer les fichiers objets) et recompiler entièrement peut résoudre des problèmes de compilation.
Contributions
Les contributions sont les bienvenues ! Si vous souhaitez améliorer ce projet, veuillez suivre ces étapes :

Fork le Dépôt
Créer une Branche (git checkout -b feature/amélioration)
Commiter vos Changements (git commit -m 'Ajout d'une nouvelle fonctionnalité')
Pousser vers la Branche (git push origin feature/amélioration)
Ouvrir une Pull Request
