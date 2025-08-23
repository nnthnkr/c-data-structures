#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

#if defined(medium_q)
    #include "medium_q.h"
#endif

int main(void) {
    /*
    LL* l;
    initLL(&l);
    insertAtEnd(l, 25);
    insertAtEnd(l, 32);
    insertAtEnd(l, 45);
    insertAtEnd(l, 38);
    insertAtEnd(l, 59);
    insertAtEnd(l, 14);
    displayLL(l);
    
    reverseLL(l);
    displayLL(l);
    
#if defined(medium_q)
    Node *tmp = getNthNode(l, 7);
     
    printf("Node[addr]: %p\n"
           "Node[data]: %d\n",
           tmp, tmp->data);

    tmp = getMiddleNode(l);
    
    printf("Middle Node[addr]: %p\n"
           "Middle Node[data]: %d\n",
           tmp, tmp->data);
#endif

    deleteLL(l);
    deleteLL(l2);
    */

    stack_impl();
    return 0;
}
