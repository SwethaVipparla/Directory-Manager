#include "Directory.h"
#include "hash.h"

PtrTree MakeTree()
{
    PtrTree T = (PtrTree) malloc (sizeof(Tree));
    T->root = (Node *) malloc (sizeof(Node));

    T->root->FirstChild = NULL;
    T->root->name = (char*) malloc (sizeof(char) * 4);
    T->root->name = "root";
    T->root->Parent = NULL;
    T->root->Sibling = NULL;
    T->root->type = 0;

    return T;
}

Node *MakeNode(Node *parentAddress, PtrTree root, char *inputName, bool inputType)
{
    Node *N = (Node*) malloc (sizeof(Node));

    N->FirstChild = NULL;
    N->name = (char*) malloc (sizeof(char) * strlen(inputName));
    N->name = inputName;
    N->Parent = parentAddress;
    N->Sibling = parentAddress->FirstChild;
    parentAddress->FirstChild = N;
    N->type = inputType;
    
    return N;
}

void AddFile(PtrNode current, PtrTree root, char *inputString)
{
    Node *File = MakeNode(current, root, inputString, 1); // inputType of file is 1
}

void AddDirectory(PtrNode current, PtrTree root, char* inputString)
{
    Node* Folder = MakeNode(current, root, inputString, 0); // inputType of directory is 0
}

PtrNode search(PtrNode current, char *array)
{
    if (current->type == 1)
    {
        return NULL;
    }
    PtrNode head = current->FirstChild; /// root->c1->c2->c3
                                        //\c4->c5->6
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
    printf("There exists no directory named '%s' in parent directory '%s'\n", array, current->name);
    return NULL;
}

PtrNode Move(PtrTree Tree, char *inputString)
{
    char array[100];

    PtrNode parent = Tree->root;
    PtrNode current = Tree->root;

    if(strcmp(inputString , "root")==0)
    {
        return current;
    }
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

HT2 **MakeHashTable()
{
    struct Node2 **HT2 = (struct Node2 **)malloc(sizeof(struct Node2 *) * 2003);
    for (int i = 0; i < 2003; i++)
    {
        HT2[i] = NULL;
    }

    return HT2;
}

void StoreAlias(PtrTree Tree, char *Address, char *Alias, HT2 **AliasHashTable)
{
    PtrNode N = Move(Tree, Address);
    if (N == NULL)
        return;
    if (N != NULL)
    {
        printf("The file/directory at location '%s' has been stored with alias '%s'\n", Address, Alias);
    }
    insertSep2(Address, AliasHashTable, Alias);
}

void Quit()
{
    printf("Goodbye\n");
    exit(0);
}