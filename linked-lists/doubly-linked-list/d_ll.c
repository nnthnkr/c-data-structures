#include <stdio.h>
#include <stdlib.h>

#include "d_ll.h"

// node functions
Node* createNode(int data) {
    Node *tmp = (Node *) malloc(sizeof(Node));

    if (tmp == NULL) {
        fprintf(stderr, 
                "[ERROR]: Memory allocation failure.\n"
                "[ERROR]: Node creation failed.\n"
                "[INFO]: NULL returned.\n");
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
        fprintf(stderr, 
                "[ERROR]: Memory allocation failure.\n"
                "[ERROR]: d-Linked List not initialized.\n"
                "[INFO]: d-Linked List pointer points to NULL.\n");
        return true;
    }

    (*dll)->head = NULL;
    (*dll)->tail = NULL;
    (*dll)->length = 0;

    return false;
}

// insert
bool dll_insert(D_LL *dll, uint pos, int data) {
    // NOTE: 0 is reserved to represent the last element
    // -1 would've made more sense but pos is declared to be an unsigned int
    //
    // TODO: Come up with some other less terrible alternative
    // UPDATE: I'll allow both 0 and dll->length to represent the tail.

    // bounds checking (negatives not possible since they'd be converted to unsigned upper bound which is positive
    if (pos > dll->length) {
        fprintf(stderr,
                "[ERROR]: Invalid bounds provided\n"
                "[ERROR]: No insertition done\n"
                "[INFO]: Valid bounds are [%u, %u]\n",
                0, dll->length);
        return false;
    } 

    if (pos == 1) {
        return dll_insert_head(dll, data);
    }

    if (pos == 0 || pos == dll->length) {
        return dll_insert_tail(dll, data);
    }

    return _dll_insert_intermediate(dll, pos, data);
}

bool dll_insert_head(D_LL *dll, int data) {
    // if the dll is initially empty, call _dll_insert_to_empty func
    if (dll_empty(dll)) {
        return _dll_insert_to_empty(dll, data);
    }
    
    Node *node = createNode(data);
    if (node == NULL) { return false; }

    node->next = dll->head;
    dll->head->prev = node;
    dll->head = node;
    dll->length += 1U;
    
    fprintf(stdout, 
            "[INFO]: Successfully inserted node (%p) as the new head.\n", 
            node);

    return true;
}
bool dll_insert_tail(D_LL *dll, int data) {
    // if the dll is initially empty, call _dll_insert_to_empty func
    if (dll_empty(dll)) {
        return _dll_insert_to_empty(dll, data);
    }
    
    Node *node = createNode(data);
    if (node == NULL) { return false; }
    
    dll->tail->next = node;
    node->prev = dll->tail;
    dll->tail = dll->tail->next;
    dll->length += 1U;

    fprintf(stdout, 
            "[INFO]: Successfully inserted node (%p) as the new tail.\n", 
            node);

    return true;

}

bool _dll_insert_to_empty(D_LL *dll, int data) {
    Node *node = createNode(data);
    if (node == NULL) { return false; }

    dll->head = node;
    dll->tail = node;
    dll->length += 1U;
    
    fprintf(stdout, 
            "[INFO]: Successfully created node (%p)\n"
            "[INFO]: and inserted to the new d-Linked List\n",
            node);

    return true;
}

bool _dll_insert_intermediate(D_LL *dll, uint pos, int data) {
    // stop right before pos and insert the new node as the next to current node
    Node *node = createNode(data);
    if (node == NULL) { return false; } 

    uint cur = 1;
    Node *tmp = dll->head;
    while (tmp != NULL) {
        if (cur == pos - 1)
            break;
        tmp = tmp->next;
        cur++;
    }

    node->next = tmp->next;
    node->prev = tmp;

    tmp->next       = node;
    tmp->next->prev = node;
    
    dll->length += 1U;
    
    fprintf(stdout,
            "[INFO]: Successfully created node (%p)" 
            "and inserted at position %u\n",
            node, pos);

    return true;
}

