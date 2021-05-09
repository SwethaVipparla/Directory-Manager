/*
 Main.c includes the function calls for the various features and menu
 interface. The entire codebase is included in this file.
*/

#include "Directory.h"
#include "Tree.c"
#include "hash.c"
#include "Directory.c"

char Elements[1000][1000];

int main(void)
{
  int i = 0;
  char command[20];
  HT **HTable = MakeHashTable(); 

  PtrTree Tree = makeTree();
  PtrTree treeRoot = Tree; // Store pointer to the root
  PtrNode current = Tree->root;

  printManual(); // Prints the menu that pops up when the program is executed
  
  // The program is run until the 'quit' function is executed
  while (1)
  {
    printf(PURPLE);
    printf("\n %s ", current->name);
    printf(LIGHT_PINK);
    printf("> ");
    printf(RESET);
    scanf("%s", command);

    // Implement the 'add' functionality
    if (strcmp("ADD", command) == 0 || strcmp("Add", command) == 0 || strcmp("add", command) == 0)
    {
      char type[10];
      scanf("%s %s", type, Elements[i]);
      
      // If the type is directory, then call the addDirectory function
      if (strcmp("di", type) == 0 || strcmp("Di", type) == 0 || strcmp("DI", type) == 0)
      {
        addDirectory(current, Tree, Elements[i]);
      }

      // If the type is file, then call the addFile function
      if (strcmp("fi", type) == 0 || strcmp("Fi", type) == 0 || strcmp("FI", type) == 0)
      {
        addFile(current, Tree, Elements[i]);
      }

      i++;
    }

    // Implement the 'move' functionality
    else if (strcmp("MOVE", command) == 0 || strcmp("Move", command) == 0 || strcmp("move", command) == 0)
    {
      char path[1000];
      scanf(" %s", path);

      // Move the directory to N based on the path inputted
      PtrNode N = move(Tree, path);

      // If we are already in the directory to which the path is inputted, then print an error message and continue
      if(N == current)
      {
        printf(RED);
        printf("\n Error: You're already in this directory!\n");
        printf(RESET);

        continue;
      }

      // If the directory exists, then move to the directory and print success message
      if (N != NULL)
      {
        printf(GREEN);
        printf("\n The current directory has been changed from '%s' to '%s'!\n", current->name, N->name);
        printf(RESET);

        current = N;
      }
    }

    // Implement the 'alias' functionality
    else if (strcmp("ALIAS", command) == 0 || strcmp("Alias", command) == 0 || strcmp("alias", command) == 0)
    {
      char alias[1000], path[1000];
      scanf("%s %s", path, alias);

      // Store the alias in the hashtable based on the path
      storeAlias(Tree, path, alias, HTable);
    }

    // Implement the 'teleport' functionality
    else if (strcmp("TELEPORT", command) == 0 || strcmp("Teleport", command) == 0 || strcmp("teleport", command) == 0)
    {
      char alias[1000];
      scanf("%s", alias);

      // Move the directory to N based on the alias directory inputted
      PtrNode N = teleport(Tree, alias, HTable);

      // If the alias directory exists, then check if we are already in the given alias directory
      if (N != NULL)
      {
        // If we are already in given alias directory, then move to the given alias directory and print success message
        if(strcmp(current->name, N->name) == 0)
        {
          printf(RED);
          printf("\n Error: You're already in the '%s' directory!\n", current->name);
          printf(RESET);
        }

        // If we are not in given alias directory, then move to the alias directory and print success message
        else
        {  
          printf(GREEN);
          printf("\n The current directory has been changed from '%s' to '%s'!\n", current->name, N->name);
          printf(RESET);
        }

        current = N;
      }
    }

    // Implement the 'find' functionality
    else if (strcmp("FIND", command) == 0 || strcmp("Find", command) == 0 || strcmp("find", command) == 0)
    {
      char prefix[1000];
      scanf("%s", prefix);

      printf("\n In current directory:\n\n");

      // Find files/directories with the given prefix in the current directory
      directoryFind(current->FirstChild, prefix);

      // Find files/directories with the given prefix in the complete directory manager
      printf("\n\n In complete directory manager:\n\n");
      managerFind(prefix, strlen(prefix), Elements);
    }

    // Implement the 'ls' functionality
    else if (strcmp("LS", command) == 0 || strcmp("Ls", command) == 0 || strcmp("ls", command) == 0)
    {
      // Lists all the files/directories present in the current directory
      ls(current);
    }

    // Implement the 'quit' functionality
    else if (strcmp("QUIT", command) == 0 || strcmp("Quit", command) == 0 || strcmp("quit", command) == 0)
    {
      // Quits the program
      quit();
    }

    // If the command inputted doesn't match any of the available functionalities, print an error messages
    else
    {
      printf(RED);
      printf("\n Error: Please enter a valid command to proceed!\n");
      printf(RESET);
    }
  }
}
