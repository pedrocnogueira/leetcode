#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    int prefSize = 0;
    char *firstStr = strs[0];

    for (int i = 0; firstStr[i]; i++)
    {

        bool isSame = true;

        for (int j = 1; j < strsSize; j++)
        {
            isSame = isSame && strs[j - 1][i] == strs[j][i];
        }

        if (isSame)
        {
            prefSize++;
        }
        else
        {
            break;
        }
    }

    char* result = (char*)malloc(prefSize + 1);

    if (!prefSize)
    {
        result[0] = '\0';
    }
    else
    {
        for (int i = 0; i < prefSize; i++)
        {
            result[i] = firstStr[i];
        }
        result[prefSize] = '\0';
    }

    return result;
}

int main() {
    char *strs[] = {"flower", "flow", "flight"};
    int strsSize = sizeof(strs) / sizeof(strs[0]);

    char *prefix = longestCommonPrefix(strs, strsSize);

    if (*prefix)
    {
        printf("\nLongest Common Prefix: %s\n", prefix);
        free(prefix); // assuming the result is dynamically allocated
    }
    else
    {
        printf("\nNo common prefix found.\n");
    }

    return 0;
}