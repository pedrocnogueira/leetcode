#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stack {
    char c;
    struct stack *next;
};
 typedef struct stack Stack;

bool isClosingOf(char c, char s) {
    if (c == '(' && s ==')') return true;
    if (c == '{' && s =='}') return true;
    if (c == '[' && s ==']') return true;

    return false;
}

bool isValid(char *s) {

    Stack* bottom = (Stack*)malloc(sizeof(Stack));

    bottom->next = NULL;
    bottom->c = *s++;

    Stack* currentStack = bottom;

    while (*s) {
        char current = *s;
        if (current =='(' || current == '[' || current == '{') {
            Stack *new = (Stack *)malloc(sizeof(Stack));

            new->next = currentStack;
            new->c = current;

            currentStack = new;
        }
        else if (isClosingOf(currentStack->c, current))
        {
            Stack* buffer = currentStack;

            currentStack = currentStack->next;
            free(buffer);
        }
        else
        {
            while (currentStack != NULL) {
                Stack* next = currentStack->next;
                free(currentStack);
                currentStack = next;
            }

            return false;
        }

        s++;
    }

    if (currentStack == NULL) return true;
    return false;
}

int main()
{
    char *examples[] = {"()", "()[]{}", "(]", "([])"};
    bool expected[] = {true, true, false, true};

    for (int i = 0; i < 4; i++)
    {
        bool result = isValid(examples[i]);
        printf("Example %d: Input: %s\n", i + 1, examples[i]);
        printf("Expected: %s, Got: %s\n\n", expected[i] ? "true" : "false", result ? "true" : "false");
    }

    return 0;
}
