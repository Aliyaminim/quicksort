#include <stdio.h>
#include "sort.h"


int main()
{
    int arr[1000]; //нужно менять размер массива
    unsigned len;

    scanf("%u", &len);

    for (int i = 0; i < len; i++)
        scanf("%d", &arr[i]);

    qsort(arr, len);

    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);


    return 0;
}
