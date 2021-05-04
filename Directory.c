#include "Directory.h"
#include "hash.h"
//char hash_for_find[10000];
//HT3 hash_for_find[10000];

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

void find(char STRING[],  int n,char Array[][])
{
    
    int len = strlen(STRING);
    //hash_for_find[];
    int j = 0;
    while (j < 10000 /*size of array)*/)
    {
        
        int m = 1;

        for (int i = 0; i < len; i++)
        {
            if (Array[j][i] == STRING[i])
            {
                m++;
            }
            else
            {
                break;
            }
        }
        if (m == len + 1)
        {
            printf("%s\n", Array[j][]);
        }
        j++;
    }
    //optimiztion can be done with the while loop as for how many times to run it
}
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
PtrNode searchAlias(PtrNode root, char *Alias)
{
    PtrNode current = root;

    if (current->type == 1)
    {
        return NULL;
    }

    PtrNode head = current->FirstChild;
    PtrNode temp = head;

    while (head != NULL)
    {
        if (strcmp(head->Alias, Alias) == 0)
        {
            return head;
        }
        head = head->Sibling;

        return searchAlias(head->FirstChild, Alias);
    }

    return searchAlias(temp->FirstChild, Alias);
}

PtrNode Move(PtrTree root, char *inputString)
{
    PtrNode parent = root;
    PtrNode current = root;
    int j = 0;
    while (inputString[j] != '\0')
    {
        int i = 0;
        char array[100];
        while (inputString[j + i] != '/')
        {
            array[i] = inputString[j + i];
            i++;
        }
        array[i] = '\0';
        current = search(current, array);
        if (current == NULL)
        {
            printf("Error\n");
            return NULL;
        }
        j += i + 1;
    }
    return current;
}

PtrNode MoveAlias(PtrNode root, char *Alias)
{
    PtrNode current = searchAlias(current, Alias);

    return current;
}

HT2 *MakeHashTable()
{
    struct Node2 *HT2[69];
    for (int i = 0; i < 69; i++)
    {
        HT2[i] = NULL;
    }

    return HT2;
}

void StoreAlias(PtrTree root, char *Address, char *Alias, HT2 *AliasHashTable)
{
    //PtrNode input = Move(root,Address);
    insertSep2(Address, AliasHashTable, Alias);
}

void StoreAliasSafety(PtrTree root, char *Address, char *Alias)
{
    PtrNode input = Move(root, Address);
    strcpy(input->Alias, Alias);
}
PtrNode Teleport(char *alias, HT2 *AliasHashTable)
{
    char *NewAddress;
    NewAddress = searchSepAlias(alias, AliasHashTable);
}
PtrNode TeleportSafety(char *Alias, PtrTree root)
{
    PtrNode current = MoveAlias(root, Alias);

    return current;
}
void Quit()
{
    printf("Goodbye\n");
    exit(0);
}