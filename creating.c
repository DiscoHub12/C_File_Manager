// Created by:
//  Alessio Giacchè, Sofia Scattolini.
//


#include "gestionCreating.h"


void createFile(){
    fflush(stdin);
    printf("Inserisci la path dove vuoi salvare il nuovo file e il nome: \n");
    questPath();
    char *path = questPath();
    //controllo se il file è già esistente.
    if(checkFileExists(path) == 1){
        printf("File esistente. Ritorno alla home.\n");
        createHome();
    }

    //apro il file in modalità scrittura per crearlo.
    FILE *fp = fopen(path, "w");

    if(fp == NULL){
        printf("Errore durante la creazione. Ritorno alla home.\n");
        createHome();
    }
    printf("File creato con successo.\nPath completa:\n\t%s\n", path);
    fclose(fp);
    int o = returnHome();
    if(o == 1){createHome();}
}


void createDirectory(){
    fflush(stdin);
    printf("Inserisci la path dove vuoi salvare la nuova cartella e il nome:\n");
    questPath();
    char *path = questPath();

    if(checkDirExists(path) == 1){
        printf("Cartella gia' esistente. Ritorno alla home.\n");
        createHome();
    }

    //mkdir torna un intero: 0 o -1 a seconda che l'azione termini con successo o meno.
    int status = mkdir(path, S_IRWXU);

    printf("Cartella creata con successo. Path completa: \n\t%s\n", path);
    int o = returnHome();
    if(o == 1){createHome();}
}


void createHome(){
    int option;
    printf("\t--CREATING PROGRAMS--\n"
           "Elenco le azioni che puoi svolgere:\n"
           "1- Crea un file.\n"
           "2- Crea una cartella.\n"
           "3- Ritorna alla home principale.\n"
           "4- Termina il programma.\n");
    fflush(stdin);
    scanf("%d", &option);
    switch (option) {
        case 1:
            createFile();
            break;
        case 2:
            createDirectory();
            break;
        case 3:
            homePrincipal();
            break;
        case 4:
            printf("Programma terminato.\nArrivederci.\n");
            exit(1);
    }
}