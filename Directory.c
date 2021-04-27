#include "Directory.h"

PtrTree MakeTree()
{
    PtrTree T =(PtrTree) malloc(sizeof(Tree));
    T->root = (Node*) malloc(sizeof(Node));  
    T->root->FirstChild=NULL;
    T->root->name=(char*) malloc(sizeof(char)*4);
    T->root->Parent=NULL;
    T->root->Sibling=NULL;
    T->root->type=0;
    return T;
}

Node* MakeNode(Node* parentAddress ,PtrTree root, char *inputString , bool inputType)
{
    Node* N = (Node*) malloc(sizeof(Node));
    N->FirstChild=NULL;
    N->name=(char*) malloc(sizeof(char)*strlen(inputString));
    N->Parent=parentAddress;
    N->Sibling=NULL;
    N->type=inputType;
    return N;
}

void Quit()
{
    printf("Goodbye\n");
    exit(0);
}
