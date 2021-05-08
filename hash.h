#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int n;
    struct node *next;

} HT;
typedef struct Node2
{
    char Address[330];
    int n;
    struct Node2 *next;
    char *Alias;

} HT2;

HT2 **MakeHashTable();

int hornersRuleHash(int n, char *word);
void insertSep2(char Address[], HT2 **hashtable, char *Alias);
char* searchSepAlias(char x[], HT2 **hashtable);

#endif
