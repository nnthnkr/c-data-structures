// 2. RF to enter a line of text and display it in reverse order without storing the text in an array.
// Example:
//  read_and_reverse_display();
//      Enter string: hello
//      Output: olleh

#include <stdio.h>

void read_and_reverse_display();    // helper
void f(char cur_char);

int main(void) {
    read_and_reverse_display();
    return 0;
}

void read_and_reverse_display() {
    f('\0');
    printf("\n");
}

void f(char cur_char) {
    if (cur_char == '\n') { return; }
    
    cur_char = getchar();
    f(cur_char);
    putchar(cur_char);
}
