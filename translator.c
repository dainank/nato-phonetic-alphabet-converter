#include <stdio.h>
#include <ctype.h>

int main()
{
    char userResponse[64];
    char singleCharacter;
    int i;
    const char *nato[] = {
        "Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
        "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
        "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
        "Sierra", "Tango", "Uniform", "Victor", "Whiskey",
        "Xray", "Yankee", "Zulu"};

    printf("Enter a word or phrase: ");
    fgets(userResponse, 64, stdin);

    i = 0;
    while (userResponse[i])
    {
        singleCharacter = toupper(userResponse[i]);
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