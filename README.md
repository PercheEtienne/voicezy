
# VOICEZY
Projet de reconnaissance vocale avec le raspberry et la maquette JoyPi

# Les commandes vocales
1.  La commande “Météo”

-   Elle permettra d’avoir la météo du jour à Lens. On affichera par exemple un soleil sur la matrice s’il fait beau.
    
-   On utilisera une API pour la météo.

2.  La commande “Musique”
-   Permettra de jouer une petite musique sur le buzzer

3.  La commande “Allume/Éteint la lumière” qui permettra d’éteindre ou d’allumer une LED
4.  La commande “Twitter + CMD”
-   CMD = “luminosité” permet de tweeter la luminosité actuelle
-   CMD = “température” permet de tweeter la température actuelle
-   CMD = “humidité” permet de tweeter l’humidité actuelle

# La communication avec un autre microcontrôleur

Sachant que l’on peut pas personnaliser l’utilisation des GPIO du RPI, on aimerait communiquer par WiFi avec un microcontrolleur qui aura accès à une matrice de LEDs RGB et avec plus de LEDs. On aurait également accès à un relais avec une lampe qui permettrait de simuler l’allumage d’une lampe. 

# Directory

## button

Ce dossier contient la librairie et les fichiers d'exemples pour le bouton

## led_matrix

Ce dossier contient la librairie et les fichiers d'exemples pour la matrice

## meteo

Ce dossier contient la librairie et les fichiers d'exemples pour la récupération de météo

## micro

Ce dossier contient le script d'exemple d'utilisation du micro

## project

Ce dossier contient le code de chaque version du projet

## reconnaissance 

Ce dossier contient les fichiers utiles à la reconnaissance vocale

# Files

## recupereWavFiles

Script qui récupère les fichiers audios enregistrés par le Raspberry

## sendExecutablesToRaspberry

Script qui envoit le fichier passé en paramètre au raspberry