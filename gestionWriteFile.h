// Created by:
//  Alessio Giacchè, Sofia Scattolini.
//


#ifndef C_FILE_GESTION_SO_GESTIONWRITEFILE_H
#define C_FILE_GESTION_SO_GESTIONWRITEFILE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "utilities.h"
#include "homeProgram.h"


/**
 * Questo metodo permette di
 * scrivere all'interno di un dato file.
 * Il file (directory) e il tipo da scrivere al suo
 * interno verrà chiesto durante
 * la sua esecuzione.
 *
 */
void writeFile();


/**
 * Questo metodo permette di inserire
 * all'interno di un dato file di testo,
 * un numero.
 * Solitamente chiamato all'interno del
 * vero metodo di scrittura.
 *
 */
void writeNumber();


/**
 * Questo metodo permette di scrivere
 * in un file di testo a scelta,
 * ma a differenza nel principale,
 * bisogna passare fin da subito
 * la sua directory.
 * @param path la directory del file.
 *
 */
void writeFileByPath(char path[MAX_PATH_SIZE]);


/**
 * Questo metodo è fondamentale
 * poichè gestisce il programma che
 * si occupa di scrivere all'interno
 * di determinati file.
 *
 */
void writeHome();


#endif //C_FILE_GESTION_SO_GESTIONWRITEFILE_H
