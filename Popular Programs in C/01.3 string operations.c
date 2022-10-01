// WAP in C to enter a string, find the length, reverse it, and change the case

#include <stdio.h>
#include <string.h>
#define MAXCHARS 100

void reverse(char *string, int length);
void changeCase(char *string, int length);

int main()
{
    int length;
    char string[MAXCHARS];

    printf("Enter string: ");
    scanf("%[^\n]",string);

    length = strlen(string);
    printf("Length of the string: %d\n",length);

    reverse(string,length);
    printf("String reversed: %s\n",string);

    changeCase(string,length);
    printf("Case changed: %s\n",string);

    return 0;
}

void reverse(char *string, int length)
{
    int i;
    char temp;
    for(i=0; i<(length-1)/2; i++)
    {
        temp=string[i];
        string[i]=string[length-1-i];
        string[length-1-i]=temp;
    }
}

void changeCase(char *string, int length)
{
    int i;
    for(i=0; i<length; i++)
    {
        if(string[i] >= 'a' && string[i] <= 'z') string[i]='A'+string[i]-'a';
        else if(string[i] >= 'A' && string[i] <= 'Z') string[i]='a'+string[i]-'A';
    }
}
