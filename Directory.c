#include "Directory.h"
#include "hash.h"

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

Node *MakeNode(Node *parentAddress, PtrTree root, char *inputString, bool inputType)
{
    Node *N = (Node *)malloc(sizeof(Node));
    N->FirstChild = NULL;
    N->name = (char *)malloc(sizeof(char *));
    N->name = inputString;
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
/*
PtrNode searchAlias (PtrNode root , char* Alias)
{
    PtrNode current = root;

    if(current->type==1)
    {
        return NULL;
    }

    PtrNode head = current->FirstChild;
    PtrNode temp = head;

    while(head!=NULL)
    {
        if(strcmp(head->Alias , Alias)==0)
        {
            return head;
        }
        head=head->Sibling;

        return searchAlias(head->FirstChild, Alias);
    }

    return searchAlias(temp->FirstChild, Alias);
}*/

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
    printf("There exists no directory named '%s' in parent directory '%s'\n", array, current->name);
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
/*
PtrNode MoveAlias(PtrNode root, char* Alias)
{
    PtrNode current = searchAlias(current, Alias);

    return current;
}*/

HT2 **MakeHashTable()
{
    struct Node2 **HT2 = (struct Node2 **)malloc(sizeof(struct Node2 *) * 69);
    for (int i = 0; i < 69; i++)
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
    insertSep2(Address, AliasHashTable, Alias);
}
/*
void StoreAliasSafety(PtrTree root,char* Address,char* Alias)
{
    PtrNode input = Move(root,Address);
    strcpy(input->Alias,Alias);
}*/
PtrNode Teleport(PtrTree Tree , char *alias, HT2 **AliasHashTable)
{
    char *NewAddress;
    NewAddress = searchSepAlias(alias, AliasHashTable);
    if (NewAddress == NULL)
    {
        printf("The alias '%s' does not exist", alias);
        return NULL;
    }
    else
    {
        PtrNode directory = Move(Tree, NewAddress);
        return directory;
    }
} /*
PtrNode TeleportSafety(char* Alias, PtrTree root)
{
    PtrNode current = MoveAlias(root, Alias);

    return current;
}
void Quit()
{
    printf("Goodbye\n");
    exit(0);
}*/