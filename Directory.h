/*
 Directory.h includes all the header files necessary, structures created,
 and the declarations for the functions used in Directory.c.
*/

#ifndef __DIRECTORY_H__
#define __DIRECTORY_H__

// Include necessary header files
#include "hash.h"
#include "Tree.h"

// Create macros for the ANSI colour codes used throughout the codebase
#define BOLD "\033[1m"
#define NO_BOLD "\033[22m"
#define RED "\033[38;5;1m"
#define GREEN "\033[38;5;121m"
#define ORANGE "\033[38;5;209m"
#define PURPLE "\033[38;5;205m"
#define LIGHT_PINK "\033[38;5;225m"
#define LIGHT_PURPLE "\033[38;5;213m"
#define YELLOW "\033[38;5;223m"
#define RESET "\033[0m"

// Declarations of the functions used in Directory.c
void addFile(PtrNode current, PtrTree Tree, char *inputName);
void addDirectory(PtrNode current, PtrTree Tree, char *inputName);

PtrNode search(PtrNode current, char *array);
PtrNode search2(PtrNode current, char *array);
PtrNode move(PtrTree Tree, char *inputString);

PtrNode teleport(PtrTree Tree, char *alias, HT **AliasHashTable);

void storeAlias(PtrTree Tree, char *Address, char *Alias, HT **AliasHashTable);

void managerFind(char STRING[], int n, char Array[][1000]);
void directoryFind(PtrNode root, char *prefix);
void ls(PtrNode root);

void quit();

void printManual();

#endif
