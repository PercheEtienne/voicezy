# Firebase

Firebase est un ensemble de services d'hébergement pour n'importe quel type d'application. Il propose d'héberger en NoSQL et en temps réel des bases de données, du contenu, de l'authentification sociale, et des notifications, ou encore des services, tel que par exemple un serveur de communication temps réel.

Nous l'utilisons ici pour voir en temps réel les données envoyées par le Raspberry.

## Pyrebase

Etant donné que nous n'avons trouvé aucune librairie pour utiliser en Firebase, nous avons choisi d'utiliser une librairie en python : pyrebase.

# Files

### sendToFirebase.py

Ce script est le script gérant la connexion à notre base de données Firebase ainsi qu'à l'envoi de donnée.

Il envoi un JSON de la forme : 

`{"Temperature" : "20.8", "time" : "04/04/2020 18:20:15"}`

Il faut lui passer 2 paramètres : 

- Le type de donnée envoyé (Température, humidité, Luminosité, ...).
- La valeur de la donnée.

## installPyrebase.sh

Script qui permet d'installer la librairie pyrebase.

# Directories

### library

Dossier comprenant les fichiers de librairie (C) permettant d'envoyer les données voulues à Firebase

### examples

Dossier comprenant les fichiers d'exemples permettant d'utiliser la librairie.