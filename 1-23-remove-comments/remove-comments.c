#include <stdio.h>
#include <stdbool.h>

enum comment {SINGLE_LINE, MULTI_LINE};

int main() {
    char c, next_char;
    char comment_type;
    bool is_inside_comment = false;
    
    while ((c = getchar()) != EOF) {
        if (!is_inside_comment) {
            if (c == '/') {
                next_char = getchar();
                
                if (next_char == '/') {
                    is_inside_comment = true;
                    comment_type = SINGLE_LINE;
                } else if (next_char == '*') {
                    is_inside_comment = true;
                    comment_type = MULTI_LINE;
                } else {
                    putchar(c);
                    putchar(next_char);
                }
            } else {
                putchar(c);
            }
        } else {
            if (comment_type == MULTI_LINE &&  c == '*') {
                if (getchar() == '/') {
                    is_inside_comment = false;
                }
            } else if (comment_type == SINGLE_LINE && c == '\n') {
                is_inside_comment = false;    
                putchar('\n');                
            }
        }
    }

    return 0;
}
