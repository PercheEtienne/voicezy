#! /bin/sh

RETOUR_CHARIOT=""
PATH_PROJET=/home/pi/voicezy


echo "SCRIPT D'INSTALLATION DE DEEPSPEECH -> RECONNAISSANCE VOCALE HORS LIGNE";
echo -e "\nappuyez sur entrée pour continuer";
read ;

if [ $(whoami) != "root" ]
then 
	echo "POUR CONTINUER, VOUS DEVEZ ETRE ROOT";
	exit 1;
fi

echo "----------DEBUT DE L'INSTALLATION-------------";

# LECTURE DU CHEMIN DU PROJET
echo "CHEMIN DU PROJET\n";

echo "\n\t-> veuillez entrer le chemin du projet (par default: $PATH_PROJET)\n\t-> appuyer sur entree si vous ne souhaitez pas changer le chemin par default)";
read path
if [ "$path" != "$RETOUR_CHARIOT" ]
then
		PATH_PROJET=$path
fi
echo "PATH_PROJET = $PATH_PROJET\n";
echo "appuyer sur entrée pour continuer...\n";
cd $PATH_PROJET;
echo "FIN CHEMIN DU PROJET\n";
read a

# MAJ DES PAQUETS RPI

echo "\n\t-> voulez vous faire la maj des paquets ?\n\t-> oui ou non";
read path
if [ "$path" != "non" ]
then
	echo "\n-> mise à jour des paquets";
	apt-get update
	apt-get upgrade
fi
echo "\nappuyer sur entrée pour continuer...\n";
echo "FIN MAJ PAQUETS \n";
read a
clear;

# INSTALLATION DE SOX

echo "\n\t-> voulez vous faire l'installation de sox ?\n\t-> oui ou non";
read path
if [ "$path" != "non" ]
then
	echo "\n-> installation de sox";
	apt-get install sox
fi
echo "\nappuyer sur entrée pour continuer...\n";
echo "FIN INSTALLATION SOX \n";
read a
clear;

# INSTALLATION DE PIP

echo "\n\t-> voulez vous faire l'installation de pip ?\n\t-> oui ou non";
read path
if [ "$path" != "non" ]
then
	echo "\n-> installation de pip";
	apt-get install python-pip
fi
echo "\nappuyer sur entrée pour continuer...\n";
echo "FIN INSTALLATION PIP \n";
read a
clear;

# INSTALLATION DE TENSORFLOW

echo "\n\t-> voulez vous faire l'installation de tensorflow ?\n\t-> oui ou non";
read path
if [ "$path" != "non" ]
then
	echo "\n-> installation de tensorflow";
	pip3 install tensorflow
fi
echo "\nappuyer sur entrée pour continuer...\n";
echo "FIN INSTALLATION TENSORFLOW \n";
read a
clear;

# INSTALLATION DE DEEPSPEECH

echo "\n\t-> voulez vous faire l'installation de deepspech ?\n\t-> oui ou non";
read path
if [ "$path" != "non" ]
then
	echo "\n-> installation de deepspech";
	pip3 install deepspeech --user
fi
echo "\nappuyer sur entrée pour continuer...\n";
echo "FIN INSTALLATION DEEPSPEECH \n";
read a
clear;

# VERIFICATION DE LA VERSION DE DEEPSPEECH

echo "VERSION DE DEEPSPEECH ET TENSORFLOW";
deepspeech --version;