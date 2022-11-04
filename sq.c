#include <stdio.h>


unsigned partition(int *arr, unsigned low, unsigned high)
{
    unsigned i = low + 1;
    unsigned j = high;
    int key = arr[low];

    while (i < j) {
        while ((arr[i] <= key) && (i < j)) {
            arr[i - 1] = arr[i];
            arr[i] = key;
            i++;
        }

        while ((arr[j] > key) && (i < j)) {
            j--;
        }

        if (i == j) {
            if (arr[i] > key)
                return i - 1;
            else {
                arr[i - 1] = arr[i];
                arr[i] = key;
                return i;
            }
        }

        if ((j - i) == 1) {
            arr[i - 1] = arr[j];
            arr[j] = arr[i];
            arr[i] = key;
            return i;
        }

        arr[i - 1] = arr[j];
        arr[j] = arr[i];
        arr[i] = key;
        i += 1;
        j -= 1;
    }

   return i;
}

void qsort_impl(int *arr, unsigned low, unsigned high)
{
    if (low >= high)
        return;
    unsigned pi = partition(arr, low, high);
    if (pi > low)
        qsort_impl(arr, low, pi - 1);
    qsort_impl(arr, pi + 1, high);
}

void qsort(int *arr, unsigned len)
{
    qsort_impl(arr, 0u, len - 1);
}


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
