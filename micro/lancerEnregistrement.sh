#!/bin/bash

if [ $# -ne 2 ]
then
        echo "Il faut éxecuter la commande : ./lancerEnregistrement.sh <Numero_de_micro> <Nom_De_Fichier>"
	echo "Le numero de micro correspond au numéro de la carte son souhaité. Cela est visible avec la commande 'arecord -l' !"
	echo "Le fichier doit avoir nom avec l'extension '.wav' et ne doit pas contenir d'espace ! "
	exit 0
fi

microNumber=$1

if [[ $microNumber = +([0-9]) ]] ; then
	echo "Micro Ok."
else
	echo "Le numero de micro correspond au numéro de la carte son souhaité. Cela est visible avec la commande 'arecord -l' !"
	echo "Ce numéro doit être un entier positif, souvent 0, 1 ou 2"
	exit 0
fi

filename=$2
EXT_FICHIER=${filename#*.}

if [ $EXT_FICHIER = "wav" ]
then
	#Lacement de l'enregistrement
	echo "Extension Ok."
	arecord -f cd -t wav -D plughw:$microNumber,0 $filename
else
	echo "Le fichier doit avoir nom avec l'extension '.wav' et ne doit pas contenir d'espace ! "
fi