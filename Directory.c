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
        
        printf(GREEN);
        printf("\nA file named '%s' has been added to the current directory '%s'!\n", inputString, current->name);
        printf(RESET);
    }

}

void AddDirectory(PtrNode current, PtrTree tree, char *inputString)
{
    PtrNode N;

    N = search2(current, inputString);

    if(N == NULL)
    {
        Node *Folder = MakeNode(current, tree, inputString, 0); // inputType of directory is 0
        
        printf(GREEN);
        printf("\nA directory named '%s' has been added to the current directory '%s'!\n", inputString, current->name);
        printf(RESET);
    }
}

//Implements one level searching of directories with a given name in the current directory i.e. it will search only the children of 
//current directory . If not found or a file found , prints message and returns
PtrNode search(PtrNode current, char *array)
{
    if (current->type == 1)//If a file is passed we need not search
    {
        return NULL;
    }

    PtrNode head = current->FirstChild;//Pointer to first member of linked list of children . Might be NULL

    //Traversing through the linked list to search for desired directory                                    
    while (head != NULL)
    {
        if (strcmp(head->name, array) == 0)//Names matched
        {
            if (head->type == 1)//If there exists a file with the given name 
            {
                //Print error message and return NULL
                printf(RED);
                printf("Error: You are trying to access a file instead of a directory!\n");
                printf(RESET);

                return NULL;
            }
            else
                return head;// Directory found and returned
        }
        head = head->Sibling;
    }
    //There is no member of linkedlist which has the name as as char string given as input.Print message and return
    printf(RED);
    printf("Error: There exists no directory named '%s' in parent directory! '%s'\n", array, current->name);
    printf(RESET);
    
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
                printf(RED);
                printf("\nError: A file with name '%s' already exists in current directory!", head->name);
                printf(RESET);
                
                return head;
            }

            else
            {
                printf(RED);
                printf("\nError: A directory with name '%s' already exists in current directory!", head->name);
                printf(RESET);
                
                return head;
            }
        }

        head = head->Sibling;
    }

    return NULL;
}

//Changes current directory to any directoryby taking input the complete path to that directory.Handles errors for incorrect paths
PtrNode Move(PtrTree Tree, char *inputString)
{
    char array[10000];

    PtrNode current = Tree->root;//Pointer to root directory

    if (strcmp(inputString, "root") == 0)//If address of root is given we return pointer to root 
    {
        return current;
    }

    for (int i = 0, j = 0; i < strlen(inputString); i++, j++)
    {
        if (inputString[i] == '/')
        {
            array[j] = '\0';//completes the string 
            //address is like root/x/y.... till i=4 only root/ is present . This is skipped since pointer to root is already there
            if (i == 4)
            {
                goto L1;
            }

            current = search(current, array);//returns pointer to one of the children(if it exists) of current with name as that of array string

            if (current == NULL)//Message has been printed in search
            {
                return NULL;
            }

        L1:
            j = -1;//next iteration j=0 , So array will be re-written from starting index
            continue;
        }

        array[j] = inputString[i];//copy characters

        if (i == strlen(inputString) - 1)//last character of string has been copied
        {
            array[++j] = '\0';//complete the string

            current = search(current, array);//returns pointer to one of the children(if it exists) of current with name as that of array string

            if (current == NULL)//Message has been printed in search
            {
                return NULL;
            }
        }
    }

    return current;//Got the desired directory and returned pointer to it
}

void StoreAlias(PtrTree Tree, char *Address, char *Alias, HT **AliasHashTable)
{
    if (searchSepAlias(Alias, AliasHashTable) != NULL)
    {
        printf(RED);
        printf("\nError: The alias '%s' already exists!\n", Alias);
        printf(RESET);

        return;
    }

    PtrNode N = Move(Tree, Address);
    
    if (N == NULL)
        return;
    
    if (N != NULL)
    {
        printf(GREEN);
        printf("\nThe file/directory at location '%s' has been stored with alias '%s'!\n", Address, Alias);
        printf(RESET);
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
        printf(RED);
        printf("\nThe alias '%s' does not exist!\n", alias);
        printf(RESET);

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
    printf("\nGoodbye\n");
    exit(0);
}

void printManual()
{
    printf("\n\n*********************************************************************************************\n\n");
    
    printf(BOLD);
    printf(CYAN);
    printf("Welcome to Directory Manager!\n\n");
    printf(NO_BOLD);
    printf(RESET);

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