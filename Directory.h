#ifndef __DIRECTORY_H__
#define __DIRECTORY_H__

#include "hash.h"
#include "Tree.h"

#define BOLD "\033[1m"
#define NO_BOLD "\033[22m"
#define RED "\033[31m"
#define GREEN "\033[32m"
<<<<<<< HEAD
#define MAGENTA "\033[35m"
=======
#define CYAN "\033[36m"
>>>>>>> 24b478ce873d912ff78b4c028bc6a89e63c0d3a2
#define RESET "\033[0m"

void AddFile(PtrNode current, PtrTree Tree, char *inputName);
void AddDirectory(PtrNode current, PtrTree Tree, char *inputName);

PtrNode search(PtrNode current, char *array);
PtrNode search2(PtrNode current, char *array);
PtrNode Move(PtrTree Tree, char *inputString);

PtrNode Teleport(PtrTree Tree, char *alias, HT **AliasHashTable);

void StoreAlias(PtrTree Tree, char *Address, char *Alias, HT **AliasHashTable);

void find(char STRING[], int n, char Array[][1000]);
void traverseTree(PtrNode root, char *prefix);

void Quit();

void printManual();

#endif
