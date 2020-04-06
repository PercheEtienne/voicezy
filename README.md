
# VOICEZY
Projet de reconnaissance vocale avec le raspberry et la maquette JoyPi

# Les commandes vocales
Il faut faire des phrases courtes contenant le mot inscrit dans les parenthèses à côté du nom de la commande.
1.  La commande “Météo” (phrase contenant le mot: "weather")

-   Elle permettra d’avoir la météo du jour à Lens. On affichera par exemple un soleil sur la matrice s’il fait beau.
    
-   On utilisera une API pour la météo.

2.  La commande “Musique” (phrase contenant le mot: "play" ou "song")
-   Permettra de jouer une petite musique sur le buzzer

3.  La commande “Allume/Éteint la lumière” qui permettra d’éteindre ou d’allumer une LED (phrase contenant le mot: "light" et "on" pour allumer et "light" et rien d'autre pour eteindre)
4.  La commande “CMD”
-   CMD = “luminosité” permet de "publier" sur Firebase la luminosité actuelle (phrase contenant le mot: "brightness")
-   CMD = “température” permet de "publier" sur Firebase la température actuelle (phrase contenant le mot: "temperature")
-   CMD = “humidité” permet de "publier" sur Firebase l’humidité actuelle (phrase contenant le mot: "humidity")

# La communication avec un autre microcontrôleur

Sachant que l’on peut pas personnaliser l’utilisation des GPIO du RPI, on communique par Bluetooth avec un microcontrolleur qui aura accès à une matrice de LEDs RGB et avec plus de LEDs.

# Directories

## button

Ce dossier contient la librairie et les fichiers d'exemples pour le bouton

## buzzer

Ce dossier contient la librairie et les fichiers d'exemples pour jouer une musique sur le buzzer

## communication

Ce dossier contient les fichiers utiles à la communication avec l'arduino ainsi que le code pour l'arduino

## flutter_app

Ce dossier contient les fichiers de l'application en Flutter

## led_matrix

Ce dossier contient la librairie et les fichiers d'exemples pour la matrice

## magPi - Voicezy

Ce dossier contient uniquement la version finale de l'exemplaire du compte-rendu du projet, avec une format très fortement inspiré du magazine MagPi

## meteo

Ce dossier contient la librairie et les fichiers d'exemples pour la récupération de météo

## micro

Ce dossier contient le script d'exemple d'utilisation du micro

## project

Ce dossier contient le code de chaque version du projet

## pyrebase

Ce dossier contient l'ensemble du code et des scripts liés à l'utilisation de Firebase (ici pyrebase)

## reconnaissance_vocale

Ce dossier contient les fichiers utiles à la reconnaissance vocale

## temperature

Ce dossier contient des exemples et la librarie concernant le capteur de température

## threads

Ce dossier contient des exemples de programme avec des threads

# Files

## recupereWavFiles

Script qui récupère les fichiers audios enregistrés par le Raspberry

## sendExecutablesToRaspberry

Script qui envoit le fichier passé en paramètre au raspberry
