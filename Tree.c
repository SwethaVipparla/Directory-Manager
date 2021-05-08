#include "Tree.h"

PtrTree MakeTree()
{
    PtrTree T = (PtrTree)malloc(sizeof(Tree));
    T->root = (Node *)malloc(sizeof(Node));

    T->root->FirstChild = NULL;
    T->root->name = (char *)malloc(sizeof(char) * 4);
    T->root->name = "root";
    T->root->Parent = NULL;
    T->root->Sibling = NULL;
    T->root->type = 0;

    return T;
}

Node *MakeNode(Node *parentAddress, PtrTree root, char *inputName, bool inputType)
{
    Node *N = (Node *)malloc(sizeof(Node));

    N->FirstChild = NULL;
    N->name = (char *)malloc(sizeof(char) * strlen(inputName));
    N->name = inputName;
    N->Parent = parentAddress;
    N->Sibling = parentAddress->FirstChild;
    parentAddress->FirstChild = N;
    N->type = inputType;

    return N;
}