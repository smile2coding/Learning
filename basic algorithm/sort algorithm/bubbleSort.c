#include "stdio.h"

int bubbleSort(int arr[], int len)
{
    if (arr == NULL)
    {
        return -1;
    }

    int changed = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                changed = 1;
            }
        }

        if (changed == 0)
            break;
    }

    return 0;
}

int main()
{
    int testArray[10] = {1, 4, 7, 9, 20, 12, 3, 4, 6, 7};
    bubbleSort(testArray, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n\r", testArray[i]);
    }
    while (1)
        ;
}