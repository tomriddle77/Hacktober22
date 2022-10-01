// a. Implement polynomial addition using linked list
// b. Implement polynomial multiplication using linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    int coeff;
    int pow;
    struct nodeStruct *link;
} node;

void input(node **);
void display(node *);
int lowestPow(node *);
void deleteZeroTerms(node **);
void add(node *, node *, node **);
void insertAtEnd(node **, int, int);
void multiply(node *, node *, node **);
void addToCoeffAtIndex(node **, int, int);

int main()
{
    node *poly1 = NULL, *poly2 = NULL, *polySum = NULL, *polyProduct = NULL;
    printf("Sample input: 2x^3 + 5x^2 - 4x^0 should be entered as 2x3 5x2 -4x0\nThe terms entered should be in the decreasing power of x\n\n");
    input(&poly1);
    input(&poly2);
    add(poly1, poly2, &polySum);
    printf("\nSum of both polynomials: ");
    display(polySum);
    multiply(poly1, poly2, &polyProduct);
    printf("\nProduct of both polynomials: ");
    display(polyProduct);
    return 0;
}

void input(node **poly)
{
    int coeff, pow;
    char last;
    printf("Enter polynomial: ");
    do
    {
        scanf("%d%*c%d%c", &coeff, &pow, &last);
        insertAtEnd(poly, coeff, pow);
    } while (last != '\n');
}

void insertAtEnd(node **poly, int coeff, int pow)
{
    node *new = (node *)malloc(sizeof(node)), *llptr = *poly;
    new->coeff = coeff;
    new->pow = pow;
    new->link = NULL;
    if (*poly == NULL)
    {
        *poly = new;
        return;
    }
    while (llptr->link != NULL)
        llptr = llptr->link;
    llptr->link = new;
}

int lowestPow(node *poly)
{
    int pow;
    while (poly != NULL)
    {
        pow = poly->pow;
        poly = poly->link;
    }
    return pow;
}

void addToCoeffAtIndex(node **poly, int value, int index)
{
    int curIndex = 0;
    node *ptr = *poly;
    while (curIndex != index)
    {
        ptr = ptr->link;
        curIndex++;
    }
    ptr->coeff = ptr->coeff + value;
}

void deleteZeroTerms(node **polySum)
{
    node *poly = *polySum, *prev;
    while (poly != NULL)
    {
        if (poly->coeff == 0)
        {
            if (poly == *polySum)
            {
                *polySum = poly->link;
                prev = poly;
            }
            else
                prev->link = poly->link;
        }
        else
            prev = poly;
        poly = poly->link;
    }
}

void add(node *poly1, node *poly2, node **polySum)
{
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->pow > poly2->pow)
        {
            insertAtEnd(polySum, poly1->coeff, poly1->pow);
            poly1 = poly1->link;
        }
        else if (poly2->pow > poly1->pow)
        {
            insertAtEnd(polySum, poly2->coeff, poly2->pow);
            poly2 = poly2->link;
        }
        else
        {
            insertAtEnd(polySum, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
    }
    if (poly1 == NULL && poly2 == NULL)
        return;
    node *polyLeft = (poly1 != NULL) ? poly1 : poly2;
    while (polyLeft != NULL)
    {
        insertAtEnd(polySum, polyLeft->coeff, polyLeft->pow);
        polyLeft = polyLeft->link;
    }
}

void multiply(node *poly1, node *poly2, node **polySum)
{
    int i, highestPow = poly1->pow + poly2->pow, lp1 = lowestPow(poly1), lp2 = lowestPow(poly2);
    for (i = highestPow; i >= lp1 + lp2; i--)
        insertAtEnd(polySum, 0, i);
    while (poly1 != NULL)
    {
        node *p2 = poly2;
        while (p2 != NULL)
        {
            addToCoeffAtIndex(polySum, poly1->coeff * p2->coeff, highestPow - poly1->pow - p2->pow);
            p2 = p2->link;
        }
        poly1 = poly1->link;
    }
    deleteZeroTerms(polySum);
}

void display(node *poly)
{
    node *llptr = poly;
    while (llptr != NULL)
    {
        printf("%c %dx^%d ", (llptr->coeff < 0) ? '-' : '+', abs(llptr->coeff), llptr->pow);
        llptr = llptr->link;
    }
}

/*
Sample input: 2x^3 + 5x^2 - 4x^0 should be entered as 2x3 5x2 -4x0
The terms entered should be in the decreasing power of x

Enter polynomial: 2x3 5x2 -4x0
Enter polynomial: 6x3 1x2

Sum of both polynomials: + 8x^3 + 6x^2 - 4x^0
Product of both polynomials: + 12x^6 + 32x^5 + 5x^4 - 24x^3 - 4x^2
*/
