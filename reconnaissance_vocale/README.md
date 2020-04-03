
# RECONNAISSANCE
Pour la reconnaissance vocale nous avons utilisé le module "deepspeech" dévellopé par Mozilla.

# UTILISATION
Nous allons utilisé ce programme pour permettre à notre raspberry de comprendre les instructions données par l'utilisateur comme Alexa ou un Google Home.

# INSTALLATION DE DEEPSPEECH
Pour pouvoir reproduire le projet facilement nous avons fait un script permettant l'installation et l'initialisation de deepspeech sur le raspberry.
Le script se nomme "script_installation_deepspeech.sh".

# CREATION DU FICHIER TEXTE CONTENANT LES CHEMINS
Ce script permet de créer le fichier texte qui sera lu par l'application à son démarage pour l'initialisation des chemins. Il a pour nom "init_chemins.sh".

# FONCTION
Il y a deux fonctions c pour la reconnaissance vocale:
- "void init_recognition(void)" permet l'initialisation des chemins aux fichiers audios et aux fichiers models. Les chemins seront dans le fichier texte créé par le script "init_chemins.sh".
- "char * audio_recognition_function(char * nom_fic)" permet de renvoyer le résultat de la reconnaissance vocale et a comme parametre le nom du fichier audio à traiter.