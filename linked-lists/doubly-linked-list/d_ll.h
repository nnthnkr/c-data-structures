#ifndef D_LL_H
#define D_LL_H

#include <stdbool.h>

// typedefs - DLL
typedef struct Node Node;
typedef struct D_LL D_LL;

// typedefs - int
typedef unsigned int uint;

// struct def
struct Node {
    Node *prev;
    int data;
    Node *next;
};

struct D_LL {
    Node *head;
    Node *tail;
    uint length;
};

// function decls
// node functions
Node* createNode(int data);
void deleteNode(Node *node);


// init
bool dll_init(D_LL **dll);                          // initialize a doubly linked list
// insert
bool dll_insert_head(D_LL *dll, int data);
bool dll_insert_tail(D_LL *dll, int data);
bool dll_insert(D_LL *dll, uint pos, int data);
bool _dll_insert_to_empty(D_LL *dll, int data);   // for internal use only
bool _dll_insert_intermediate(D_LL *dll, int data);

// update
bool dll_update(D_LL *dll, uint pos, int data);

// delete
int _dll_delete_edge_cases(D_LL *dll);
bool dll_delete_head(D_LL *dll);
bool dll_delete_tail(D_LL *dll);
bool dll_delete_intermediate(D_LL *dll, uint pos);
bool dll_delete(D_LL *dll, uint pos);

// search
Node* dll_search(D_LL *dll, int data);

// display
void dll_display(D_LL *dll);
void dll_display_reverse(D_LL *dll);

// clear (different from delete)
bool dll_clear(D_LL *dll);

// useful
bool dll_empty(D_LL *dll);
uint dll_length(D_LL *dll);

// misc
bool dll_reverse(D_LL *dll);
#endif
