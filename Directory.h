#ifndef __DIRECTORY__H
#define __DIRECTORY__H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "hash.h"

typedef struct Node Node;
typedef struct Node* PtrNode;

typedef struct Tree Tree;
typedef struct Tree* PtrTree;

typedef struct ListNode ListNode;
typedef struct ListNode* PtrListNode;

typedef struct HashTable HashTable;
typedef struct HashTable* PtrTable;

struct ListNode
{
    char* name;
    ListNode* next;
    char* alias;
};

struct Node
{
    Node* Parent;
    char* name;
    char* Alias;
    Node* FirstChild;
    Node* Sibling; 
    bool type;
    //PtrListNode Children;
};
struct Tree
{
    Node* root;
};

PtrListNode MakeList();
PtrListNode MakeList();
PtrTable MakeTable();

Node* MakeNode(Node* parentAddress, PtrTree root, char *inputString, bool inputType);
PtrTree MakeTree();

PtrNode Find(char* Prefix);

void AddFile(PtrNode current, PtrTree root, char* inputName);
void AddDirectory(PtrNode current, PtrTree root, char* inputName);

PtrNode search(PtrNode current, char *array);
PtrNode Move(PtrTree root, PtrNode inputString);

int getHash(char* inputString);
int LookinTable(char* inputString, PtrTable Table);
HT2** MakeHashTable();

PtrNode Teleport(PtrTree Tree , char* alias, HT2** AliasHashTable);
PtrNode TeleportSafety(char* alias, PtrTree root);

void StoreAlias(PtrTree Tree, char* Address, char* Alias, HT2** AliasHashTable);
void StoreAliasSafety(PtrTree root, char* Address, char* Alias);

void Quit();

#endif