/*
 Tree.h includes all the header files necessary, structures created,
 and the declarations for the functions used in Tree.c.
*/

#ifndef __TREE_H__
#define __TREE_H__

// Include all necesssary header files
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Give aliases to the structs and pointers 
typedef struct Node Node;
typedef struct Node *PtrNode;

typedef struct Tree Tree;
typedef struct Tree *PtrTree;

typedef struct ListNode ListNode;
typedef struct ListNode *PtrListNode;

// Structs used
struct ListNode
{
    char *name;
    ListNode *next;
    char *alias;
};

struct Node
{
    Node *Parent;
    char *name;
    char *Alias;
    Node *FirstChild;
    Node *Sibling;
    bool type;
};

struct Tree
{
    Node *root;
};

// Declarations of the functions in Tree.c
PtrListNode MakeList();
Node *MakeNode(Node *parentAddress, PtrTree root, char *inputString, bool inputType);
PtrTree MakeTree();

#endif