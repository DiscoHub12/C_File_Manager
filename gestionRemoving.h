// Created by:
//  Alessio Giacchè, Sofia Scattolini.
//

#ifndef C_FILE_GESTION_SO_GESTIONREMOVING_H
#define C_FILE_GESTION_SO_GESTIONREMOVING_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "utilities.h"
#include "homeProgram.h"


/**
 * Questo metodo permette
 * di rimuovere uno specifico file
 * che verrà richiesto durante l'esecuzine
 * del programma ,all'interno del nostro SO.
 */
void removeFile();


/**
 * Questo metodo permette di rimuvere
 * un file, passato tramite parametro
 * (la sua directory completa)
 * @param fullPath directory file.
 */
void removeFileByPath(char fullPath[MAX_PATH_SIZE]);


/**
 * Questo metodo permette di rimuovere
 * una specifica directory che verrà richiesta
 * durante l'esecuzione del programma , all'interno
 * del nostro SO.
 */
void removeDirectory();


/**
 * Questo metodo permette di rimuovere
 * la directory passata tramite parametri.
 * @param fullPath directory.
 */
void removeDirectoryByPath(char fullPath[MAX_PATH_SIZE]);


/**
 * Questo metodo è fondamentale
 * poichè è la home del programma
 * che gestisce la rimozione
 * di file o di directory.
 *
 */
void removeHome();


#endif //C_FILE_GESTION_SO_GESTIONREMOVING_H
