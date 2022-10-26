#include "stdio.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int selectionSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int index = i;
        for (int j = i; j < len; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }
        swap(&arr[index], &arr[i]);
    }

    return 0;
}

int main()
{
    int testArray[10] = {1, 4, 7, 9, 20, 12, 3, 4, 6, 7};
    selectionSort(testArray, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n\r", testArray[i]);
    }
    while (1)
        ;
}