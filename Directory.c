#include "Directory.h"
#include "hash.h"
#include "Tree.h"

void AddFile(PtrNode current, PtrTree tree, char *inputString)
{
    PtrNode N;

    N = search2(current, inputString);

    if(N == NULL)
    {
        Node *File = MakeNode(current, tree, inputString, 1); // inputType of file is 1
        //printf(GREEN);
        printf("A file named '%s' has been added to the current directory '%s'\n", inputString, current->name);
        //printf(RESET);
    }

}

void AddDirectory(PtrNode current, PtrTree tree, char *inputString)
{
    PtrNode N;

    N = search2(current, inputString);

    if(N == NULL)
    {
        Node *Folder = MakeNode(current, tree, inputString, 0); // inputType of directory is 0
        //printf(GREEN);
        printf("A directory named '%s' has been added to the current directory '%s'\n", inputString, current->name);
        //printf(RESET);
    }
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

PtrNode search2(PtrNode current, char *array)
{
    if (current->FirstChild == NULL)
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
                printf("A file with name '%s' already exists in current directory\n", head->name);
                return head;
            }

            else
            {
                printf("A directory with name '%s' already exists in current directory\n", head->name);
                return head;
            }
        }

        head = head->Sibling;
    }

    return NULL;
}

PtrNode Move(PtrTree Tree, char *inputString)
{
    char array[1000];

    PtrNode parent = Tree->root;
    PtrNode current = Tree->root;

    if (strcmp(inputString, "root") == 0)
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

void StoreAlias(PtrTree Tree, char *Address, char *Alias, HT **AliasHashTable)
{
    if (searchSepAlias(Alias, AliasHashTable) != NULL)
    {
        printf("The alias '%s' already exists.\n", Alias);
        return;
    }

    PtrNode N = Move(Tree, Address);
    
    if (N == NULL)
        return;
    
    if (N != NULL)
    {
        printf("The file/directory at location '%s' has been stored with alias '%s'\n", Address, Alias);
    }
    
    insertSep(Address, AliasHashTable, Alias);
}

// Teleport :
// Teleports to an alias entered by the user, updating the current directory to start from the entered alias
// Calls the search function, to search up the entered alias in the hash table, and moves to the address of the desired alias

PtrNode Teleport(PtrTree Tree, char *alias, HT **AliasHashTable)
{
    char *NewAddress;
    NewAddress = searchSepAlias(alias, AliasHashTable); //Hash search function implemented in hash.c
    
    if (NewAddress == NULL)                             //Error handling : for when the entered alias is not found in the hash table
    {
        printf("The alias '%s' does not exist.\n", alias);
        return NULL;
    }
    
    else //When the entered alias exists, the current directory is updated to the address of the entered alias by the Move function
    {
        PtrNode directory = Move(Tree, NewAddress);
        return directory;
    }
}

void traverseTree(PtrNode root, char *prefix)
{
    if (root == NULL)
        return;

    while (root)
    {
        int m = 1;
        
        for (int i = 0; i < strlen(prefix); i++)
        {
            if (root->name[i] == prefix[i])
            {
                m++;
            }
            
            else
            {
                break;
            }
        }
        
        if (m == strlen(prefix) + 1)
        {
            printf("%s\n", root->name);
        }
        
        if (root->FirstChild)
            traverseTree(root->FirstChild, prefix);
        
        root = root->Sibling;
    }
}

void find(char STRING[], int n, char Array[][1000])
{

    int len = n;
    //hash_for_find[];
    int j = 0;
    
    while (j < 1000) //Number of inputs
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
            printf("%s\n", Array[j]);
        }
        
        j++;
    }
    //optimiztion can be done with the while loop as for how many times to run it
}

void Quit()
{
    printf("Goodbye\n");
    exit(0);
}

void printManual()
{
    printf("\n\n*********************************************************************************************\n\n");
    
    printf(BOLD);
    //printf(MAGENTA);
    printf("Welcome to Directory Manager!\n\n");
    printf(NO_BOLD);
    //printf(RESET);

    printf("Choose one of the following options to continue:\n\n");

    printf(BOLD);
    printf("1. ADD\n");
    printf(NO_BOLD);
    printf("Adds a file or directory\n\n");

    printf(BOLD);
    printf("2. MOVE\n");
    printf(NO_BOLD);
    printf("Changes the current directory to another directory\n\n");

    printf(BOLD);
    printf("3. ALIAS\n");
    printf(NO_BOLD);
    printf("Saves a directory with an alias\n\n");

    printf(BOLD);
    printf("4. TELEPORT\n");
    printf(NO_BOLD);
    printf("Changes the current directory to another directory by taking in an alias\n\n");

    printf(BOLD);
    printf("5. FIND\n");
    printf(NO_BOLD);
    printf("Finds directories and files with a given prefix inside the current directory\n\n");

    printf(BOLD);
    printf("6. QUIT\n");
    printf(NO_BOLD);
    printf("Exit the program\n\n");

  printf("**********************************************************************************************\n\n");
  
}