// Created by:
//  Alessio Giacchè, Sofia Scattolini.
//


#ifndef C_FILE_GESTION_SO_UTILITIES_H
#define C_FILE_GESTION_SO_UTILITIES_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>


#define MAX_NAME_SZ 256
#define MAX_PATH_SIZE 120
#define MAX_LINE_FILE 256


/**
 * Questo metodo permette di controllare
 * se il fle passato tramite parametri
 * esiste. (tutta la directory)
 * @param fullPath la directory del file.
 *
 */
int checkFileExists(char fullPath [MAX_PATH_SIZE]);


/**
 * Questo metodo permette di controllare
 * se la cartella passata come parametri
 * esiste. (tutta la directory)
 * @param fullPathFolder la directory della cartella.
 * @return
 */
int checkDirExists(char fullPathFolder[MAX_PATH_SIZE]);


/**
 * Questo metodo permette di controllare
 * se la cartella passata come parametri
 * è vuota o no. (tutta la directory)
 * @param fullPath la directory della cartella.
 * @return
 */
int checkDirEmpty(char fullPath[MAX_PATH_SIZE]);


/**
 * Questo metodo permette di fare
 * determinati passaggi, al fine di eliminare una
 * data cartella (non vuota). Quindi permette di eliminare
 * file all'interno di essa tramite chiamate a metodi
 * esterni.
 *
 */
void checkDirEmptRemove(char fullPath[MAX_PATH_SIZE]);


/**
 *
 * @return
 */
char *questPath();


/**
 * Metodo che mi permette di chiedere all'
 * utente la scelta di ritornare alla home.
 * @return
 */
int returnHome();


#endif //C_FILE_GESTION_SO_UTILITIES_H
