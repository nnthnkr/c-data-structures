#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "LL.h"

// function defs
bool stck_init(Stack** s) {
    (*s) = (Stack *) malloc(sizeof(Stack));
    
    if (*s == NULL) {
        fprintf(stderr, "[ERROR]: Stack initialization failed.\n");
        return false;
    }

    if(! initLL(&((*s)->ll)))    return false;
    (*s)->top = 0;          // by default top is 0
    return true;
};

bool stck_empty(Stack* s) {
    return (isEmpty(s->ll));
}

bool stck_push(Stack* s, int data) {
    if (!insertAtBeginning(s->ll, data))    return false;
    s->top = data;
    return true;
}

int stck_pop(Stack* s) {
    if (stck_empty(s))  return s->top;
    int tmp = s->ll->head->data;        // current head's data
    deleteHead(s->ll);
    
    // if after popping the current element, the stack is empty, set top to 0. else to the value
    // of the current top node
    if (stck_empty(s)) {
        s->top = 0;
    } else {
        s->top = s->ll->head->data;
    }

    return tmp;
}

int stck_peep(Stack* s) {
    return s->top;
}

void stck_display(Stack* s) {
    if (!stck_empty(s)) displayLL(s->ll);
}

bool stck_clear(Stack* s) {
    // delete the internal linked list
    if(!deleteLL(s->ll) || s == NULL) return false;

    // free the memory s points to.
    free(s);
    return true;
};
