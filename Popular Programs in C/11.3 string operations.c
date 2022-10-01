#include <stdio.h>
#define MAX_CHARS 200

void read(char *string);
int length(char *string);
int compare(char *s1, char *s2);
void concat(char *s1, char *s2);
int position(char *s1, char *s2);
char getChar(char *string, int index);
void putChar(char *string, int index, char ch);
void delete (char *string, int index, int charCount);
char *subString(char *string, int startIndex, int length);

void main()
{
    char string[MAX_CHARS], temp[MAX_CHARS];
    int choice, index, len;
    printf("Enter string: ");
    read(string);
loop:
    printf("\n1: Length\n2: Substring\n3: Display\n4: Compare\n5: Concatenate\n6: Position\n7: Delete\n\nEnter your choice: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        printf("Length of string: %d\n", length(string));
        goto loop;
    case 2:
        printf("Enter starting index and substring length: ");
        scanf("%d %d", &index, &len);
        printf("Substring: %s\n", subString(string, index, len));
        goto loop;
    case 3:
        printf("String: %s\n", string);
        goto loop;
    case 4:
        printf("Enter string to compare: ");
        read(temp);
        if (!compare(string, temp))
            printf("Both are equal\n");
        else
            printf("Both are not equal\n");
        goto loop;
    case 5:
        printf("Enter string to concatenate: ");
        read(temp);
        concat(string, temp);
        printf("String concatenated\n");
        goto loop;
    case 6:
        printf("Enter substring to search the position of: ");
        read(temp);
        index = position(string, temp);
        if (index == -1)
            printf("Substring not found\n");
        else
            printf("Substring found at index %d\n", index);
        goto loop;
    case 7:
        printf("Enter starting index and total characters to delete: ");
        scanf("%d %d", &index, &len);
        delete (string, index, len);
        printf("Deleted\n");
    }
}

char getChar(char *string, int index)
{
    return string[index];
}

void putChar(char *string, int index, char ch)
{
    string[index] = ch;
}

void read(char *string)
{
    fflush(stdin);
    scanf("%[^\n]", string);
    fflush(stdin);
}

int length(char *string)
{
    int count = 0;
    while (*string)
    {
        count++;
        string++;
    }
    return count;
}

char *subString(char *string, int startIndex, int length)
{
    char *subStr = (char *)malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++)
        subStr[i] = string[startIndex + i];
    subStr[length] = '\0';
    return subStr;
}

int compare(char *s1, char *s2)
{
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
            return *s1 - *s2;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

void concat(char *s1, char *s2)
{
    while (*s1 != '\0')
        s1++;
    while (*s2 != '\0')
    {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}

int position(char *s1, char *s2)
{
    int lenOfS1 = length(s1), lenOfS2 = length(s2), isEqual;
    for (int i = 0; i < lenOfS1; i++)
    {
        isEqual = 1;
        for (int j = 0; j < lenOfS2; j++)
            if (s1[i + j] != s2[j])
            {
                isEqual = 0;
                break;
            }
        if (isEqual)
            return i;
    }
    return -1;
}

void delete (char *string, int index, int charCount)
{
    int lenStr = length(string), diff = index + charCount;
    for (int i = diff; i <= lenStr; i++)
        string[i - charCount] = string[i];
}