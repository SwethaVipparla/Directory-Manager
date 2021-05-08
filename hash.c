#include "hash.h"
//Useless code
int hash(int x, int tablesize)
{

    return (x % tablesize);
}
//hornersRuleHash:
//Obtains the hash of the entered string ( the Alias of the component(file/folder) ), using Horner's rule
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
//Useless code
int searchSep(int x, int tablesize, HT *hashtable[])
{
    HT *node = hashtable[hash(x, tablesize)];
    int i = 0;
    while (node != NULL)
    {
        if (node->n == x)
        {
            return i;
        }
        node = node->next;
        i++;
    }
    return -1;
}
//Useless code
void insertSep(int x, int tablesize, HT *hashtable[])
{
    int pos = hash(x, tablesize);

    if (hashtable[pos] == NULL)
    {
        hashtable[pos] = (HT *)malloc(sizeof(HT));
        (hashtable[pos])->n = x;
        (hashtable[pos])->next = NULL;
    }
    else
    {
        HT *temp = (HT *)malloc(sizeof(HT));
        temp->n = x;
        temp->next = NULL;

        HT *traversal = hashtable[pos];

        while (traversal->next != NULL)
        {
            traversal = traversal->next;
        }
        traversal->next = temp;
    }
}
//hash2:
//Obtains the basic hash of the entered string ( the alias of the given component(file/folder) )
int hash2(char w[])
{
    char c;

    c = w[0];

    int y = c - 65;

    return y;
}
//Useless code
int searchSep2(char x[], HT2 *hashtable[])
{
    HT2 *node = hashtable[hornersRuleHash(2003, x)];
    int i = 0;
    while (node != NULL)
    {
        if ((strcmp(node->Address, x) == 0))
        {
            return i;
        }
        node = node->next;
        i++;
    }
    return -1;
}
// searchSepAlias:
// Searches whether an entered string is stored in the hash table, implemented using separate chaining
char *searchSepAlias(char x[], HT2 **hashtable)
{
    HT2 *node = hashtable[hornersRuleHash(2003, x)];
    int i = 0;
    while (node != NULL)
    {
        if ((strcmp(node->Alias, x) == 0))
        {
            return node->Address; //If the entered string(alias) is found, the address of the file is returned
        }
        node = node->next; //Linked list traversal
        i++;
    }
    return NULL; //String not found
}
//insertSep2:
//Inserts the details(Alias/Address) of a component(file/folder) into the hash table, implemented using separate chaining
void insertSep2(char Address[], HT2 **hashtable, char *Alias)
{
    int pos = hornersRuleHash(2003, Alias); //Obtains the hash of the Alias of the file/folder, can have multiple alias'es with same hash, but all corresponding to different addresses

    if (hashtable[pos] == NULL) //Node in hash table is empty, inseart details into the head
    {
        hashtable[pos] = (HT2 *)malloc(sizeof(HT2));
        hashtable[pos]->Alias = malloc(sizeof(char) * strlen(Alias));
        strcpy((hashtable[pos])->Address, Address);
        strcpy((hashtable[pos])->Alias, Alias);
        (hashtable[pos])->next = NULL;
    }
    else //Node in hash table is not empty, insert details into the back of the linked list
    {
        HT2 *temp = (HT2 *)malloc(sizeof(HT2));
        temp->Alias = (char *)malloc(sizeof(char) * strlen(Alias));
        strcpy(temp->Address, Address);
        strcpy(temp->Alias, Alias);
        temp->next = NULL;

        HT2 *traversal = hashtable[pos];

        while (traversal->next != NULL)
        {
            traversal = traversal->next;
        }
        traversal->next = temp; //Linked list traversal
    }
}
