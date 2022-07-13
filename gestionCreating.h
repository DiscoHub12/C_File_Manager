// Created by:
//  Alessio Giacchè, Sofia Scattolini.
//



#ifndef C_FILE_GESTION_SO_GESTIONCREATING_H
#define C_FILE_GESTION_SO_GESTIONCREATING_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "utilities.h"
#include "homeProgram.h"


/**
 * Questo metodo permette di creare
 * un file all'interno nostro SO.
 * Durante l'esecuzione, ci verrà
 * chiesto come chiamare il file
 * e dove salvarlo.
 */
void createFile();


/**
 * Questo metodo permette di creare
 * una cartella all'interno del nostro SO.
 * Durante l'esecuzione, ci verrà
 * chiesto come chiamare la cartella e
 * dove salvarla.
 */
void createDirectory();


/**
 * Questo metodo è fondamentale
 * poichè è la home del programma
 * che gestisce la creazione di
 * file o directory.
 *
 */
void createHome();



#endif //C_FILE_GESTION_SO_GESTIONCREATING_H