// update
bool dll_update(D_LL *dll, uint pos, int data) {
    // bounds checking
    if (pos > dll->length) {    
        fprintf(stderr,
                "[ERROR]: Invalid bounds provided\n"
                "[ERROR]: No updation done\n"
                "[INFO]: Valid bounds are [%u, %u]\n",
                0, dll->length);
        return false;
    }
    
    if (pos == 1) {
        return dll_update_head(dll, data);
    }
    if (pos == 0) {
        return dll_update_tail(dll, data);
    }

    return _dll_update_intermediate(dll, pos, data);
}

bool dll_update_head(D_LL *dll, int data) {
    if (dll_empty(dll)) {
        return dll_insert_head(dll, data);
    }

    dll->head->data = data;
    return true;
}

bool dll_update_tail(D_LL *dll, int data) {
    if (dll_empty(dll)) {
        return dll_insert_tail(dll, data);
    }

    dll->tail->data = data;
    return true;
}

bool _dll_update_intermediate(D_LL *dll, uint pos, int data) {
    uint cur = 1;
    Node *tmp = dll->head;
    
    while (cur < pos) {
        tmp = tmp->next;
        cur++;
    }
    
    // when above loop ends tmp will be pointing to the pos'th node
    tmp->data = data;

    return true;        // redundant?
}

// delete
bool dll_delete(D_LL *dll, uint pos) {
    // NOTE: Same as dll_insert()

    // bounds checking (negatives not possible since they'd be converted to unsigned upper bound which is positive
    if (pos > dll->length) {
        fprintf(stderr,
                "[ERROR]: Invalid bounds provided\n"
                "[ERROR]: No deletion done\n"
                "[INFO]: Valid bounds are [%u, %u]\n",
                0, dll->length);
        return false;
    } 

    if (pos == 1) {
        return dll_delete_head(dll);
    }

    if (pos == 0 || pos == dll->length) {
        return dll_delete_tail(dll);
    }

    return _dll_delete_intermediate(dll, pos);
}

bool dll_delete_head(D_LL *dll) {
    int status = _dll_delete_edge_cases(dll);
    
    if (status == -1)
        return false;
    if (status == 0)
        return true;
    
    // dll has more than one element
    fprintf(stdout,
            "[INFO]: Deleting node (%p)\n",
            dll->head);
    dll->head       = dll->head->next;      // make dll->head point to the immediate next node of head
    free(dll->head->prev);                  // free the last node head was pointing to
    dll->head->prev = NULL;                 // make current head's prev pointer point to NULL
    dll->length    -= 1U;                   // decrement length counter
    fprintf(stdout,
            "[INFO]: Deleted successfully\n");
    
    return true;
}

bool dll_delete_tail(D_LL *dll) {
    int status = _dll_delete_edge_cases(dll);

    if (status == -1)
        return false;
    if (status == 0)
        return true;
    
    fprintf(stdout,
            "[INFO]: Deleting node (%p)\n",
            dll->tail);
    dll->tail       = dll->tail->prev;  
    free(dll->tail->next);              
    dll->tail->next = NULL;             
    dll->length    -= 1U;
    fprintf(stdout,
            "[INFO]: Deleted successfully\n");

    return true;
}

int _dll_delete_edge_cases(D_LL *dll) {
    /*
     * return value meanings
     *  -1 : d-Linked List was empty
     *  0  : d-Linked List had only one element and it was deleted successfully.
     *  1  : d-Linked List has more than one element
     * */
    // case 1: d-Linked List is empty
    if (dll_empty(dll)) {
        fprintf(stderr,
                "[ERROR]: d-Linked List is empty\n"
                "[ERROR]: Cannot perform delete operation\n");
        return -1;
    }

    // case 2: d-Linked List has only one element
    if (dll_length(dll) == 1) {
        // store address of node inside a temporary variable
        Node *tmp = dll->head;
        // set dll params to default values (NULL and 0)
        dll->head = NULL;
        dll->tail = NULL;
        dll->length = 0U;
        // free the node 
        fprintf(stdout, 
                "[INFO]: Deleting node (%p)\n",
                tmp);
        free(tmp);
        fprintf(stdout,
                "[INFO]: Deleted successfully\n");
        return 0;
    }

    return 1;
}

