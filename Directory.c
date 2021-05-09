/*
 Directory.c includes all the function implementations required to 
 implement the add, move, alias, teleport, find, ls, and quit functionalities.
*/

#include "Directory.h"

/*
 addFile:
 Takes in pointers to the current node, tree, and the input string, and creates a file with the corresponding
 name. This file is stored in the current directory.
*/
void addFile(PtrNode current, PtrTree tree, char *inputString)
{
    PtrNode N;

    N = search2(current, inputString); // Searches if a file with the given name already exists in the current directory and gives an error message accordingly

    if (N == NULL)
    {
        Node *File = makeNode(current, tree, inputString, 1); // Makes a node for the file, and inputType of file is 1

        printf(GREEN);
        printf("\n New file '%s' added to the current directory '%s'!\n", inputString, current->name);
        printf(RESET);
    }
}

/*
 addDirectory:
 Takes in pointers to the current node, tree, and the input string, and creates a directory with the corresponding
 name. This directory is stored in the current directory.
*/
void addDirectory(PtrNode current, PtrTree tree, char *inputString)
{
    PtrNode N;

    N = search2(current, inputString); // Searches if a directory with the given name already exists in the current directory and gives an error message accordingly

    if (N == NULL)
    {
        Node *Folder = makeNode(current, tree, inputString, 0); // Makes a node for the directory, and inputType of file is 1

        printf(GREEN);
        printf("\n New directory '%s' added to the current directory '%s'!\n", inputString, current->name);
        printf(RESET);
    }
}

/*
 search:
 Implements one level searching of directories with a given name in the current directory i.e. it will search only the children of 
 current directory . If not found or a file found , prints message and returns.
*/
PtrNode search(PtrNode current, char *array)
{
    if (current->type == 1) // If a file is passed we need not search
    {
        return NULL;
    }

    PtrNode head = current->FirstChild; // Pointer to first member of linked list of children . Might be NULL

    // Traversing through the linked list to search for desired directory
    while (head != NULL)
    {
        if (strcmp(head->name, array) == 0) //Names matched
        {
            if (head->type == 1) // If there exists a file with the given name
            {
                //Print error message and return NULL
                printf(RED);
                printf("\n Error: You are trying to access a file instead of a directory!\n");
                printf(RESET);

                return NULL;
            }
            else
                return head; // Directory found and returned
        }
        head = head->Sibling;
    }

    // There is no member of linkedlist which has the name as as char string given as input.Print message and return
    printf(RED);
    printf("\n Error: There exists no directory named '%s' in parent directory '%s'!\n", array, current->name);
    printf(RESET);

    return NULL;
}

/*
 search2:
 Searches if a file/directory with the given name from addFile/addDirectory already exists in the current directory 
 and gives an error message accordingly.
*/
PtrNode search2(PtrNode current, char *array)
{
    // If the current directory is empty, this means a directory/file with the given name doesn't exist, and hence, we're good to go
    if (current->FirstChild == NULL)
    {
        return NULL;
    }

    // Make a pointer to the first child of current
    PtrNode head = current->FirstChild;

    // While head is not empty, check whether a file/directory with the given name already exists
    while (head != NULL)
    {
        // Proceed if the given name and the name of the pointer are the same
        if (strcmp(head->name, array) == 0)
        {
            // If the type of the pointer is file(1), then that means a file with the same name as given name exists, so print error
            if (head->type == 1)
            {
                printf(RED);
                printf("\n Error: A file with name '%s' already exists in current directory!\n", head->name);
                printf(RESET);

                return head;
            }

            // If the type of the pointer is directory(0), then that means a directory with the same name as given name exists, so print error
            else
            {
                printf(RED);
                printf("\n Error: A directory with name '%s' already exists in current directory!\n", head->name);
                printf(RESET);

                return head;
            }
        }

        // Point the head to its sibling if the given name and the name of the pointer are not the same
        head = head->Sibling;
    }

    return NULL;
}

