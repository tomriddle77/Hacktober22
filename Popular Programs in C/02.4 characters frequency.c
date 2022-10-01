// Write a program to print normalized frequency of occurrence of characters in an array

#define MAX_CHARS 100
#include <stdio.h>
#include <string.h>

void normalizedFreq(char *s);

int main()
{
    char string[MAX_CHARS];
    printf("Enter a character array (string): ");
    scanf("%[^\n]",string);
    normalizedFreq(string);
    return 0;
}


void normalizedFreq(char *s)
{
    int upper[26]={0}, lower[26]={0}, i;
    while(*s)
    {
        if(*s>='a' && *s<='z') lower[*s-'a']++;
        else if(*s>='A' && *s<='Z') upper[*s-'A']++;
        s++;
    }
    for(i=0; i<26; i++)
        if(lower[i]!=0) printf("%c:%d ",'a'+i,lower[i]);
    printf("\n");
    for(i=0; i<26; i++)
        if(upper[i]!=0) printf("%c:%d ",'A'+i,upper[i]);
}
