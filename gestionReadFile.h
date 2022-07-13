// Created by:
//  Alessio Giacchè, Sofia Scattolini.
//

#ifndef C_FILE_GESTION_SO_GESTIONREADFILE_H
#define C_FILE_GESTION_SO_GESTIONREADFILE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include "utilities.h"
#include "homeProgram.h"


/**
 * Questo metodo permette di leggere
 * un file di testo che verrà chiesto
 * all'utente durante l'esecuzione.
 *
 */
void readFile();


/**
* Questo metodo permette di leggere un file
 * che viene passato tramite argomenti
 * dalla sua path.
 * @param fullPath la directory del file.
 *
 */
void readFileByPath(char fullPath[MAX_PATH_SIZE]);


/**
 * Questo metodo permette di cercare
 * una stringa all'interno di un file
 * di testo.(che verrà chiesto all'
 * utente dutante l'esecuzione).
 */
int searchInsideFile();


/**
 * Questo metodo è il programma
 * principale della gestione della
 * lettura file. Permette di far
 * scegliere all'utente le diverse
 * azioni che si possono eseguire.
 * Gestisce tutti i metodi riguardo
 * la lettura file.
*/
void readHome();


#endif //C_FILE_GESTION_SO_GESTIONREADFILE_H
