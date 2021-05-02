#include "Directory.h"

PtrTree MakeTree()
{
    PtrTree T = (PtrTree)malloc(sizeof(Tree));
    T->root = (Node *)malloc(sizeof(Node));
    T->root->FirstChild = NULL;
    T->root->name = (char *)malloc(sizeof(char) * 4);
    T->root->Parent = NULL;
    T->root->Sibling = NULL;
    T->root->type = 0;
    return T;
}

Node *MakeNode(Node *parentAddress, PtrTree root, char *inputString, bool inputType)
{
    Node *N = (Node *)malloc(sizeof(Node));
    N->FirstChild = NULL;
    N->name = (char *)malloc(sizeof(char) * strlen(inputString));
    N->Parent = parentAddress;
    N->Sibling = parentAddress->FirstChild;
    parentAddress->FirstChild = N;
    N->type = inputType;
    return N;
}

void AddFile(PtrNode current, PtrTree root, char *inputString)
{
    Node *File = MakeNode(current, root, inputString, 1); //file inputType is 1
}
void AddDirectory(PtrNode current, PtrTree root, char *inputString)
{
    Node *Folder = MakeNode(current, root, inputString, 0); //directory inputType is 0
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
            return head;
        }
        head = head->Sibling;
    }
    return NULL;
}

PtrNode Move(PtrTree root, char *inputString)
{
    PtrNode parent = root;
    PtrNode current = root;
    char array[100];
    for (int i = 0, j = 0; i < strlen(inputString); i++, j++)
    {
        if (inputString[i] == '/')
        {
            array[j] = '\0';
            current = search(current, array);
            if (current == NULL)
            {
                printf("Error\n");
                return NULL;
            }
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
