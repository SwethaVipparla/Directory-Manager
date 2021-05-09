/*
 Hash.c includes all the function implementations required to 
 create and implement the hash table that is used in storing the 
 aliases of the directories.
*/


#include "hash.h"

/* 
 MakeHashTable:
 Creates a hash table with the size of 2003
*/
HT **MakeHashTable()
{
    struct node **HT = (struct node **)malloc(sizeof(struct node *) * 2003);

    for (int i = 0; i < 2003; i++)
    {
        HT[i] = NULL; // Initialize all values to be null
    }

    return HT;
}

/* 
 hornersRuleHash:
 Obtains the hash of the entered string (the Alias of the component(file/folder)) using Horner's rule
*/
int hornersRuleHash(int n, char *word)
{
    int index = 0;

    for (int i = 0; word[i] != 0; i++)
    {
        index += word[i] - 'A' + 1;
        index *= 33;
        index %= n;
    }

    return index;
}

/* 
 searchSepAlias:
 Searches whether an entered string is stored in the hash table, implemented using separate chaining
*/
char *searchSepAlias(char x[], HT **hashtable)
{
    HT *node = hashtable[hornersRuleHash(2003, x)];
    int i = 0;

    while (node != NULL)
    {
        if ((strcmp(node->Alias, x) == 0))
        {
            return node->Address; // If the entered string(alias) is found, the address of the file is returned
        }

        node = node->next; // Linked list traversal
        i++;
    }
    return NULL; // String not found
}

/*
 insertSep:
 Inserts the details(Alias/Address) of a component(file/folder) into the hash table, implemented using separate chaining
*/
void insertSep(char Address[], HT **hashtable, char *Alias)
{
    int pos = hornersRuleHash(2003, Alias); // Obtains the hash of the Alias of the file/folder, can have multiple aliases with same hash, but all corresponding to different addresses

    // Node in hash table is empty, insert details into the head
    if (hashtable[pos] == NULL) 
    {
        hashtable[pos] = (HT *)malloc(sizeof(HT));
        hashtable[pos]->Alias = malloc(sizeof(char) * strlen(Alias));

        strcpy((hashtable[pos])->Address, Address);
        strcpy((hashtable[pos])->Alias, Alias);

        hashtable[pos]->next = NULL;
    }

    //Node in hash table is not empty, insert details into the back of the linked list
    else 
    {
        HT *temp = (HT *)malloc(sizeof(HT));
        
        temp->Alias = (char *)malloc(sizeof(char) * strlen(Alias));
        strcpy(temp->Address, Address);
        strcpy(temp->Alias, Alias);
        temp->next = NULL;

        HT *traversal = hashtable[pos];

        while (traversal->next != NULL)
        {
            traversal = traversal->next;
        }

        traversal->next = temp; //Linked list traversal
    }
}
