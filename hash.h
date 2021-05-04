#ifndef __HASH_
#define __HASH_

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
    char Address[33];
    int n;
    struct Node2 *next;
    char* Alias;

} HT2;

typedef struct Node3
{
    char* Name_of_string;
    //struct Node3* Next;

} HT3;
int hornersRuleHash(int n, char* word);
void insertSep(int x, int tablesize, HT *hashtable[]);
void insertSep2(char Address[], HT2 *hashtable[],char* Alias);
char* searchSepAlias(char x[], HT2 *hashtable[]);
void insertsep3(char* name, HT3 *hash_for_find[]);
int searchSep(int x, int tablesize, HT *hashtable[]);
int searchSep2(char x[], HT2 *hashtable[]);

#endif