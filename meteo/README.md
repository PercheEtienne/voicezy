
# **La Récupération de la météo**
La récupération de la météo est appelée dans notre projet lorsque nous lançons la commande vocale "météo" et elle est ensuite représenté sur la matrice de LEDs par un dessin (soleil, nuage, pluie, ...)

## Les librairies utilisées

Pour récupérer la météo, nous avons utilisé une [API
](https://openweathermap.org/api). Nous avions donc besoin d'effectuer des requêtes HTTPS depuis le Raspberry. Nous avons donc utilisé la librairie CURL. Cependant avec la librairie seule, nous pouvions réalisé uniquement des requêtes HTTP et pas HTTPS.
Il a donc fallu utilisé la librairie openSSL, qui permet de gérer les connections sécurisées. Finalement, nous avons utilisé la librairie zlib, car nous avions une erreur en utilisant les deux premières librairies ensemble, l'utilisation de zlib nous a permsi de la corriger.

## Files

### simple_http_request.c

Test d'une requête HTTP

### simple_https_request.c

Test d'une requête HTTPS

### test_meteo.c

Test de l'API et récupération du JSON

### récupération_météo

Récupération du JSON et on le "parse" pour récupérer l'information voulue.

