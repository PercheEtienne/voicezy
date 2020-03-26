# Utilisation du micro / Enregistrement de la voix
- Paquets / Commandes utilisées 
 - Choix du micro
 

## Paquets / Commandes utilisées 
Pour procéder a l'enregistrement de la voix, on utilise le paquet arecord.
la commande que nous utilisons est donc :

    arecord -f cd -t wav -D plughw:<microNumber>,0 <filename>

Le numéro de micro correspond au numéro de la carte son souhaité. Cela est visible avec la commande arecord -l
Ce numéro doit être un entier positif, souvent 0, 1 ou 2

Le fichier son contenant l'enregistrement est au format *.wav


## Choix du micro
Nous avons choisi un casque micro USB basique pour procéder à l'enregistrement du son ( = de la voix). 
Nous avons juger ce micro de meilleur qualité que le micro de base intégré a la mallette joyPi car celui produit moins de 'grésillement' dans le fichier enregistré.