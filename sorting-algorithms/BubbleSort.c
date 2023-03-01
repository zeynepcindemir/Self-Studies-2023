#include <stdio.h>
#define SIZE 10

void bubble(int work[], size_t size, int (*compare)(int a, int b));
int ascending(int a, int b);
int descending(int a, int b);

int main(void)
{

    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};

    printf("%s", "Enter 1 to sort in ascending order,\n"
                 "Enter 2 to sort in descending order: ");
    int order;
    scanf("%d", &order);

    puts("\nData items in original order");

    for (size_t counter = 0; counter < SIZE; ++counter)
    {
        printf("%5d", a[counter]);
    }

    if (order == 1)
    {
        bubble(a, SIZE, ascending);
        puts("\nData items in ascending order");
    }
    else
    {
        bubble(a, SIZE, descending);
        puts("\nData items in descending order");
    }

    for (size_t counter = 0; counter < SIZE; ++counter)
    {
        printf("%5d", a[counter]);
    }

    puts("\n");
}

void bubble(int work[], size_t size, int (*compare)(int a, int b))
{
    void swap(int *element1Ptr, int *element2ptr);

    for (unsigned int pass = 1; pass < size; ++pass)
    {

        for (size_t count = 0; count < size - 1; ++count)
        {

            if ((*compare)(work[count], work[count + 1]))
            {
                swap(&work[count], &work[count + 1]);
            }
        }
    }
}

void swap(int *element1Ptr, int *element2Ptr)
{
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}

int ascending(int a, int b)
{
    return b < a;
}

int descending(int a, int b)
{
    return b > a;
}

