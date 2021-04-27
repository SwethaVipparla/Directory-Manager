#ifndef __DIRECTORY__H
#define __DIRECTORY__H

typedef struct Node Node;
typedef struct Node* PtrNode;
typedef struct Tree* PtrTree;
typedef struct ListNode ListNode;
typedef struct ListNode* PtrListNode;
typedef struct HashTable HashTable;
typedef struct HashTable* PtrTable;

struct ListNode
{
    char* name;
    ListNode* next;
    char* alias;
};

struct Node
{
    Node* Parent;
    char *name;
    Node* FirstChild;
    Node* Sibling; 
    bool type;
    //PtrListNode Children;
};

// struct TreeNode
// {
//     TreeNode* Parent;
//     char *name;
//     PtrListNode Children;
//     bool type;
// };


struct Tree
{
    Node* root;
};

struct HashTable
{
};

PtrListNode MakeList();

PtrListNode MakeList();
PtrTable MakeTable();
void MakeNode(PtrTree root, char *name);
PtrTree MakeTree();

PtrNode Find(char* Prefix);

PtrNode AddFile(PtrNode current,PtrTree root, char* name);
PtrNode AddDirectory(PtrNode current, PtrTree root, char* name);

PtrNode Move(PtrTree root,PtrNode name);

int getHash(char* name);
int LookinTable(char* name, PtrTable Table);

PtrNode Teleport(char* alias);
void StoreAlias(char* Address, char* Alias);

void Quit();

#endif