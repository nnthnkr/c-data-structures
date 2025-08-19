#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

int main(void) {
    LL *l = NULL;
    /* initLL(&l);
    insertAtEnd(l, 24); 
    insertAtEnd(l, 32); 
    displayLL(l);
    printf("Head: %d\n", (l->head)->data);
    printf("Count: %d\n", l->length);

    int deleteVal = deleteHead(l);
    displayLL(l);
    printf("Head: %d\n", (l->head)->data);
    printf("Count: %d\n", l->length);
    printf("Deleted Val: %d\n", deleteVal);
    
    deleteVal = deleteTail(l);
    displayLL(l);
    printf("Tail: %p\n", (l->tail));
    printf("Count: %d\n", l->length);
    printf("Deleted Val: %d\n", deleteVal);
    
    displayLL(l);
    printf("length: %d\n", l->length);
    deleteTail(l);
    displayLL(l);
    printf("head: %p\n"
           "tail: %p\n"
           "length: %d\n",
           l->head, l->tail, l->length);
    printf("isEmpty? %d\n", isEmpty(l)); */
    initLL(&l);
    insertAtEnd(l, 25);
    insertAtEnd(l, 32);
    insertAtEnd(l, 75);
    insertAtEnd(l, 89);
    insertAtEnd(l, 92);
    insertAtEnd(l, 43);
    insertAtEnd(l, 57);
    displayLL(l);
    clearLL(l);
    printf("head: %p\n", l->head);
    displayLL(l);
    
    free(l);

    return 0;
}
