#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

// Node Functions
Node* createNode(int data) {
    Node *tmp = (Node *) malloc(sizeof(Node));
    if (tmp == NULL) {
        fprintf(stderr, "[ERROR]: Memory allocation to Node unsuccessful.");
        fprintf(stderr, "[Aborting]");
        return NULL;
    }

    tmp->data = data;
    tmp->next = NULL;
    
    return tmp;
}

void freeNode(Node *node) {
    fprintf(stdout, "Node[%p] freed.\n", node); 
    free(node); 
}

// (singly) Linked List Functions

void displayLL(LL *ll) {
    if (isEmpty(ll)) {
        fprintf(stderr, "[Error]: Linked List Empty.\n");
        fprintf(stderr, "[Error]: Cannot print array.\n");
        return;
    }

    Node *tmp = ll->head;
    while (tmp != NULL) {
        printf("%d", tmp->data);
        if (tmp->next != NULL)
            printf(" ");
        tmp = tmp->next;
    }
    printf("\n");
}

void reverseDisplayLL(LL* ll) {
    if (isEmpty(ll)) {
        fprintf(stderr, "[Error]: Linked List Empty.\n");
        fprintf(stderr, "[Error]: Cannot display reversed array.\n");
        return;
    }
    
    // temporary array to store data elements.
    int *elements = (int *) calloc(ll->length, sizeof(int));         // C99 (and beyond) compilers implicitly cast (void          
    if (elements == NULL) {                                          // ) to its appropriate type in assignment. 
        fprintf(stderr, "[Error]: Auxiliary array allocation failed.\n");
        fprintf(stderr, "[Error]: Linked list is too lengthy or failure of calloc.\n");
        fprintf(stderr, "[Error]: Aborting ...");
        return;
    }
                                                                     
    Node *tmp = ll->head;
    int i = 0;
    while (tmp != NULL) {
        elements[i] = tmp->data;
        tmp = tmp->next;
        i++;
    }
    // i here would be length + 1. decrement it by 1
    i--;

    while (i >= 0) {
        printf("%d", elements[i]);
        if (i != 0)
            printf(" ");
        i--;
    }
    printf("\n");
    
    // clean up the memory
    free(elements);
}

bool isEmpty(LL *ll) {
    if (ll->head == NULL)
        return true;
    return false;
}

bool initLL(LL** ll) { 
    // allocate the memory for ll 
    (*ll) = (LL *) malloc(sizeof(LL));          // sizeof **ll is also valid

    if ((*ll) == NULL) {
        fprintf(stderr, "[Error] Initialization failed.\n");
        fprintf(stderr, "[Abort]\n");
        return false;
    }
    
    // initialize internal fields.
    (*ll)->head = NULL;
    (*ll)->tail = NULL;
    (*ll)->length = 0;                          // this can be used to check whether LL is empty

    fprintf(stdout, "[Info]: Singly Linked List Initialized!!\n");
    return true;
}

bool insertAtBeginning(LL* ll, int data) {
    Node *tmp = createNode(data);
    
    if (tmp == NULL) {
        fprintf(stderr, "[Error] Initialization failed.\n");
        fprintf(stderr, "[Abort]\n");
        return false;
    } 
    
    // in case the ll is empty, both head and tail will point to this new node
    if (isEmpty(ll)) {
        ll->head = tmp;
        ll->tail = tmp;
        ll->length++;
        return true;
    }
    
    tmp->next = ll->head;
    ll->head = tmp;
    ll->length++;
    return true;
}

bool insertAtEnd(LL* ll, int data) {
    Node *tmp = createNode(data);

    if (tmp == NULL) {
        fprintf(stderr, "[Error] Initialization failed.\n");
        fprintf(stderr, "[Abort]\n");
        return false;
    }
     
    // in case the ll is empty, both head and tail will point to this new node
    if (isEmpty(ll)) {
        ll->head = tmp;
        ll->tail = tmp;
        ll->length++;
        return true;
    }

    ll->tail->next = tmp;
    ll->tail = tmp;
    ll->length++;
    
    return true;
}

