#include "Tree.h"
#include "Tree.c"
#include "hash.h"
#include "hash.c"
#include "Directory.h"
#include "Directory.c"

char Elements[1000][1000];

int main(void)
{
  int i = 0;
  char command[20];
  HT **HTable = MakeHashTable();

  PtrTree Tree = MakeTree();
  PtrNode current = Tree->root;

  printManual();
  
  while (1)
  {
    printf(PURPLE);
    printf("\n %s ", current->name);
    printf(LIGHT_PINK);
    printf("> ");
    printf(RESET);
    scanf("%s", command);

    if (strcmp("ADD", command) == 0 || strcmp("Add", command) == 0 || strcmp("add", command) == 0)
    {
      char type[10];
      scanf("%s %s", type, Elements[i]);

      if (strcmp("di", type) == 0)
      {
        AddDirectory(current, Tree, Elements[i]);
        
      }

      if (strcmp("fi", type) == 0)
      {
        AddFile(current, Tree, Elements[i]);
      }

      i++;
    }

    else if (strcmp("MOVE", command) == 0 || strcmp("Move", command) == 0 || strcmp("move", command) == 0)
    {
      char path[1000];
      scanf(" %s", path);

      PtrNode N = Move(Tree, path);

      if (N)
      {
        printf(GREEN);
        printf("\nThe current directory has been changed from '%s' to '%s'!\n", current->name, N->name);
        printf(RESET);

        current = N;
      }
    }

    else if (strcmp("ALIAS", command) == 0 || strcmp("Alias", command) == 0 || strcmp("alias", command) == 0)
    {
      char alias[1000], path[1000];
      scanf("%s %s", path, alias);

      StoreAlias(Tree, path, alias, HTable);
    }

    else if (strcmp("TELEPORT", command) == 0 || strcmp("Teleport", command) == 0 || strcmp("teleport", command) == 0)
    {
      char alias[1000];
      scanf("%s", alias);

      PtrNode N = Teleport(Tree, alias, HTable);

      if (N)
      {
        if(strcmp(current->name, N->name)==0)
        {
          printf(RED);
          printf("\nError: You're already in the %s directory!\n", current->name);
          printf(RESET);
        }

        else
        {  
          printf(GREEN);
          printf("\nThe current directory has been changed from '%s' to '%s'!\n", current->name, N->name);
          printf(RESET);
        }

        current = N;
      }
    }

    else if (strcmp("FIND", command) == 0 || strcmp("Find", command) == 0 || strcmp("find", command) == 0)
    {
      char prefix[1000];
      scanf("%s", prefix);

      printf("\nIn current directory:\n\n");

      traverseTree(current->FirstChild, prefix);

      printf("\n\nIn complete manager:\n\n");
      find(prefix, strlen(prefix), Elements);
    }

    else if (strcmp("LS", command) == 0 || strcmp("Ls", command) == 0 || strcmp("ls", command) == 0)
    {
      ls(current);
    }

    else if (strcmp("QUIT", command) == 0 || strcmp("Quit", command) == 0 || strcmp("quit", command) == 0)
    {
      Quit();
    }

    else
    {
      printf(RED);
      printf("\nError: Please enter a valid command to proceed!\n\n");
      printf(RESET);
    }
  }
}
