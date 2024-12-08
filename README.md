Jeu de la Vie


Jeu de la Vie est une implémentation en C++ du célèbre automate cellulaire conçu par le mathématicien John Conway. Ce projet propose deux modes d'affichage : un mode console pour visualiser l'évolution des cellules en texte, et un mode graphique utilisant la bibliothèque SFML pour une représentation visuelle interactive.

Table des Matières
Fonctionnalités
Structure du Projet
Dépendances
Installation
1. Cloner le Projet
2. Installer SFML
3. Configurer Visual Studio 2022
Compilation
Utilisation
Mode Console
Mode Graphique
Exemple
Débogage
Contributions
Licence
Auteurs
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
├── resultat.txt
└── JeuDeLaVie.sln
include/ : Contient tous les fichiers d'en-tête (.h).
src/ : Contient tous les fichiers sources (.cpp).
input.txt : Fichier d'entrée contenant l'état initial de la grille.
resultat.txt : Fichier de sortie contenant l'état final de la grille après simulation.
JeuDeLaVie.sln : Solution Visual Studio 2022.
Dépendances
Langage : C++17
Bibliothèques :
SFML (Simple and Fast Multimedia Library) pour l'affichage graphique.
Installation
1. Cloner le Projet
Clonez ce dépôt ou téléchargez-le en tant qu'archive ZIP et extrayez-le dans votre répertoire de travail préféré.


2. Installer SFML
Téléchargement :

Rendez-vous sur le site officiel de SFML.
Téléchargez la version correspondant à votre compilateur. Pour Visual Studio 2022, choisissez la version Visual C++ 17 (MSVC 17) - 64-bit.
Extraction :

Extrayez le contenu de l'archive téléchargée dans un dossier, par exemple C:\SFML.
Copie des DLL :

Dans le dossier C:\SFML\bin, copiez les DLL nécessaires (sfml-graphics-2.dll, sfml-window-2.dll, sfml-system-2.dll, etc.) dans le même répertoire que votre exécutable après la compilation (JeuDeLaVie.exe), ou ajoutez C:\SFML\bin à votre variable d'environnement PATH.
3. Configurer Visual Studio 2022
Ouvrir Visual Studio 2022 :

Lancez Visual Studio 2022 sur votre ordinateur.
Ouvrir la Solution :

Ouvrez le fichier JeuDeLaVie.sln situé à la racine du projet.
Configurer les Répertoires d'Inclure et de Lib SFML :

Inclure :
Faites un clic droit sur le projet dans l'Explorateur de solutions et sélectionnez Propriétés.
Allez dans C/C++ > Général > Répertoires des fichiers d'inclusion supplémentaires.
Ajoutez le chemin vers le dossier include de SFML (par exemple, C:\SFML\include).
Bibliothèques :
Toujours dans les Propriétés du projet, allez dans Linker > Général > Répertoires des fichiers de bibliothèque supplémentaires.
Ajoutez le chemin vers le dossier lib de SFML (par exemple, C:\SFML\lib).
Ajouter les Librairies SFML :

Dans les Propriétés du projet, allez dans Linker > Input > Dépendances supplémentaires.
Ajoutez les librairies SFML nécessaires :
vbnet

sfml-graphics.lib
sfml-window.lib
sfml-system.lib
sfml-main.lib
Configurer le Répertoire de Sortie des DLL :

Assurez-vous que les DLL de SFML sont accessibles lors de l'exécution :
Copiez les DLL de C:\SFML\bin dans le dossier de sortie de votre projet (généralement Debug ou Release).
OU
Ajoutez C:\SFML\bin à votre variable d'environnement PATH.
Compilation
Construire la Solution :

Dans Visual Studio, allez dans le menu Build et sélectionnez Build Solution (ou appuyez sur Ctrl + Shift + B).
Assurez-vous qu'il n'y a pas d'erreurs de compilation.
Exécuter le Projet :

Une fois la compilation réussie, exécutez le programme en appuyant sur F5 ou en cliquant sur Start.
Utilisation
Mode Console
Préparation :

Assurez-vous que le fichier input.txt est présent dans le répertoire de sortie (Debug ou Release).
Exécution :

Lancez JeuDeLaVie.exe.
Entrez 1 pour sélectionner le mode console.
Fonctionnement :

Le programme lira l'état initial depuis input.txt, effectuera les itérations spécifiées, affichera chaque état dans la console, et sauvegardera le résultat final dans resultat.txt.
Mode Graphique
Préparation :

Assurez-vous que les DLL SFML sont présentes dans le même dossier que JeuDeLaVie.exe.
Exécution :

Lancez JeuDeLaVie.exe.
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

Lisez attentivement les messages d'erreur dans Visual Studio pour identifier le fichier et la ligne où le problème se produit.
Vérifier les Inclusions :

Assurez-vous que tous les fichiers headers sont correctement inclus avec des guillemets doubles (" ") et non des crochets (< >).
Chemins Corrects :

Vérifiez que les chemins vers les fichiers headers et les bibliothèques SFML sont correctement configurés dans Visual Studio.
Gardes d'Inclusion :

Chaque fichier header doit avoir des gardes d'inclusion uniques pour éviter les inclusions multiples.
Compatibilité SFML :

Assurez-vous que la version de SFML correspond à celle de votre compilateur Visual Studio 2022.
DLL Manquantes :

Pour le mode graphique, assurez-vous que toutes les DLL SFML nécessaires sont présentes dans le même dossier que JeuDeLaVie.exe.
Nettoyer et Recompiler :

Parfois, nettoyer le projet (supprimer les fichiers intermédiaires) et recompiler entièrement peut résoudre des problèmes de compilation.
Contributions
Les contributions sont les bienvenues ! Si vous souhaitez améliorer ce projet, veuillez suivre ces étapes :

Fork le Dépôt
Créer une Branche (git checkout -b feature/amélioration)
Commiter vos Changements (git commit -m 'Ajout d'une nouvelle fonctionnalité')
Pousser vers la Branche (git push origin feature/amélioration)
Ouvrir une Pull Request
Licence
Ce projet est sous licence MIT. Voir le fichier LICENSE pour plus de détails.

Auteurs
Ce projet a été réalisé par le binôme Berraki et Bouchou.(groupe21)

Contact
Pour toute question ou suggestion, veuillez contacter :

Berraki

Email : berraki@example.com
GitHub : https://github.com/berraki
Bouchou

Email : bouchou@example.com
GitHub : https://github.com/bouchou
Merci d'avoir choisi Jeu de la Vie ! Nous espérons que ce projet vous sera utile et inspirant.
