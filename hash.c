#include "hash.h"

//Q1 Starts

int hash(int x, int tablesize)
{

    return (x % tablesize);
}

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
int hash2(char w[])
{
    char c;

    c = w[0];

    int y = c - 65;

    return y;
}

int searchSep2(char x[], HT2 *hashtable[])
{
    HT2 *node = hashtable[hash2(x)];
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

char* searchSepAlias(char x[], HT2 **hashtable)
{
    HT2 *node = hashtable[hash2(x)];
    printf("%d\n",hash2(x));
    int i = 0;
    while (node != NULL)
    {
        if ((strcmp(node->Alias, x) == 0))
        {
            return node->Address;
        }
        node = node->next;
        i++;
    }
    return NULL;
}

void insertSep2(char Address[], HT2 **hashtable, char *Alias)
{
    int pos = hash2(Alias);

    if (hashtable[pos] == NULL)
    {
        hashtable[pos] = (HT2 *)malloc(sizeof(HT2));
        hashtable[pos]->Alias = malloc(sizeof(char)*strlen(Alias));
        strcpy((hashtable[pos])->Address, Address);
        strcpy((hashtable[pos])->Alias, Alias);
        (hashtable[pos])->next = NULL;
    }
    else
    {
        HT2 *temp = (HT2 *)malloc(sizeof(HT2));
        temp->Alias=(char*) malloc(sizeof(char)*strlen(Alias));
        strcpy(temp->Address, Address);
        strcpy(temp->Alias, Alias);
        temp->next = NULL;

        HT2 *traversal = hashtable[pos];

        while (traversal->next != NULL)
        {
            traversal = traversal->next;
        }
        traversal->next = temp;
    }
}