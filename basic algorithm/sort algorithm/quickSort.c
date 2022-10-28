#include "stdio.h"

int quickSort(int arr[], int left, int right)
{
    int low = left, high = right;
    int pivot = arr[low];
    if (low < high)
    {
        while (low < high)
        {
            while (low < high && pivot <= arr[high])
            {
                high--;
            }
            if (low < high)
                arr[low++] = arr[high];
            while (low < high && pivot > arr[low])
            {
                low++;
            }
            if (low < high)
                arr[high--] = arr[low];
        }
        arr[low] = pivot;
        quickSort(arr, left, low - 1);
        quickSort(arr, low + 1, right);
    }
    return 0;
}

int main()
{
    int testArray[10] = {1, 4, 7, 9, 20, 12, 3, 4, 6, 7};
    quickSort(testArray, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n\r", testArray[i]);
    }
    while (1)
        ;
}