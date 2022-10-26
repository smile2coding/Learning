#include "stdio.h"

int traversalSearch(int arr[], int len, int val, int *index)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == val)
        {
            *index = i;
            return 0;
        }
    }
    return -1;
}

int main()
{
    int testArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int index = -1;
    if (traversalSearch(testArray, 10, 9, &index) == 0)
    {
        printf("find successfully!\r\n");
        printf("index:%d", index + 1);
    }
    else
    {
        printf("find failure!\r\n");
    }
    while (1)
        ;

    return 0;
}