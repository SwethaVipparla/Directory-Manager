#include "Directory.h"

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

Node *MakeNode(Node *parentAddress, PtrTree Tree, char *inputString, bool inputType)
{
    Node *N = (Node *)malloc(sizeof(Node));
    N->FirstChild = NULL;
    N->name = (char *)malloc(sizeof(char) * strlen(inputString));
    N->name = inputString;
    N->Parent = parentAddress;
    N->Sibling = parentAddress->FirstChild;
    parentAddress->FirstChild = N;
    N->type = inputType;
    return N;
}

void AddFile(PtrNode current, PtrTree Tree, char *inputString)
{
    Node *File = MakeNode(current, Tree, inputString, 1); //file inputType is 1
}
void AddDirectory(PtrNode current, PtrTree Tree, char *inputString)
{
    Node *Folder = MakeNode(current, Tree, inputString, 0); //directory inputType is 0
}

PtrNode search(PtrNode current, char *array)
{
    if (current->type == 1)
    {
        return NULL;
    }
    PtrNode head = current->FirstChild;
    while (head != NULL)
    {
        if (strcmp(head->name, array) == 0)
        {
            if (head->type == 1)
            {
                printf("You are trying to access a file instead of a directory!\n");
                return NULL;
            }
            else
                return head;
        }
        head = head->Sibling;
    }
    printf("There exists no directory named '%s' in parent directory '%s'\n",array ,current->name);
    return NULL;
}

PtrNode Move(PtrTree Tree, char *inputString)
{
    PtrNode parent = Tree->root;
    PtrNode current = Tree->root;
    char array[100];
    for (int i = 0, j = 0; i < strlen(inputString); i++, j++)
    {
        if (inputString[i] == '/')
        {
            array[j] = '\0';
            if (i == 4)
            {
                goto L1;
            }
            current = search(current, array);
            if (current == NULL)
            {
                printf("Error\n");
                return NULL;
            }
        L1:
            j = -1;
            continue;
        }
        array[j] = inputString[i];
        if (i == strlen(inputString) - 1)
        {
            array[++j] = '\0';
            current = search(current, array);
            if (current == NULL)
            {
                printf("Error\n");
                return NULL;
            }
        }
    }
    return current;
}

void Quit()
{
    printf("Goodbye\n");
    exit(0);
}
