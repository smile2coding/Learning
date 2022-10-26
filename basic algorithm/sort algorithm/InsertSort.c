#include "stdio.h"

int directInsertSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j > 0 && j < len; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    return 0;
}

int main()
{
    int testArray[10] = {1, 4, 7, 9, 20, 12, 3, 4, 6, 7};
    directInsertSort(testArray, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n\r", testArray[i]);
    }
    while (1)
        ;
}