bool _dll_delete_intermediate(D_LL *dll, uint pos) {
    uint cur = 1;
    Node *tmp = dll->head, *tmp2 = NULL;
    while (tmp != NULL) {
        if (cur == pos - 1)
            break;
        tmp = tmp->next;
        cur++;
    }
     
    tmp2 = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    
    // should I decrease the length after deleting or before deleting?
    // for now I am doing it after deleting
    
    fprintf(stdout,
            "[INFO]: Deleting node (%p) from position %u\n",
            tmp2, pos);
    free(tmp2);
    dll->length -= 1U;
    
    fprintf(stdout,
            "[INFO]: Successfully deleted node\n");

    return true;
}

// display
void dll_display(D_LL *dll) {
    Node *tmp = dll->head;

    while (tmp != NULL) {
        fprintf(stdout, "%d", tmp->data);
        if (tmp->next != NULL)
            fprintf(stdout, " <-> ");
        tmp = tmp->next;
    }

    fprintf(stdout, "\n");
}

void dll_display_reverse(D_LL *dll) {
    Node *tmp = dll->tail;

    while (tmp != NULL) {
        fprintf(stdout, "%d", tmp->data);
        if (tmp->prev != NULL)
            fprintf(stdout, " <-> ");
        tmp = tmp->prev;
    }

    fprintf(stdout, "\n");
}

// search
uint dll_search(D_LL *dll, int data) {
    if (dll_empty(dll)) {
        fprintf(stderr,
                "[ERROR]: Empty d-Linked List provided\n"
                "[ERROR]: No search performed\n");
        return false;
    }

    Node *tmp = dll->head;
    uint cur = 1;

    while (tmp != NULL) {
        if (tmp->data == data) {
            return cur;
        }
        tmp = tmp->next;
        cur++;
    }

    // since position of an element can't be greater than the length of the d-Linked
    // List, length + 1 implies failure
    return dll->length + 1;         
}

// clear
bool dll_clear(D_LL *dll) {
    if (dll == NULL) {
        fprintf(stderr,
                "[ERROR]: Pointer to null provided\n"
                "[ERROR]: Clear opertion couldn't be performed\n");
        return false;
    }

    if (dll_empty(dll)) {
        free(dll);
        return true;
    }

    while (!dll_empty(dll)) {
        if (!dll_delete_head(dll)) {
            // some error occurred here
            return false;
        }
    }

    free(dll);
    return true;
}


// useful funcs
bool dll_empty(D_LL *dll) {
    return (dll->length == 0U);     /* length is unsigned */
}

uint dll_length(D_LL *dll) {
    return (dll->length);
}

// misc
bool dll_reverse(D_LL *dll) {
    /* checks */
    // check if dll is empty
    if (dll_empty(dll)) {
        fprintf(stdout,
                "[ERROR]: d-Linked List empty\n"
                "[ERROR]: Cannot reverse empty d-Linked List\n");
        return false;
    }
    
    // check if dll has only one element
    if (dll_length(dll) == 1) {
        fprintf(stdout,
                "[INFO]: d-Linked List has only one element\n"
                "[INFO]: No reversal performed\n");
        return false;
    }
      
    // for every node, we swap its next and prev pointers.
    Node *prev = NULL, *cur = dll->head, *next = dll->head->next;

    while (next != NULL) {  
        cur->prev = cur->next;
        cur->next = prev;
        
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur->next = prev;
    cur->prev = NULL;

    dll->tail = dll->head;
    dll->head = cur;
    return true;
}
