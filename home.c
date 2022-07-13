// Created by:
//  Alessio Giacchè, Sofia Scattolini.
//


#include "homeProgram.h"


void homePrincipal() {
    int option;
    printf("Benvenuto nel programma.\n"
           "\tEcco la lista dei programmi che vuoi avviare: \n"
           "1) Programma per gestione directory.\n"
           "2) Programma per scrittura file.\n"
           "3) Programma per lettura file.\n"
           "4) Programma per creazione file/directory.\n"
           "5) Programma per rimozione file/directory.\n"
           "6) Terminare il programma.\n");

    scanf("%d", &option);
    system("clear");
    switch (option) {
        case 1:
            directoryHome();
            break;
        case 2:
            writeHome();
            break;
        case 3:
            readHome();
            break;
        case 4:
            createHome();
            break;
        case 5:
            removeHome();
            break;
        case 6:
            printf("Programma terminato.\nArrivederci.\n");
            return;
    }
}