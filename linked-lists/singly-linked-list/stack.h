#ifndef STACK_H
#define STACK_H

#include "LL.h"
#include <stdbool.h>

typedef struct Stack Stack;       // Stack is internally just a linked list

struct Stack {
    int top;
    LL* ll;
};

// functions
// stck_init();         -> initializes a stack
// stck_empty();        -> true if stack is empty, otherwise false
// stck_push();         -> pushes an element to the top
// stck_pop();          -> pops the top element
// stck_peep();         -> returns the top element
// stck_display();      -> displays the stack (top to bottom)
// stck_clear();        -> frees the stack

bool    stck_init(Stack** s);
bool    stck_empty(Stack* s);
bool    stck_push(Stack* s, int data);
int     stck_pop(Stack* s);
int     stck_peep(Stack* s);
void    stck_display(Stack* s);
bool    stck_clear(Stack* s);

#endif