// Deletion Functions
bool deleteEdgeCases(LL* ll, int *returnVal) {
    // if neither edge cases occur, then return false
    if (isEmpty(ll)) {
        fprintf(stderr, "[Error] Array empty.\n");
        fprintf(stderr, "[Error] Cannot perform delete operation.\n");
        *returnVal = 0;
        return true;
    }
    if (ll->head == ll->tail) {
        // since head == tail, we can free just one node
        // and then set both head and tail to NULL
        Node *tmp = ll->head;
        *returnVal = ll->head->data;
        // free the node
        freeNode(tmp);
        // set head and tail to NULL
        ll->head = NULL;
        ll->tail = NULL;
        ll->length = 0;
        return true;
    } 
    return false;
}
int deleteHead(LL* ll) {
    // check for edge cases first
    int returnVal = 0;
    if (deleteEdgeCases(ll, &returnVal))
        return returnVal;

    // temporary var to hold address to head
    Node *tmp = ll->head;
    // set the data val of head to returnVal
    returnVal = ll->head->data;
    // Making the head pointer point to the next to head element.
    ll->head = ll->head->next;
    // decrease the length
    ll->length -= 1;
    // free the memory address occupied by head. 
    freeNode(tmp);
    return returnVal;
}

int deleteTail(LL* ll) { 
    // check for edge cases first
    int returnVal = 0;
    if (deleteEdgeCases(ll, &returnVal))
        return returnVal;

    Node *tmp = ll->head;
    while (tmp->next != ll->tail) {
        tmp = tmp->next;
    }

    returnVal = tmp->next->data;
    freeNode(tmp->next);      // tmp->next is the tail node
    ll->tail = tmp;           // tmp (second to last) is the new tail
    ll->tail->next = NULL;    // Never forget this line. 
    ll->length -= 1;

    return returnVal;
}

// clear the linked list (basically free all the nodes)
bool clearLL(LL* ll) {
    Node *currentNode = ll->head, *prevNode;
    
    while (currentNode != NULL) {
        prevNode = currentNode;
        currentNode = currentNode->next;
        freeNode(prevNode);
    }
    // all nodes are deleted. set head = tail = null and length = 0;
    ll->head = NULL;
    ll->tail = NULL;
    ll->length = 0;
    return true;
}

// "delete" the LL.
bool deleteLL(LL* ll) {
    if (! isEmpty(ll) && ! clearLL(ll)) {
        fprintf(stderr, "[Error]: Error while freeing all nodes.\n");
        fprintf(stderr, "[Info]: Close the program to free leaked memory.\n");
        return false;
    }
    // free the memory occupied by ll ptr itself.
    free(ll);
    
    fprintf(stdout, "[Info]: Linked List cleared from memory successfully.\n");

    return true;
}

// search
//  returns position (1-based) of element in the LL
int search(LL *ll, int elem) {
    Node *tmp = ll->head;
    int pos = 1;
    while (tmp != NULL) {
        if (tmp->data == elem)
            return pos;
        tmp = tmp->next;
        pos++;
    }
    return -1;
}

// reverse
bool reverseLL(LL* ll) {
    // check if empty 
    if (isEmpty(ll)) {
        fprintf(stderr, "[Error] Cannot reverse an empty linked list.\n");
        return false;
    }
    // no need to reverse a ll with just one node
    if (ll->length == 1) {
        return true;
    }

    Node *prev = NULL, *cur = ll->head, *next = ll->head->next;
    
    while (next != NULL) {
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    
    // after the above loop completes. (nth -> last)
    //  prev -> (n-1)th node
    //  cur -> nth last node
    //  next -> null
    // So, we have to do one final ptr change so cur correctly points to prev;
    cur->next = prev;
    
    ll->tail = ll->head;
    ll->head = cur;

    return true;        // assuming everything went perfectly
}
