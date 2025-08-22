#ifndef LL_h
#define LL_h

#include <stdbool.h>

typedef struct Node Node;
typedef struct LL LL;

struct Node {
    int data;
    Node *next;
};

struct LL {
    Node* head;
    Node* tail;
    int length;
};

// Node Functions
Node* createNode(int data);
void freeNode(Node *node);

// (singly) Linked List Functions
// Helpers
void displayLL(LL* ll);
void reverseDisplayLL(LL* ll);
bool isEmpty(LL* ll);
bool initLL(LL** ll);
bool clearLL(LL* ll);
// Insertion
bool insertAtBeginning(LL* ll, int data);
bool insertAtPosition(LL* ll, int data, int position);
bool insertAtEnd(LL* ll, int data);
// Deletion
int deleteHead(LL* ll);
int deleteTail(LL* ll);
bool deleteEdgeCases(LL* ll, int *returnVal);
// Search
int search(LL* ll, int elem);

// Reverse
bool reverseLL(LL* ll);

// Clear & Delete
bool clearLL(LL* ll);
bool deleteLL(LL* ll);
#endif
