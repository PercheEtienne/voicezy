# Filtrer les résultats de l'API Méteo

Le résultat de l'API est obtenu sous forme d'une chaine de caractères. Il est
donc nécessaire de la parser afin d'obtenir uniquement les informations 
voulue.

## Files

### /librairie/parseMeteo.c
Ce fichier comporte les fonctions :
   -  `char *substr(char *src,int pos,int len);`
   Cette fonction est faite pour creer une nouvelle chaine
   corespodant à un morceau de la chaine source   
   
   -  `char* infoMeteo(char* string);`
   Cette fonction permet de récupérer l'information de la meteo. (Par exemple : Clouds)
   
   -  `char* infoTempEnKelvin(char * string);`
      Cette fonction permet de récupérer la valeur de la température en Kelvin

### /librairie/parseMeteo.h
Il s'agit du fichier d'en-tête du fichier parseMeteo.c

### /exemples/recupMeteo.c
Il s'agit du code source permettant de tester les fonctions de la librairie parseMeteo. Le make fournit une version pour le pc et une autre pour le RaspberryPi
