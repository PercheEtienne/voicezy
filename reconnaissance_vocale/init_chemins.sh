# VARIABLE PAR DEFAUT
OUI="o"
RETOUR_CHARIOT=""
CHEMIN_AUDIO_PC=../speech/voices_sample/
CHEMIN_AUDIO_RPI=/home/pi/voicezy/deepspeech/voices_sample/
CHEMIN_MODEL_PC=../speech/models_fr/tensorflow/
CHEMIN_MODEL_RPI=/media/pi/RPI/tflite/

echo "----------DEBUT INITIALISATION DES CHEMINS-------------";

# LECTURE DU CHEMIN DU PROJET
echo -e "CHEMIN DU PROJET";

echo -e "\t-> ETES VOUS SUR PC OU RPI (par defaut RPI)\nReponse ('o' pour PC SINON RPI)";
read pc
if [ "$pc" != "$OUI" ]
then
	# FIC AUDIO
	echo -e "\nFICHIER AUDIO:";
	echo -e "\t-> veuillez entrer le chemin des FICHIERS AUDIOS (par default: $CHEMIN_AUDIO_RPI)\nappuyer sur entree si vous ne souhaitez pas changer le chemin par default)";
	read chemin
	if [ "$chemin" != "$RETOUR_CHARIOT" ]
	then
		CHEMIN_AUDIO=$chemin
	else
		CHEMIN_AUDIO=$CHEMIN_AUDIO_RPI
	fi

	# FIC MODEL
	echo -e "\nFICHIER MODEL:";
	echo -e "\t-> veuillez entrer le chemin des FICHIERS AUDIOS (par default: $CHEMIN_MODEL_RPI)\nappuyer sur entree si vous ne souhaitez pas changer le chemin par default)";
	read chemin
	if [ "$chemin" != "$RETOUR_CHARIOT" ]
	then
		CHEMIN_MODEL=$chemin
	else
		CHEMIN_MODEL=$CHEMIN_MODEL_RPI
	fi
	
	MODEL="RPI"
else
	# FIC AUDIO
	echo -e "\nFICHIER AUDIO:";
	echo -e "\t-> veuillez entrer le chemin des FICHIERS AUDIOS (par default: $CHEMIN_AUDIO_PC)\nappuyer sur entree si vous ne souhaitez pas changer le chemin par default)";
	read chemin
	if [ "$chemin" != "$RETOUR_CHARIOT" ]
	then
		CHEMIN_AUDIO=$chemin
	else
		CHEMIN_AUDIO=$CHEMIN_AUDIO_PC
	fi

	# FIC MODEL
	echo -e "\nFICHIER MODEL:";
	echo -e "\t-> veuillez entrer le chemin des FICHIERS AUDIOS (par default: $CHEMIN_MODEL_PC)\nappuyer sur entree si vous ne souhaitez pas changer le chemin par default)";
	read chemin
	if [ "$chemin" != "$RETOUR_CHARIOT" ]
	then
		CHEMIN_MODEL=$chemin
	else
		CHEMIN_MODEL=$CHEMIN_MODEL_PC
	fi

	MODEL="PC"
fi
echo -e "$CHEMIN_AUDIO" > Programme/.chemin_fic.txt;
echo -e "$CHEMIN_MODEL" >> Programme/.chemin_fic.txt;
echo -e "$MODEL" >> Programme/.chemin_fic.txt;
echo "appuyer sur entrée pour continuer...\n";
echo "FIN CHEMIN DU PROJET\n";
read a

echo "----------FIN INITIALISATION DES CHEMINS-------------";

