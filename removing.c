// Created by:
//  Alessio Giacchè, Sofia Scattolini.
//


#include "gestionRemoving.h"


void removeFile(){
    fflush(stdin);
    printf("Inserisci la path dove si trova il file e il nome:\n");
    questPath();
    char *path = questPath();

    //controllo se il file esiste.
    if(checkFileExists(path) == 0){
        printf("File inesistente. Ritorno alla home.\n");
        removeHome();
    }
    //richiamo la funzione remove per rimuovere il file: ritorna 0 o -1 in caso successo o insuccesso.
    int rm = remove(path);
    printf("File rimosso con successo.\n");
    int o = returnHome();
    if(o == 1){removeHome();}
}


void removeFileByPath(char fullPath[MAX_PATH_SIZE]){
    //controllo se il file esiste.
    if(checkFileExists(fullPath) == 0){
        printf("File inesistente. Ritorno alla home.\n");
        removeHome();
    }

    int rm = remove(fullPath);
    printf("File rimosso con successo.\n");
    int o = returnHome();
    if(o == 1){removeHome();}
}


void removeDirectory(){
    fflush(stdin);
    printf("Inserisci la path dove si trova la cartella e il nome:\n");
    questPath();
    char *path = questPath();

    //controllo se la cartella esiste.
    if(checkDirExists(path) == 0){
        printf("Cartella inesistente. Ritorno alla home.\n");
        removeHome();
    }
    //controllo se la cartella è vuota al suo interno.
    if(checkDirEmpty(path) == 0){
        //se non è vuota, richiamo il metodo esterno in utilities.c
        checkDirEmptRemove(path);
    }
    //richiamo la funzione rmdir per rimuovere una cartella: ritorna 0 o -1 in caso successo o insuccesso.
    int rm;
    rm = rmdir(path);
    printf("Cartella rimossa con successo.\n");
    int o = returnHome();
    if(o == 1){removeHome();}
}


void removeDirectoryByPath(char fullPath[MAX_PATH_SIZE]){
    //controllo se la cartella esiste.
    if(checkDirExists(fullPath) == 0){
        printf("Cartella inesistente. Ritorno alla home.\n");
        removeHome();
    }
    //controllo se la cartella è vuota al suo interno.
    if(checkDirEmpty(fullPath) == 0){
        checkDirEmptRemove(fullPath);
    }
    //richiamo la funzione rmdir per rimuovere una cartella: ritorna 0 o -1 in caso successo o insuccesso.
    int rm = rmdir(fullPath);
    printf("Cartella rimossa con successo.\n");
    int o = returnHome();
    if(o == 1){removeHome();}
}


void removeHome(){
    int option;
    printf("\t--REMOVE PROGRAMS--\n"
           "Elenco le azioni che puoi svolgere:\n"
           "1- Rimuovi un file.\n"
           "2- Rimuovi una cartella.\n"
           "3- Ritorna alla home principale.\n"
           "4- Termina il programma.\n");
    fflush(stdin);
    scanf("%d", &option);
    switch (option) {
        case 1:
            removeFile();
            break;
        case 2:
            removeDirectory();
            break;
        case 3:
            homePrincipal();
            break;
        case 4:
            printf("Programma terminato.\nArrivederci.\n");
            exit(1);
    }
}