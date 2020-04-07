//
// Created by pilou on 31/03/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "deepspeech.h"

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

/*int main(){
    short RPI; // 1 si sur RPI, si SUR PC
    char validation;
    char nom_ficAudio[20];
    char commande[1000];


    init_recognition();

    sprintf(commande,"arecord -f S16_LE -r16000 -t wav -D plughw:1,0 ../../Audio/record.wav");
    system(commande);

    printf("\n\n\nLe résultat obtenu est: %d\n",recherche_Ordre(audio_recognition_function("record.wav")));

    return 0;
}*/

int recherche_Ordre(char *string) {
    printf("\n\nResultat obtenu: %s\n",string);
    if ((strstr(string, "weather") != NULL) || (strstr(string, "whether") != NULL) ||
        (strstr(string, "whither") != NULL) || (strstr(string, "wither") != NULL) || (strstr(string, "with her") != NULL) || (strstr(string, "wiser") != NULL))
        return 1;
    else if ((strstr(string, "bright") != NULL) || (strstr(string, "luminosity") != NULL) || (strstr(string, "luminous") != NULL))
        return 2;
    else if ((strstr(string, "temperature") != NULL))
        return 3;
    else if ((strstr(string, "light") != NULL) || (strstr(string, "late") != NULL)){
        if ((strstr(string, "on") != NULL))
            return 4;
        return 5;
    }
    else if( (strstr(string,"humidity")!=NULL) || (strstr(string,"humility")!=NULL) || (strstr(string,"heredity")!=NULL))
        return 6;
     else if( (strstr(string,"play")!=NULL) || (strstr(string,"song")!=NULL) )
        return 7;
    return 0;
}

void init_recognition(void){
    short n = 0;
    FILE *fic1 = NULL;
    char lecture[TAILLE_MAX_CHEMIN];

    fic1 = fopen(".chemin_fic.txt","r");
    if(fic1 != NULL){
        while(fgets(lecture, TAILLE_MAX_CHEMIN, fic1) != NULL){
            //printf("%hd: %s",n,lecture);
            if(n==0)
                strcpy(chemin_audio,lecture);
            else if (n==1)
                strcpy(chemin_model,lecture);
            else if (n == 2){
                if(strcmp(lecture,"RPI\n")==0)
                    strcpy(model,MODEL_RPI);
                else
                    strcpy(model,MODEL_PC);
            }
            n++;
        }
        chemin_audio[strlen(chemin_audio)-1]='\0';
        chemin_model[strlen(chemin_model)-1]='\0';
        fclose(fic1);
    }
}

char * audio_recognition_function(char *fic_audio){
    FILE *fic = NULL;
    char commande[1000];
    char *reponse;
    char lecture[TAILLE_MAX];

    reponse = malloc(TAILLE_MAX * sizeof(char));

    system("touch rep.txt");
    sprintf(commande,"deepspeech --model /media/pi/RPI/tflite/output_graph.tflite --lm /media/pi/RPI/tflite/lm.binary --trie /media/pi/RPI/tflite/trie --audio enregistrement.wav  > rep.txt 2> .stdout_Deepspeech.txt");
    //printf ("COMMMANDE: %s\n\n",commande);
    system(commande);


    fic = fopen("rep.txt","r");
    if(fic != NULL){
        while(fgets(lecture, TAILLE_MAX, fic) != NULL){
            strcpy(reponse,lecture);
        }
        fclose(fic);
        system("rm rep.txt");
        return reponse;
    }
    return "une erreur s'est produit";
}

void test_fic_audio(char * nom){
    char commande[1000];
    char nomA[50];

    char * resultat;

    sprintf(commande,"echo -n \"\" > ../Reconnaissance2/reconnaissance%s.txt",nom);
    system(commande);
    sprintf(nomA,"../%s/",nom);
    strcpy(chemin_audio,nomA);
    short i;
    for(i=0; i<20 ; i++){
        sprintf(nomA,"%s%hd.wav",nom,i);
        printf("\n\n\n Nom fichier: %s\n",nomA);
        resultat = audio_recognition_function(nomA);
        resultat[strlen(resultat)-1]='\0';
        printf("RESULTAT %hd: \033[0;31m%s \n",i,resultat);printf("\033[0;m");
        sprintf(commande,"echo \"%s\" >> ../Reconnaissance2/reconnaissance%s.txt",resultat,nom);
        system(commande);
    }

}
