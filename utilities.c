// Created by:
//  Alessio Giacchè, Sofia Scattolini.
//


#include "utilities.h"
#include "gestionDirectory.h"


int checkFileExists(char fullPath[MAX_PATH_SIZE]) {
    FILE *file;
    //apro il file in modalità lettura, se esiste ritorna 1.
    if ((file = fopen(fullPath, "r"))) {
        fclose(file);
        return 1;
    } else if (ENOENT == errno) {
        return 0;
    }
}


int checkDirExists(char fullPathDirect[MAX_PATH_SIZE]) {
    DIR *dir = opendir(fullPathDirect);
    //apro la cartella, se esiste ritorna 1.
    if (dir) {
        closedir(dir);
        return 1;
    } else if (ENOENT == errno) {
        //cartella non esistente.
        return 0;
    }
}


int checkDirEmpty(char fullPath[MAX_PATH_SIZE]) {
    int n = 0;
    struct dirent *d;
    DIR *dir = opendir(fullPath);

    if (dir == NULL) { //controlla se è nulla.
        return 1;
    }
    //conta i file al suo interno tramite un contatore.
    while ((d = readdir(dir)) != NULL) {
        if (n++ > 2) {
            break;
        }
    }
    closedir(dir);
    //controllo il contatore, se è < 2 è vuota e ritorna 1, altrimenti 0.
    if (n <= 2) {
        return 1; //directory vuota.
    } else {
        return 0; //directory non vuota.
    }
}


void checkDirEmptRemove(char fullPath[MAX_PATH_SIZE]) {
    if (checkDirEmpty(fullPath) == 0) {
        char nameFile[MAX_NAME_SZ], nameFolder[MAX_NAME_SZ];
        int o;
        printf("La cartella non è vuota. Mostro il suo contenuto: \n");
        showContentByPath(fullPath);
        printf("Inserisci:\n"
               "1- Elimina i file al suo interno.\n"
               "2- Elimina cartella al suo interno.\n"
               "3- Ritorna alla home.\n");
        scanf("%d", &o);

        switch (o) {
            case 1:
                printf("Inserisci il nome del file al suo interno che vuoi eliminare (ricordati la / prima del nome): \n");
                scanf("%s", nameFile);
                strcat(fullPath, nameFile); //funzione per concatnare 2 stringe, la path e il nome del file.
                int rm = remove(fullPath);
                printf("Il file è stato rimosso. Rilancio il metodo.\n");
                removeDirectory();
                break;
            case 2:
                printf("Inserisci il nome della cartella che vuoi eliminare (ricordati la / prima del nome): \n");
                scanf("%s", nameFolder);
                strcat(fullPath, nameFolder); //funzione per concatnare 2 stringe, la path e il nome della cartella.
                int s = rmdir(fullPath);
                printf("Cartella rimossa con successo. Rilancio il metodo.\n");
                removeDirectory();
                break;
            case 3:
                removeHome();
                break;
        }
    }
}


char *questPath() {
    fflush(stdin);
    //malloc associa dinamicamente la memoria di size <MAX_NAME_SZ>.
    char *path = malloc(MAX_NAME_SZ);

    if (path == NULL) {
        printf("Nessuna memoria.\n");
        returnHome();
    }
    //utilizzo la funzione fgets per associare l'input a path.
    fgets(path, MAX_NAME_SZ, stdin);

    //controllo la lunghezza se > 0 o se la lunghezza -1 è la fine della stringa, in caso gli assegno
    // \0 che serve per indicare la terminazione della stringa.
    if ((strlen(path) > 0) && (path[strlen(path) - 1] == '\n')) {
        path[strlen(path) - 1] = '\0';
    }
    return path;
}


int returnHome() {
    int o;
    fflush(stdin);
    printf("Inserisci: \n"
           "1 = Torna alla home di questo programma.\n");
    scanf("%d", &o);
}
