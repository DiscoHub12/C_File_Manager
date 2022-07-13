// Created by:
//  Alessio Giacchè, Sofia Scattolini.
//


#include "gestionWriteFile.h"


void writeFile() {
    char write[MAX_NAME_SZ];
    fflush(stdin);
    printf("Inserire la path del file e il nome:\n");
    questPath();
    char *path = questPath();

    FILE *file = fopen(path, "a+");
    if (checkFileExists(path) == 0) {
        printf("File inesistente.\nRitorno alla home.\n");
        writeHome();
    }
    printf("Inserisci il testo da scrivere nel file:\n");
    scanf("%[^\n]", write);
    fprintf(file, "%s \n", write);
    printf("Scrittura avvenuta con successo.\n");
    fclose(file);
    int o = returnHome();
    if (o == 1) { writeHome(); }

}


void writeNumber() {
    float number;
    fflush(stdin);
    printf("Inserire la path del file e il nome:\n");
    questPath();
    char *path = questPath();

    FILE *file = fopen(path, "a+");

    if (checkFileExists(path) == 0) {
        printf("File inesistente.\nRitorno alla home.\n");
        writeHome();
    }

    printf("Inserisci il numero da scrivere nel file:\n");
    scanf("%f", &number);
    fprintf(file, "%.2f \n", number);
    printf("Scrittura avvenuta con successo\n");
    fclose(file);

    int o = returnHome();
    if (o == 1) { writeHome(); }
}


void writeFileByPath(char path[MAX_PATH_SIZE]) {
    char write[200];
    FILE *file = fopen(path, "a+");
    if (checkFileExists(path) == 0) {
        printf("File inesistente.\nRitorno alla home.\n");
        writeHome();
    }
    printf("Inserisci il testo da scrivere nel file:\n");
    scanf("%[^\n]", write);
    fprintf(file, "%s \n", write);
    printf("Scrittura avvenuta con successo.\n");
    fclose(file);
    int o = returnHome();
    if (o == 1) { writeHome(); }
}


void writeHome() {
    int option;
    printf("\t--WRITE PROGRAMS--\n"
           "Elenco le azioni che puoi svolgere:\n"
           "1- Scrivi un testo all'interno del file.\n"
           "2- Scrivi un numero all'interno del file.\n"
           "3- Torna alla home.\n"
           "4- Termina il programma.\n");
    fflush(stdin);
    scanf("%d", &option);
    switch (option) {
        case 1:
            writeFile();
            break;
        case 2:
            writeNumber();
            break;
        case 3:
            homePrincipal();
            break;
        case 4:
            printf("Programma terminato.\nArrivederci.\n");
            exit(1);
    }
}
