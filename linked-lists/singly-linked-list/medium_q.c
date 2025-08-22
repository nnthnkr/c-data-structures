#include <stdio.h>
#include "LL.h"
#include "medium_q.h"

Node* getNthNode(LL *ll, int n) { 
    // if either of below two checks pass, we return the head ptr
    // empty ll check
    if (isEmpty(ll)) {
        fprintf(stderr, "[Error]: Empty List.\n");
        fprintf(stderr, "[Info]: Try again with a non-empty list.\n");
        return ll->head;
    }

    // out of bounds check (1 based)
    if (n < 1 || n > ll->length) {
        fprintf(stderr, "[Error]: Node index out of valid bounds [%d, %d].\n", 1, ll->length);
        fprintf(stderr, "[Info]: Try again with a valid index.\n");
        return ll->head;
    }

    Node *tmp = ll->head;
    int curPos = 1;         // indexing starts from 1
    
    // not checking for tmp == NULL 
    // assuming its guaranteed that tmp will NEVER be NULL if tmp != tail->next;
    while (tmp != NULL && curPos++ < n)  tmp = tmp->next; 

    return tmp;
}

Node* getMiddleNode(LL* ll) {
    // empty check
    if (isEmpty(ll)) {
        fprintf(stderr, "[Error]: Empty List.\n");
        fprintf(stderr, "[Info]: Try again with a non-empty list.\n");
        return ll->head;
    }
    
    int middleNodeIdx = ll->length / 2;         // I should really be using uint but... anyways, output is floor(len/2);
    int curPos = 1;
    Node *tmp = ll->head;
    while (tmp != NULL && curPos++ < middleNodeIdx) tmp = tmp->next;

    return tmp; 
}
