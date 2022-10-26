#include "stdio.h"

int binarySearch(int arr[], int len, int val, int *index)
{
    int left = 0, right = len;
    while (left < right)
    {
        if (arr[(left + right) / 2] == val)
        {
            *index = (left + right) / 2;
            return 0;
        }

        if (arr[(left + right) / 2] < val)
        {
            left = (left + right) / 2 + 1;
        }
        else
        {
            right = (left + right) / 2 - 1;
        }
    }
    return -1;
}

int main()
{
    int testArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index = -1;
    if (binarySearch(testArray, 10, 9, &index) == 0)
    {
        printf("find successfully!\r\n");
        printf("index:%d", index+1);
    }
    else
    {
        printf("find failure!\r\n");
    }
    while (1)
        ;

    return 0;
}