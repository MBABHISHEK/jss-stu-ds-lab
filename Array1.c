#include <stdio.h>
#include <stdlib.h>
int n = 0, size;
int *insertbypos(int *p)
{
    if (n == size)
    {
        printf("Array Full\nReallocating\n");

        p = ((int *)realloc(p, 2 * size));
        size = size * 2;
    }
    int pos;
L1:
    printf("Enter Position between 1 to %d : ", n + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1)
        goto L1;
    int i;
    for (i = n - 1; i >= pos - 1; i--)
    {
        *(p + i + 1) = *(p + i);
    }
    int item;
    printf("Enter The Item : ");
    scanf("%d", &item);
    *(p + i + 1) = item;
    n++;
    return p;
}
void display(int *p)
{
    if (n == 0)
    {
        printf("Empty\n");
        return;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", *(p + i));
    printf("\n");
}
void reverse(int *p)
{
    int temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = *(p + i);
        *(p + i) = *(p + n - i - 1);
        *(p + n - i - 1) = temp;
    }
}
void deletebykey(int *p)
{
    if (n == 0)
    {
        printf("Empty\n");
        return;
    }
    int item;
    printf("Enter The Item : ");
    scanf("%d", &item);
    for (int i = 0; i < n; i++)
    {
        if (*(p + i) == item)
        {
            for (int j = i; j < n - 1; j++)
            {
                *(p + j) = *(p + j + 1);
            }
            n--;
            return;
        }
    }
    printf("Key Not Found\n");
}
void searchbykey(int *p)
{
    if (n == 0)
    {
        printf("Empty\n");
        return;
    }
    int item;
    printf("Enter The Item : ");
    scanf("%d", &item);
    for (int i = 0; i < n; i++)
    {
        if (*(p + i) == item)
        {

            printf("Element Found\n");
            return;
        }
    }
    printf("Element Not Found\n");
}
void searchbypos(int *p)
{
    if (n == 0)
    {
        printf("Empty\n");
        return;
    }
    int pos;
L1:
    printf("Enter Position between 1 to %d : ", n);
    scanf("%d", &pos);
    if (pos < 1 || pos > n)
        goto L1;
    printf("Eleement is : %d\n", *(p + pos - 1));
}
void main()
{
    printf("Enter The Size of Array : ");
    scanf("%d", &size);
    int *A = (int *)malloc(size * sizeof(int));
    int ch;
    for (;;)
    {
        printf("1.Insert By Position\n2.Delete By Key\n3.Search By Pos\n4.Reverse\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            A = insertbypos(A);
            display(A);
            break;
        case 2:
            deletebykey(A);
            display(A);
            break;
        case 3:
            searchbypos(A);
            break;
        case 4:
            reverse(A);
            display(A);
            break;
        default:
            exit(0);
        }
    }
}
