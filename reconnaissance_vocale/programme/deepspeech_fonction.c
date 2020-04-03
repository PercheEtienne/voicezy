//
// Created by pilou on 31/03/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "deepspeech_fonction.h"

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int main(int argc, char *argv[]){
    short RPI; // 1 si sur RPI, si SUR PC
    char validation;
    char nom_ficAudio[20];

    /*
    printf("Argc: %d",argc);
    if(argc!=2){
        printf("Veuillez saisir le nom de votre fichier audio: ");scanf("%s",nom_ficAudio);
    } else{
        strcpy(nom_ficAudio,argv[1]);
    }
    */

    init_recognition();

    printf("\n\nLES CHEMINS SONT LES SUIVANTS:\n");
    printf("\tFICHIER MODEL: %s\n",chemin_model);
    printf("\tFICHIER AUDIO: %s\n",chemin_audio);
    printf("\n\nLE MODEL EST LE SUIVANT: %s\n\n\n\n",model);

    test_fic_audio("Eteint");
    test_fic_audio("Allume");
    test_fic_audio("Temperature");
    test_fic_audio("Luminosite");
    test_fic_audio("Meteo");
    test_fic_audio("Humidite");

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
    sprintf(commande,"deepspeech --model %s%s --lm %s%s --trie %s%s --audio %s%s > rep.txt 2> .stdout_Deepspeech.txt",
            chemin_model,model,chemin_model,LM,chemin_model,TRIE,chemin_audio,fic_audio);
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
    for(short i=0; i<20 ; i++){
        sprintf(nomA,"%s%hd.wav",nom,i);
        printf("\n\n\n Nom fichier: %s\n",nomA);
        resultat = audio_recognition_function(nomA);
        resultat[strlen(resultat)-1]='\0';
        printf("RESULTAT %hd: \033[0;31m%s \n",i,resultat);printf("\033[0;m");
        sprintf(commande,"echo \"%s\" >> ../Reconnaissance2/reconnaissance%s.txt",resultat,nom);
        system(commande);
    }

}