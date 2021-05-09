/*
 Tree.c includes all the function implementations required to 
 create the left child right sibling tree data structure and nodes
*/

#include "Tree.h"

/*
 makeTree: 
 Initiliases and makes the First Child-Next Sibling tree for the initial root directory
*/
PtrTree makeTree()
{
    PtrTree T = (PtrTree)malloc(sizeof(Tree)); // Allocates space for root 
    T->root = (Node *)malloc(sizeof(Node));

    T->root->FirstChild = NULL;
    T->root->name = (char *)malloc(sizeof(char) * 4);
    T->root->name = "root";
    T->root->Parent = NULL;
    T->root->Sibling = NULL;
    T->root->type = 0; // `root` is of type directory

    return T;
}

/*
 MakeNode:
 Makes a node for each individual component(file/folder), called during the AddFile and AddDirectory
*/
Node *makeNode(Node *parentAddress, PtrTree root, char *inputName, bool inputType)
{
    Node *N = (Node *)malloc(sizeof(Node)); // Allocates space for node

    N->FirstChild = NULL;
    N->name = (char *)malloc(sizeof(char) * strlen(inputName));
    N->name = inputName;
    N->Parent = parentAddress;
    N->Sibling = parentAddress->FirstChild;
    parentAddress->FirstChild = N;
    N->type = inputType; // Component(file/folder) type entered by user


    return N;
}