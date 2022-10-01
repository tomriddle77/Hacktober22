// WAP in C to enter a string, find length with out using predefined functions

#include <stdio.h>
#define MAXCHARS 100

int customLen(char *s);

int main()
{
    char string[MAXCHARS];

    printf("Enter string: ");
    scanf("%[^\n]",string);
    printf("Length of the string: %d\n",customLen(string));

    return 0;
}

int customLen(char *s)
{
    int length=0;
    while(*s)
    {
        length++;
        s++;
    }
    return length;
}
