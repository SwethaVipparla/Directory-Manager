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

  while (1)
  {
    scanf("%s", command);

    if (strcmp("ADD", command) == 0)
    {
      char type[10];
      scanf("%s %s", type, Elements[i]);
      if (strcmp("Directory", type) == 0)
      {
        AddDirectory(current, Tree, Elements[i]);
        //printf("%s",Elements[i]);
        //printf("%s",current->FirstChild->name);
        printf("A directory named '%s' has been added to the current directory '%s'\n", Elements[i], current->name);
      }
      if (strcmp("File", type) == 0)
      {
        AddFile(current, Tree, Elements[i]);
        printf("A file named '%s' has been added to the current directory '%s'\n", Elements[i], current->name);
      }
      i++;
    }
    else if (strcmp("MOVE", command) == 0)
    {
      char path[1000];
      scanf(" %s", path);
      //printf("--%c--",path[0]);
      PtrNode N = Move(Tree, path);
      if (N != NULL)
      {
        printf("The current directory has been changed from '%s' to '%s'\n", current->name, N->name);
        current = N;
      }
    }
    else if (strcmp("ALIAS", command) == 0)
    {
      char alias[100];
      char path[1000];
      scanf("%s %s", path, alias);
      StoreAlias(Tree, path, alias, HTable);
    }
    else if (strcmp("TELEPORT", command) == 0)
    {
      char alias[100];
      scanf("%s", alias);
      PtrNode N = Teleport(Tree, alias, HTable);
      if (N != NULL)
      {
        printf("The current directory has been changed from '%s' to '%s'\n", current->name, N->name);
        current = N;
      }
    }
    else if (strcmp("FIND", command) == 0)
    {
      char prefix[100];
      scanf("%s", prefix);
      traverseTree(current->FirstChild, prefix);
      printf("\nIn complete manager\n");
      find(prefix, strlen(prefix), Elements);
    }
    else if (strcmp("QUIT", command) == 0)
    {
      Quit();
    }
    else
    {
      printf("The command '%s' you entered is invalid.Please enter a valid command to proceed.\n", command);
    }
  }
}
