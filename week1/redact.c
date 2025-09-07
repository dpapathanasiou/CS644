#include <stdio.h>
#include <ctype.h>

void redact_numbers(char *string)
{
    // pointer arithmetic style, inspired by K&R's `strcpy` example
    while (*string != '\0')
    {
        isdigit(*string) ? printf("X") : printf("%c", *string);
        string++;
    }
    puts("");
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage:\n\n%s \"string\" \"string\" ... \n", argv[0]);
    }
    for (int i = 1; i < argc; i++)
    {
        redact_numbers(argv[i]);
    }
    return 0;
};
