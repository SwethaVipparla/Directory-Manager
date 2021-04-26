#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Directory.h"

int main()
{
    int queries;
    printf("Enter the number of commands you wish to perform\n");
    scanf("%d",queries);
    PtrTree root = MakeTree();

    for(int i=0; i<q; i++)
    {
    printf("Press 1 to Add file\n");
    printf("Press 2 to Add Directory\n");
    printf("Press 3 to move to another Directory\n");
    printf("Press 4 to store address of a file as an Alias\n");
    printf("Press 5 to teleport to an Alias\n");
    printf("Press 6 to Quit the function\n");
    int n;
    scanf("%d",&n);

    switch(n)
    {
        case 1:
        {
                char* name;
                scanf("%s",name);
                AddFile(current,root,name);
        }break;
        case 2:
        {
            char* name;
            scanf("%s",name);
            AddDirectory(current,root,name);
        }break;
        case 3:
        {
            char nextDirectory[256];
            fgets(nextDirectory,256,stdin);
            Move(root,nextDirectory);
        }break;
        case 4:
        {
            //PtrNode Address;
            char Address[256];
            fgets(Address,256,stdin);
            char* Alias;
            scanf("%s",Alias);
            StoreAlias(Address,Alias);
        }break;
        case 5:
        {
            char Alias[100];
            scanf("%s",Alias);
            Teleport(Alias);
        }break;
        case 6:
        {
            printf("Goodbye\n");
            exit(0);
        }
    }
    }
}