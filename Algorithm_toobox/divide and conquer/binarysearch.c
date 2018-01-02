#include<stdio.h>
#include<stdlib.h>

long binary_search(long element, long array[], long size)
{
    long index, i, mid, low, high;
    low = 0;
    high = size;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (array[mid] == element)
            return mid;
        if (array[mid] > element)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;

}

void main()
{
    long n, k, i, j, *array, *search, result;

    scanf("%ld", &n);
    array = (long *)malloc(sizeof(long) * n);

    for (i = 0; i < n; i++)
    {
        scanf("%ld", &array[i]);
    }

    scanf("%ld", &k);
    search = (long *)malloc(sizeof(long) * k);

    for (i = 0; i < k; i++)
    {
        scanf("%ld", (search + i));
    }


    for ( i = 0; i < k; i++)
    {

        result = binary_search(search[i], array, n);
        printf("%ld ", result);
    }

}
