#ifndef __DIRECTORY_H__
#define __DIRECTORY_H__

#include "hash.h"
#include "Tree.h"

#define BOLD "\033[1m"
#define NO_BOLD "\033[22m"
#define RED "\u001b[31m"
#define GREEN "\u001b[32m"
#define MAGENTA "\u001b[35m"
#define RESET "\u001b[0m"

void AddFile(PtrNode current, PtrTree Tree, char *inputName);
void AddDirectory(PtrNode current, PtrTree Tree, char *inputName);

PtrNode search(PtrNode current, char *array);
PtrNode Move(PtrTree Tree, char *inputString);

PtrNode Teleport(PtrTree Tree, char *alias, HT2 **AliasHashTable);

void StoreAlias(PtrTree Tree, char *Address, char *Alias, HT2 **AliasHashTable);

void find(char STRING[], int n, char Array[][1000]);
void traverseTree(PtrNode root, char *prefix);

void Quit();

void printManual();

#endif
