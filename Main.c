#include "hash.h"
#include "Directory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Elements[1000][1000];

int main(void)
{
  int i = 0;
  char command[20];
  HT2 **HTable = MakeHashTable();

  PtrTree Tree = MakeTree();
  PtrNode current = Tree->root;

  printf("*********************************************************************************************\n\n \
          Welcome to Directory Manager!\n\n \
          Choose one of the following options to continue:\n\n \
          1. ADD\n \
          Adds a file or directory\n\n \
          2. MOVE\n \
          Changes the current directory to another directory\n\n \
          3. ALIAS\n \
          Saves a directory with an alias\n\n \
          4. TELEPORT\n \
          Changes the current directory to another directory by taking in an alias\n\n \
          5. FIND\n \
          Finds directories and files with a given prefix inside the current directory\n\n \
          6. QUIT\n \
          Exit the program\n\n");

  printf("**********************************************************************************************\n\n");

  while (1)
  {
    printf("Enter your choice\n");
    scanf("%s", command);

    if (strcmp("ADD", command) == 0 || strcmp("Add", command) == 0 || strcmp("add", command) == 0)
    {
      char type[10];

      printf("Directory or file?\n");
      scanf("%s", type);

      printf("Enter the name\n");
      scanf("%s", Elements[i]);

      if (strcmp("Directory", type) == 0)
      {
        AddDirectory(current, Tree, Elements[i]);
        printf("A directory named '%s' has been added to the current directory '%s'\n", Elements[i], current->name);
      }

      if (strcmp("File", type) == 0)
      {
        AddFile(current, Tree, Elements[i]);
        printf("A file named '%s' has been added to the current directory '%s'\n", Elements[i], current->name);
      }

      i++;
    }

    else if (strcmp("MOVE", command) == 0 || strcmp("Move", command) == 0 || strcmp("move", command) == 0)
    {
      char path[1000];

      printf("Enter the path\n");
      scanf(" %s", path);

      PtrNode N = Move(Tree, path);

      if (N)
      {
        printf("The current directory has been changed from '%s' to '%s'\n", current->name, N->name);
        current = N;
      }
    }

    else if (strcmp("ALIAS", command) == 0 || strcmp("Alias", command) == 0 || strcmp("alias", command) == 0)
    {
      char alias[100], path[1000];

      printf("Enter the path and alias\n");
      scanf("%s %s", path, alias);

      StoreAlias(Tree, path, alias, HTable);
    }

    else if (strcmp("TELEPORT", command) == 0)
    {
      char alias[100];

      printf("Enter the alias\n");
      scanf("%s", alias);

      PtrNode N = Teleport(Tree, alias, HTable);

      if (!N)
      {
        printf("The current directory has been changed from '%s' to '%s'\n", current->name, N->name);
        current = N;
      }
    }

    else if (strcmp("FIND", command) == 0 || strcmp("Find", command) == 0 || strcmp("find", command) == 0)
    {
      char prefix[100];

      printf("Enter the prefix\n");
      scanf("%s", prefix);

      traverseTree(current->FirstChild, prefix);

      printf("\nIn complete manager\n");
      find(prefix, strlen(prefix), Elements);
    }

    else if (strcmp("QUIT", command) == 0 || strcmp("Quit", command) == 0 || strcmp("quit", command) == 0)
    {
      Quit();
    }

    else
    {
      printf("The command '%s' you entered is invalid. Please enter a valid command to proceed.\n", command);
    }
  }
}