/*
 move:
 Changes current directory to any directory by taking input the complete path to that directory. 
 Handles errors for incorrect paths.
*/
PtrNode move(PtrTree Tree, char *inputString)
{
    char array[10000];

    PtrNode current = Tree->root; // Pointer to root directory

    if (strcmp(inputString, "root") == 0) // If address of root is given we return pointer to root
    {
        return current;
    }

    // If the first word is not root, output an error
    else if (strlen(inputString) < 4)
    {
        printf(RED);
        printf("\n Error: The address you entered is incorrect!\n"); // Prints message
        printf(RESET);

        return NULL; // Returns NULL pointer
    }

    // Check if the first word in address is root
    else
    {
        char word[5];
        int i = 0;

        for (i = 0; i < 4; i++)
        {
            word[i] = inputString[i];
        }

        word[i] = '\0';

        // If the first word is not root, address is incorrect
        if (strcmp(word, "root") != 0) 
        {
            printf(RED);
            printf("\n Error: The address you entered is incorrect!\n"); // Prints message
            printf(RESET);

            return NULL; // Returns NULL pointer
        }
    }

    for (int i = 0, j = 0; i < strlen(inputString); i++, j++)
    {
        if (inputString[i] == '/')
        {
            array[j] = '\0'; // Completes the string

            // Address is like root/x/y.... till i=4 only root/ is present. This is skipped since pointer to root is already there
            if (i == 4)
            {
                goto L1;
            }

            current = search(current, array); // Returns pointer to one of the children(if it exists) of current with name as that of array string

            // Message has been printed in search
            if (current == NULL)
            {
                return NULL;
            }

        L1:
            j = -1; // Next iteration j = 0 , So array will be re-written from starting index
            continue;
        }

        array[j] = inputString[i]; // Copy characters

        // Last character of string has been copied
        if (i == strlen(inputString) - 1)
        {
            array[++j] = '\0'; // Complete the string

            current = search(current, array); // Returns pointer to one of the children(if it exists) of current with name as that of array string

            // Message has been printed in search
            if (current == NULL)
            {
                return NULL;
            }
        }
    }

    return current; // Got the desired directory and returned pointer to it
}

/*
 storeAlias:
 The storeAlias function adds the given address and the alias
 to a globally declared hashtable
*/
void storeAlias(PtrTree Tree, char *Address, char *Alias, HT **AliasHashTable)
{
    if (searchSepAlias(Alias, AliasHashTable) != NULL)
    {
        // SearchSepAlias here checks if the alias already exists
        printf(RED);
        printf("\n Error: The alias '%s' already exists!\n", Alias);
        printf(RESET);

        return;
    }

    PtrNode N = move(Tree, Address);
    // Move function here verifies if the address is valid or not

    if (N == NULL)
        return;

    if (N != NULL)
    {
        printf(GREEN);
        printf("\n The directory at location '%s' has been stored with alias '%s'!\n", Address, Alias);
        printf(RESET);
    }

    // Inserts the address and alias into the hashtable
    // Uses seperate chaining
    insertSep(Address, AliasHashTable, Alias);
}

/*
 Teleport :
 Teleports to an alias entered by the user, updating the current directory to start from the entered alias
 Calls the search function, to search up the entered alias in the hash table, and moves to the address of the desired alias
*/
PtrNode teleport(PtrTree Tree, char *alias, HT **AliasHashTable)
{
    char *NewAddress;
    NewAddress = searchSepAlias(alias, AliasHashTable); // Hash search function implemented in hash.c

    // Error handling: for when the entered alias is not found in the hash table
    if (NewAddress == NULL)
    {
        printf(RED);
        printf("\n Error: The alias '%s' does not exist!\n", alias);
        printf(RESET);

        return NULL;
    }

    // When the entered alias exists, the current directory is updated to the address of the entered alias by the Move function
    else
    {
        PtrNode directory = move(Tree, NewAddress);
        return directory;
    }
}

/*
 directoryFind
 Traverse tree is the FIND function which searches strings of directories inside the current directory,
 and returns the strings that match the prefix.
 The function aims to return the prefix mathced strings in DFS manner and prints all those present in the current Directory.
*/
// This function provides us all the directory names matching the prefix in the current directory
void directoryFind(PtrNode root, char *prefix)
{
    if (root == NULL) // error handling
        return;

    while (root)
    {
        int m = 1;

        for (int i = 0; i < strlen(prefix); i++)
        {
            // matching every single character of both prefix to respective string in Array
            if (root->name[i] == prefix[i])
            {
                m++;
            }

            // Breaks out of the loop otherwise
            else
            {
                break;
            }
        }

        if (m == strlen(prefix) + 1)
        {
            // if(root->type == 0)
            // {
            //     printf(LIGHT_PURPLE);
            // }
            // else
            // {
            //     printf(YELLOW);
            // }
            printf(" %s\n", root->name); // The array string which satisfies.
            printf(RESET);
        }

        if (root->FirstChild)                        // checks if exists.
            directoryFind(root->FirstChild, prefix); // First Child here refers to the first neighbour of current pointer.(Depth first Call(Recurssion)).

        root = root->Sibling; // here we do the Linked List Traversal.
    }
}

