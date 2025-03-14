#include <stdio.h>

int charRomanToInt(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
    default:
        return 0;
        break;
    }
}

int romanToInt(char *s)
{
    int result = 0;

    while (*s)
    {
        int current = charRomanToInt(*s);
        s++;
        int next = charRomanToInt(*s);

        int toAdd = current;

        if (current < next)
        {
            toAdd = next - current;
            s++;
        }

        result += toAdd;
    }

    return result;
}

int main(void){

    char s[] = "III";

    printf("%d\n", romanToInt(s));

    return 0;

}