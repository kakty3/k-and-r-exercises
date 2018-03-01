#include <stdio.h>

#define IN  1
#define OUT 0

int main() {
    char state = OUT;
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n') {
            if (state == IN) {
                state = OUT;
                putchar('\n');
            }
        } else {
            state = IN;
            putchar(c);
        }
    }
}
