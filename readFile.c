// Created by:
//  Alessio Giacchè, Sofia Scattolini.
//


#include "gestionReadFile.h"


void readFile() {
    char rigaFile[MAX_LINE_FILE];
    fflush(stdin);
    printf("Inserire la path del file e il nome:\n");
    questPath();
    char *path = questPath();

    FILE *file = fopen(path, "r");
    //controllo se il file esiste.
    if (checkFileExists(path) == 0) {
        printf("File non esistente.\nRitorno alla home.\n");
        readHome();
    }
    char *res;
    while (1) {
        res = fgets(rigaFile, 200, file);
        if (res == NULL) {
            break;
        }
        //stampa il suo contenuto.
        printf("%s", rigaFile);
    }
    printf("File letto correttamente\n");
    fclose(file);

    int o = returnHome();
    if (o == 1) { readHome(); }
}


void readFileByPath(char fullPath[MAX_PATH_SIZE]) {
    FILE *file = fopen(fullPath, "r");
    char rigaFile[100];

    if (checkFileExists(fullPath) == 0) {
        printf("File inesistente. Ritorno alla home.\n");
        readHome();
    }
    while (!feof(file)) {
        fscanf(file, "%s", rigaFile);
        printf("%s\n", rigaFile);
    }
    printf("File letto correttamente\n");
    fclose(file);
    int o = returnHome();
    if (o == 1) { readHome(); }
}


int searchInsideFile() {
    char rigaFile[MAX_LINE_FILE], parola[MAX_NAME_SZ];
    int n = 0;
    fflush(stdin);
    printf("Inserire la path del file e il nome:\n");
    questPath();
    char *path = questPath();

    FILE *file = fopen(path, "r");

    if (checkFileExists(path) == 0) {
        printf("File non esistente.\nRitorno alla home.\n");
        readHome();
    }
    printf("Inserisci la parola che vuoi cercare: \n");
    scanf("%s", parola);

    while(fscanf(file, "%s", rigaFile) == 1){ // == 1 se è in grado di scansionare una stringa.
        if(strstr(rigaFile, parola) != 0){
            n++;
        }
    }
    printf("Ho trovato la parola : [%s] nel file [%d] volte.\n", parola, n);
    n = 0;
    fclose(file);
    int o = returnHome();
    if (o == 1) { readHome(); }
    return 0;
}


void readHome() {
    int option;
    printf("\t--READ PROGRAMS--\n"
           "Elenco le azioni che puoi svolgere:\n"
           "1- Leggi all'interno del file.\n"
           "2- Cerca una parola all'interno del file.\n"
           "3- Torna alla home\n"
           "4- Termina il programma.\n");
    fflush(stdin);
    scanf("%d", &option);
    switch (option) {
        case 1:
            readFile();
            break;
        case 2:
            searchInsideFile();
            break;
        case 3:
            homePrincipal();
            break;
        case 4:
            printf("Programma terminato.\nArrivederci.\n");
            exit(1);
    }
}