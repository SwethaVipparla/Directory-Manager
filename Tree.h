#ifndef __TREE_H__
#define __TREE_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node Node;
typedef struct Node *PtrNode;

typedef struct Tree Tree;
typedef struct Tree *PtrTree;

typedef struct ListNode ListNode;
typedef struct ListNode *PtrListNode;

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

PtrListNode MakeList();
Node *MakeNode(Node *parentAddress, PtrTree root, char *inputString, bool inputType);
PtrTree MakeTree();

#endif