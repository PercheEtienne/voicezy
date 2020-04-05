#ifndef PROJET_DEEPSPEECH_FUNCTION_H

    #define PROJET_DEEPSPEECH_FUNCTION_H

    // CHEMIN DES FICHIERS

    #define CHEMIN_TFLITE "/media/pi/RPI/tflite/"
    #define CHEMIN_TENSORFLOW "../speech/models_fr/tensorflow/"
    #define CHEMIN_AUDIO_PC "../speech/voices_sample/"
    #define CHEMIN_AUDIO_RPI "/home/pi/voicezy/deepspeech/voices_sample/"

    // NOM FIC PAR DEFAULT

    #define MODEL_RPI "output_graph.tflite"
    #define MODEL_PC "output_graph.pbmm"
    #define LM "lm.binary"
    #define TRIE "trie"
    #define AUDIO "Test"

    // VAR MAX

    #define TAILLE_MAX 200
    #define TAILLE_MAX_CHEMIN 200

    // VARIABLE GLOBALE

    char chemin_audio[200];
    char chemin_model[200];
    char model[30];

    // SQUELETTE DE FONCTION

    void init_recognition(void);
    void test_fic_audio(char * nom);
    char * audio_recognition_function(char *);

#endif //PROJET_DEEPSPEECH_FUNCTION_H