/*
 managerFind:
 The Universal managerFind searches for all the directory and files in the ROOT directory and returns us the ones matching the prefix.
 The Method is to use a global 2d array to store the name of directories whenever a file or directory is added, and Traversing through it,
 which prints the whole list of prefix strings in O(k*N) time, where k is the length of String and N is the number of Directories.
*/
// This function provides us all the directory names matching the prefix in the whole complete manager directory
void managerFind(char STRING[], int n, char Array[][1000])
{

    int len = n;
    int j = 0;

    // Size of the array we are using
    while (j < 1000)
    {
        int m = 1;

        for (int i = 0; i < len; i++)
        {
            // Matching every single character of both prefix to respective string in Array
            if (Array[j][i] == STRING[i])
            {
                m++;
            }

            // Breaks out of the loop otherwise
            else
            {
                break;
            }
        }

        // When the value of m has been summed up n times, then only it had been same
        if (m == len + 1)
        {
            printf(" %s\n", Array[j]); // The array string which satisfies
        }

        j++;
    }
}

/*
 ls:
 Lists the files and directories in the current directory
*/
void ls(PtrNode root)
{
    // Error handling
    if (root == NULL) // Directory is empty
        return;

    root = root->FirstChild;

    printf("\n");

    // Loops until the end of the linked list
    while (root != NULL)
    {
        if (root->type == 0)
        {
            printf(LIGHT_PURPLE);
        }
        else
        {
            printf(YELLOW);
        }
        printf(" %s   ", root->name);
        printf(RESET);

        root = root->Sibling; // Linked list traversal
    }

    printf("\n");
}

/*
 quit:
 Quits the program and prints a goodbye message
*/
void quit()
{
    printf("\n Goodbye!\n\n");
    exit(0);
}

/*
 printManual:
 Function to print the Menu that appears at the beginning of the program. 
 It contains the description of each function and the command to run it.
*/
void printManual()
{
    printf("\n\n    ************************************************************************************************************************\n\n");

    printf(BOLD);
    printf(ORANGE);
    printf("                                                   Welcome to Directory Manager!\n\n");
    printf(NO_BOLD);
    printf(RESET);

    printf("                    Choose one of the following options to continue:\n\n");

    printf(BOLD);
    printf("                    1. ADD\n");
    printf(NO_BOLD);
    printf("                       Adds a file or directory to the current directory\n");
    printf("                       Command: ");
    printf(LIGHT_PINK);
    printf("add di/fi <new_name>\n\n");
    printf(RESET);

    printf(BOLD);
    printf("                    2. MOVE\n");
    printf(NO_BOLD);
    printf("                       Changes the current directory to another directory\n");
    printf("                       Command: ");
    printf(LIGHT_PINK);
    printf("move <path_to_destination_directory>\n\n");
    printf(RESET);

    printf(BOLD);
    printf("                    3. ALIAS\n");
    printf(NO_BOLD);
    printf("                       Saves a directory with an alias\n");
    printf("                       Command: ");
    printf(LIGHT_PINK);
    printf("alias <path_to_directory> <new_alias>\n\n");
    printf(RESET);

    printf(BOLD);
    printf("                    4. TELEPORT\n");
    printf(NO_BOLD);
    printf("                       Changes the current directory to another directory by taking in an existing alias\n");
    printf("                       Command: ");
    printf(LIGHT_PINK);
    printf("teleport <existing_alias>\n\n");
    printf(RESET);

    printf(BOLD);
    printf("                    5. FIND\n");
    printf(NO_BOLD);
    printf("                       Finds directories and files with a given prefix inside the current directory\n");
    printf("                       Command: ");
    printf(LIGHT_PINK);
    printf("find <prefix>\n\n");
    printf(RESET);

    printf(BOLD);
    printf("                    6. LS\n");
    printf(NO_BOLD);
    printf("                       Lists the contents of the current directory\n");
    printf("                       Command: ");
    printf(LIGHT_PINK);
    printf("ls\n\n");
    printf(RESET);

    printf(BOLD);
    printf("                    7. QUIT\n");
    printf(NO_BOLD);
    printf("                       Exit the program\n");
    printf("                       Command: ");
    printf(LIGHT_PINK);
    printf("quit\n\n");
    printf(RESET);

    printf("    *************************************************************************************************************************\n\n");
}
