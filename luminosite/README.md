# Le capteur de luminosité
Nous utilisons le capteur de luminosité intégré au JoyPi. Il s'agit d'un BH1750 (nous retrouvons la datasheet via ce lien : https://components101.com/sites/default/files/component_datasheet/BH1750.pdf)

Il permet de récupérer la valeur de luminosité en Lux. Il communique avec le Raspberry Pi via le protocole I2C

## Le protocole I2C

Le bus I2C permet de faire communiquer entre eux des composants électroniques très divers grace à seulement trois fils : Un signal de donnée ( SDA ), un signal d'horloge ( SCL ), et un signal de référence électrique ( Masse ).

## Files

### librairie/lightsensor.c

Il s'agit du code de la fonction permettant de réaliser la communication I2C entre le composant et le RaspberryPi.
La fonction se nomme `getLuminositeEnLux();`et permet comme son nom l'indique de récupérer la valeur de luminosité en Lux.

### librairie/lightsensor.h

Il s'agit du fichier d'en-tête de lightsensor.c

### exemples/testBH1750.c

C'est le code source permettant de générer un éxecutable pour le Raspberry Pi afin de tester la librairie lightsensor
