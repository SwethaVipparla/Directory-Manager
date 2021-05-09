/*
 hash.h includes all the header files necessary, structures created,
 and the declarations for the functions used in hash.c.
*/

#ifndef __HASH_H__
#define __HASH_H__

// Include necessary header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for hashtable
typedef struct node
{
    char Address[10000];
    int n;
    struct node *next;
    char *Alias;

} HT;

// Declarations of the functions used in Hash.h
HT **MakeHashTable();

int hornersRuleHash(int n, char *word);
void insertSep(char Address[], HT **hashtable, char *Alias);
char *searchSepAlias(char x[], HT **hashtable);

#endif
