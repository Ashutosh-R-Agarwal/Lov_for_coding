#include<stdio.h>
#include<stdlib.h>

// UNIQUE ELEMENTS
static unsigned long index = 0;
unsigned long partition(unsigned long array[], unsigned long low, unsigned long high)
{
    unsigned long element, i , j, temp;


    element = array[0];
    j = high - 1;
    printf("\nBefore");
    for(i = low; i < high; i++)
        printf("%lu ", array[i]);

    // HERE IS UNIQUE
 /*   while(element < array[j])
    {
        j--;
    }
    for (i = 1; i < high; i++)
    {

    }*/
    i = low + 1;
    while (1)
    {
        while(element > array[i])
        {
            i++;
        }
        while(element < array[j])
        {
            j--;
        }
        if (i >= j)
            break;
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    temp = array[j];
    array[j] = element;
    array[low] = temp;


    printf("\nINDEX : %lu\n", index++);

    for(i = low; i < high; i++)
        printf("%lu ", array[i]);
    return j;

}


void quicksort(unsigned long array[], unsigned long low, unsigned long high)
{
    unsigned long pivot;
    if (low >= high)
        return;
    pivot = partition(array, low, high);
    printf("\nPIVOT IS : %lu and element : %lu", pivot, array[pivot]);

  //  prunsigned longf("\nPIVOT IS : %d", pivot);
    if (pivot > low && pivot < high) {
        quicksort(array, low, pivot - 1);
        quicksort(array, pivot + 1, high);
    }

}


void main()
{
    unsigned long array[100], n, i;
    //prunsigned longf("\nEnter the number of elements:");
    scanf("%lu", &n);

    for(i=0; i < n; i++)
    {
        scanf("%lu",&array[i]);

    }
    quicksort(array, 0, n -1);
   // prunsigned longf("\nSORTED ARRAY:\n");
    for(i = 0; i < n; i++)
        printf("%d ", array[i]);
}
