#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {
    char c;
    struct stack *next;
};
 typedef struct stack Stack;

bool isValid(char *s) {

    Stack* bottom = (Stack*)malloc(sizeof(Stack));

    bottom->next = NULL;
    bottom->c = *s++;

    while (*s) {
        
    }

}

