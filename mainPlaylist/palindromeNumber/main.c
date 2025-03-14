#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    if (x < 10)
        return true;

    unsigned int y = 0;
    int og = x;

    while (x != 0)
    {
        y += x % 10;
        if (x >= 10) {
            y = y * 10;
        }
        x = x / 10;
    }

    return (og == y);
}

int main(void) {
    
    int x = 1001;

    if (isPalindrome(x)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}
