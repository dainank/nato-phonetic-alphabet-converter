#include <stdio.h>
#include <ctype.h>
#include "alphabet.h"

int main()
{
    char userResponse[64];
    char singleCharacter;
    int i;

    printf("Enter a word or phrase: ");
    fgets(userResponse, 64, stdin);

    i = 0;
    while (userResponse[i])
    {
        singleCharacter = toUpper(userResponse[i]);
        if (isalpha(singleCharacter))
        {
            printf("%s ", nato[singleCharacter - 'A']);
        }
        i++;
        if (i == 64)
            break;
    }
    putchar('\n');
    return 0;
}