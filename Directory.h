#ifndef __DIRECTORY_H__
#define __DIRECTORY_H__

#include "hash.h"
#include "Tree.h"

#define BOLD "\033[1m"
#define NO_BOLD "\033[22m"
#define RED "\033[38;5;1m"
#define GREEN "\033[38;5;121m"
#define CYAN "\033[36m"
#define PURPLE "\033[38;5;199m"
#define LIGHT_PINK "\033[38;5;225m"
#define LIGHT_PURPLE "\033[38;5;213m"
#define YELLOW "\033[38;5;223m"
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
void ls(PtrNode root);

void Quit();

void printManual();

#endif
