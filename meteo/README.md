
# **La Récupération de la météo**
La récupération de la météo est appelée dans notre projet lorsque nous lançons la commande vocale "météo" et elle est ensuite représenté sur la matrice de LEDs par un dessin (soleil, nuage, pluie, ...)

## Les librairies utilisées

Pour récupérer la météo, nous avons utilisé une [API
](https://openweathermap.org/api). Nous avions donc besoin d'effectuer des requêtes HTTPS depuis le Raspberry. Nous avons donc utilisé la librairie CURL. Cependant avec la librairie seule, nous pouvions réalisé uniquement des requêtes HTTP et pas HTTPS.
Il a donc fallu utilisé la librairie openSSL, qui permet de gérer les connections sécurisées. Finalement, nous avons utilisé la librairie zlib, car nous avions une erreur en utilisant les deux premières librairies ensemble, l'utilisation de zlib nous a permsi de la corriger.


## Directories

### library

Dossier qui contient la librairie que nous avons crée.

### parseMeteo

Dossier qui contient les librairies et exemples servant à parser le JSON que l'on récupère une fois notre requête effectuée.

### tests

Dossier qui contient les tests de requêtes HTTP/HTTPS.

### examples

Dossier qui contient les exemples d'utilisation de la librairie
