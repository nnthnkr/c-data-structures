#include <stdio.h>
#include <stdlib.h>

#include "d_ll.h"

// node functions
Node* createNode(int data) {
    Node *tmp = (Node *) malloc(sizeof(Node));

    if (tmp == NULL) {
        fprintf(stderr, "[ERROR]: Memory allocation failure.\n");
        fprintf(stderr, "[ERROR]: Node creation failed.\n");
        fprintf(stderr, "[INFO]: NULL returned.\n");
        return NULL;
    }

    tmp->next = NULL;
    tmp->prev = NULL;
    tmp->data = data;

    return tmp;
}

// init
bool dll_init(D_LL **dll) {
    (*dll) = (D_LL *) malloc(sizeof(**dll));
    
    // in case memory allocation fails
    if ((*dll) == NULL) {
        fprintf(stderr, "[ERROR]: Memory allocation failure.\n");
        fprintf(stderr, "[ERROR]: d-Linked List not initialized.\n");
        fprintf(stderr, "[INFO]: d-Linked List pointer points to NULL.\n");
        return true;
    }

    (*dll)->head = NULL;
    (*dll)->tail = NULL;
    (*dll)->length = 0;

    return false;
}

// insert
bool dll_insert_tail(D_LL *dll, int data) {
    // if the dll is initially empty, call _dll_insert_to_empty func
    if (empty(dll)) {
        return _dll_insert_to_empty(dll, data);
    }
    
    Node *node = createNode(data);
    if (node == NULL) { return false; }
    
    dll->tail->next = node;
    node->prev = dll->tail;
    dll->tail = dll->tail->next;
    dll->length += 1;

    fprintf(stdout, 
            "[INFO]: Successfully insert node (%p) as the new tail.\n", 
            node);

    return true;

}

bool _dll_insert_to_empty(D_LL *dll, int data) {
    Node *node = createNode(data);
    if (node == NULL) { return false; }

    dll->head = node;
    dll->tail = node;
    dll->length += 1;
    
    fprintf(stdout, 
            "[INFO]: Successfully created node (%p)\n"
            "[INFO]: and inserted to the new d-Linked List\n"
            node);

    return true;
}
// delete

// clear
