#include "hash.h"
#include "Directory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    PtrTree Tree = MakeTree();
    PtrNode current = Tree->root;
    AddDirectory(current , Tree ,"Directory1");
    AddDirectory(current , Tree ,"Directory2");
    AddDirectory(current , Tree ,"Directory3");
    current = current->FirstChild;
    AddDirectory(current , Tree ,"Directory4");
    AddDirectory(current , Tree ,"Directory5");

    HT2** Htable = MakeHashTable();
    StoreAlias(Tree , "root/Directory1" , "Alias1" , Htable);
    StoreAlias(Tree , "root/Directory2" , "Alias2" , Htable);
    for(int i=0 ; i<69 ; i++)
    {
        if(Htable[i]!=NULL)
        {
            printf("%d\n",i);
        }
    }
    printf("%s\n" , Teleport(Tree ,"Alias1",Htable)->Parent->name);

    return 0;
}