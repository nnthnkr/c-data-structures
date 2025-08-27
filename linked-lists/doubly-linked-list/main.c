#include <stdio.h>
#include <stdlib.h>

#include "d_ll.h"

int main(void) {
    D_LL *dll;
    dll_init(&dll);
    
    /*
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
    */
    dll_insert(dll, 1, 26);
    dll_insert(dll, 0, 59);
    dll_insert(dll, 0, 15);
    dll_insert(dll, 0, 59);
    dll_insert(dll, 0, 92);
    dll_insert(dll, 0, 85);
    dll_insert(dll, 6, 69);
    dll_insert(dll, 2, 42);
    dll_insert(dll, 3, 373);

    dll_display(dll);
    dll_reverse(dll);
    dll_display(dll);
    
    dll_delete(dll, 1);
    dll_delete(dll, dll->length);

    dll_display(dll);

    printf("Position of 59: %u\n", dll_search(dll, 59));
    printf("Position of 26: %u\n", dll_search(dll, 26));
    printf("Position of 69: %u\n", dll_search(dll, 69));
    printf("Position of 6969: %u\n", dll_search(dll, 6969));  

    dll_update(dll, 1, 69);
    dll_update(dll, 0, 69);
    dll_update(dll, 42, 1234);
    dll_update(dll, 3, 369);
    
    printf("Position of 69: %u\n", dll_search(dll, 69));
    printf("Position of 6969: %u\n", dll_search(dll, 6969));  

   
    dll_display(dll);
    
    dll_clear(dll);

   return 0;
}

