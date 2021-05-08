#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char Address[10000];
    int n;
    struct node *next;
    char *Alias;

} HT;

HT **MakeHashTable();

int hornersRuleHash(int n, char *word);
void insertSep(char Address[], HT **hashtable, char *Alias);
char *searchSepAlias(char x[], HT **hashtable);

#endif
