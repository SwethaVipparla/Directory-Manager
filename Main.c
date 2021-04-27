#include "Directory.h"

int main()
{
    int queries;
    printf("Enter the number of commands you wish to perform\n");
    scanf("%d", queries);
    PtrTree root = MakeTree();

    for(int i = 0; i < queries; i++)
    {
        printf("Press 1 to Add file/directory\n");
        printf("Press 2 to move to another Directory\n");
        printf("Press 3 to store address of a file as an Alias\n");
        printf("Press 4 to teleport to an Alias\n");
        printf("Press 5 to find a file/directory with a prefix\n");
        printf("Press 6 to Quit the function\n");

        int n;
        scanf("%d", &n);

        switch(n)
        {
            case 1:
            {
                char* inputName;
                char inputType[20];
                scanf("%s %s", inputType, inputName);

                if(strcmp(inputType, "file") == 0)
                    AddFile(current, root, inputName);
                    
                else if(strcmp(inputType, "directory") == 0)
                    AddDirectory(current, root, inputName);
            }
                break;

            case 2:
            {
                char nextDirectory[256];
                fgets(nextDirectory, 256, stdin);
                Move(root, nextDirectory);
            }
                break;

            case 3:
            {
                //PtrNode Address;
                char Address[256];
                fgets(Address, 256, stdin);
                char* Alias;
                scanf("%s", Alias);
                StoreAlias(Address,Alias);
            }
                break;

            case 4:
            {
                char Alias[256];
                scanf("%s", Alias);
                Teleport(Alias);
            }
                break;

            case 6:
            {
                Quit();
            }
                break;
        }
    }
}