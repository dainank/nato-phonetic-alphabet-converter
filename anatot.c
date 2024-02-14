#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

const char *nato[] = {
    "Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot",
    "Golf", "Hotel", "India", "Juliett", "Kilo", "Lima",
    "Mike", "November", "Oscar", "Papa", "Quebec", "Romeo",
    "Sierra", "Tango", "Uniform", "Victor", "Whiskey",
    "Xray", "Yankee", "Zulu"};

char isterm(char *term)
{
    int x;
    const char *n;
    char *t;

    for (x = 0; x < 26; x++)
    {
        n = nato[x];
        t = term;
        while (*n != '\0')
        {
            if ((*n | 0x20) != (*t | 0x20))
                break;
            n++; // increments NATO alphabet
            t++; // increments letter received
        }
        if (*n == '\0')
            return (*nato[x]);
    }
    return ('\0');
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <conversion_type> <input_file>\n", argv[0]);
        exit(1);
    }

    const char *type = argv[1];
    const char *filename = argv[2];

    if (strcmp(type, "english_to_nato") == 0)
    {
        char userResponse[64];
        char singleCharacter;
        int i;
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
    else if (strcmp(type, "nato_to_english") == 0)
    {
        char phrase[64];
        char *match;
        char ch;
        printf("NATO word or phrase: ");
        fgets(phrase, 64, stdin);

        match = strtok(phrase, " ");
        while (match)
        {
            if ((ch = isterm(match)) != '\0')
                putchar(ch);
            match = strtok(NULL, " ");
        }
        putchar('\n');

        return (0);
    }
    else
    {
        fprintf(stderr, "Invalid conversion type: %s\n", type);
        exit(1);
    }

    return 0;
}
