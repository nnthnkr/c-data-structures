#include <stdio.h>
#include <stdlib.h>

#include "d_ll.h"

int main(void) {
    D_LL *dll;
    dll_init(&dll);

    dll_insert_tail(dll, 1);
    // dll_insert_tail(dll, 2);
    // dll_insert_tail(dll, 3);
    // dll_insert_tail(dll, 4);
    dll_display(dll);    
    dll_display_reverse(dll);
    printf( "head: %p\n"
            "head->next: %p\n"
            "head->data: %d\n"
            "tail: %p\n"
            "tail->next: %p\n"
            "tail->data: %d\n",
            dll->head, dll->head->next, dll->head->data, dll->tail, dll->tail->next, dll->tail->data);

    dll_reverse(dll);
    
    printf( "head: %p\n"
            "head->next: %p\n"
            "head->prev: %p\n"
            "head->data: %d\n"
            "tail: %p\n"
            "tail->next: %p\n"
            "tail->prev: %p\n"
            "tail->data: %d\n",
            dll->head, dll->head->next, dll->head->prev, dll->head->data, 
            dll->tail, dll->tail->next,dll->tail->prev, dll->tail->data);

    dll_display(dll);
    dll_delete_head(dll);
    dll_delete_head(dll);
    dll_delete_head(dll);
    dll_delete_head(dll);
    dll_delete_head(dll);

    dll_insert_head(dll, 25);
    dll_insert_head(dll, 29);
    dll_insert_head(dll, 42);
    dll_insert_head(dll, 37);
    dll_insert_head(dll, 144);
    
    dll_display(dll);
    dll_reverse(dll);
    dll_display(dll);


    dll_delete_head(dll);
    dll_delete_head(dll);
    dll_delete_head(dll);
    dll_delete_head(dll);
    dll_delete_head(dll);
    dll_delete_head(dll);
    
    free(dll);
    return 0;
}

