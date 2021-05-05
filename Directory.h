#ifndef __DIRECTORY__H
#define __DIRECTORY__H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
    Node* FirstChild;
    Node* Sibling; 
    bool type;
    //PtrListNode Children;
};

// struct TreeNode
// {
//     TreeNode* Parent;
//     char *name;
//     PtrListNode Children;
//     bool type;
// };


struct Tree
{
    Node* root;
};

struct HashTable
{
};

PtrListNode MakeList();
PtrListNode MakeList();
PtrTable MakeTable();
Node* MakeNode(Node* parentAddress ,PtrTree Tree, char *inputString , bool inputType);
PtrTree MakeTree();

PtrNode Find(char* Prefix);
PtrNode search(PtrNode current, char *array);

void AddFile(PtrNode current, PtrTree Tree, char *inputString);
void AddDirectory(PtrNode current, PtrTree Tree, char* inputString);

PtrNode Move(PtrTree Tree,char* inputString);

int getHash(char* inputString);
int LookinTable(char* inputString, PtrTable Table);

PtrNode Teleport(char* alias);
void StoreAlias(char* Address, char* Alias);

void Quit();

#endif