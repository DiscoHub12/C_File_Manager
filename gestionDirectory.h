// Created by:
//  Alessio Giacchè, Sofia Scattolini.
//


#ifndef C_FILE_GESTION_SO_GESTIONDIRECTORY_H
#define C_FILE_GESTION_SO_GESTIONDIRECTORY_H


#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include "utilities.h"
#include "homeProgram.h"


/**
 * Questo metodo permette di
 * vedere il contenuto di una
 * specifica cartella , che verrà
 * richiesta durante l'esecuzione.
 *
 */
void showContent();


/**
 * Questo metodo permette di
 * cambiare directory, facendo eventuali
 * controlli, con la possibilità di
 * vederne il contenuto o di
 * terminare il programma.
 *
 */
void changeDirectory();


/**
 * Questo metodo permette di mostrare
 * il conenuto di una determinata directory
 * che viene passata tramite parametri.
 * @param path la path da passare al metodo.
 *
 */
void showContentByPath(char path[MAX_PATH_SIZE]);


/**
 * Questo metodo è il programma
 * principale della gestione
 * delle directory. Permette di
 * scegliere tra le varie azioni
 * che si posso fare, e gestisce
 * tutti gli altri metodi.
 *
 */
void directoryHome();

#endif //C_FILE_GESTION_SO_GESTIONDIRECTORY_H
