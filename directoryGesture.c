// Created by:
//  Alessio Giacchè, Sofia Scattolini.
//


#include "gestionDirectory.h"


void showContent() {
    fflush(stdin);
    printf("Inserici la path e il nome della cartella: \n");
    questPath();
    char *directory = questPath();
    printf("Hai scelto questa directory: \n\t%s\n", directory);

    DIR *dir;
    struct dirent *entry;
    int number = 0;

    dir = opendir(directory);
    //controllo se la cartella è già esistente.
    if(checkDirExists(directory) == 0){
        printf("Cartella inesistente. Ritorno alla home.\n");
        directoryHome();
    }

    if (dir == NULL) {
        printf("Directory nulla. Ritorno alla home.\n");
        directoryHome();
    }
    printf("Elenco il contenuto della cartella scelta: \n");

    //puntatore alla directory, incremento il contatore per la stampa.
    while ((entry = readdir(dir))) {
        number++;
        printf("File %2d:\t%s\n", number, entry->d_name);
    }

    printf("Contenuti stampati.\n");

    closedir(dir);
    int o = returnHome();
    if (o == 1) {directoryHome();}
}


void changeDirectory() {
    int optionOne;
    fflush(stdin);
    printf("Inserisci la path e il nome della cartella su cui spostarti.\n");
    questPath();
    char *directory = questPath();
    printf("Ti sei spostato nella seguente directory: \t\n%s\n", directory);
    printf("Inserisci: \n"
           "1) Vedi il suo contenuto.\n"
           "2) Ritorna alla home.\n");

    scanf("%d", &optionOne);

    if (optionOne == 1) {
        printf("Elenco il contenuto della cartella scelta: \n");
        showContentByPath(directory);
    }else if(optionOne == 2){
        directoryHome();
    }
    int o = returnHome();
    if (o == 1) {
        directoryHome();
    }
}


void showContentByPath(char path[MAX_PATH_SIZE]) {
    DIR *dir;
    struct dirent *entry;
    int number = 0;

    dir = opendir(path);

    if(checkDirExists(path) == 0){
        printf("Cartella inesistente. Ritorno alla home.\n");
        directoryHome();
    }

    if (dir == NULL) {
        printf("Directory nulla. Ritorno alla home.\n");
        directoryHome();
    }
    while ((entry = readdir(dir))) {
        number++;
        printf("File %2d:\t%s\n", number, entry->d_name);
    }
    closedir(dir);
}


void directoryHome() {
    int option;

    printf("\t--DIRECTORY PROGRAM--\n"
           "Elenco le azioni che puoi svolgere:\n"
           "1- Leggi il contenuto di una directory.\n"
           "2- Cambia directory.\n"
           "3- Ritorna alla home principale.\n"
           "4- Termina il programma.\n");
    scanf("%d", &option);
    switch (option) {
        case 1:
            showContent();
            break;
        case 2:
            changeDirectory();
            break;
        case 3:
            homePrincipal();
            break;
        case 4:
            printf("Programma terminato.\nArrivederci.\n");
            exit(1);
    }
}
