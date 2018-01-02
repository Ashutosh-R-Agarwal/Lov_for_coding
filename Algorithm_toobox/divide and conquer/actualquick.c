#include<stdio.h>
#include<stdlib.h>

unsigned long swap(unsigned long array[], unsigned long x, unsigned long y)
{
    unsigned long temp;
    temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}

unsigned long partition(unsigned long array[], unsigned long low, unsigned long high)
{
    unsigned long i, j, pivot;

    j = low;
    pivot = array[low];
    for(i = low +1; i <= high; i++)
    {
        if(pivot >= array[i])
        {
            j++;
            if(j != i)
            {
                swap(array, i ,j);
            }
        }
    }
//    if(j == high)
  //  swap(array, low, j );
    //else
        swap(array, low, j);
    return j;
}


void quicksort(unsigned long array[], unsigned long low, unsigned long high)
{

    unsigned long pivot, i;
    if(low >= high)
        return;
    pivot = partition(array, low, high);
    //prunsigned longf("In quciksort \n");
    //for(i = 0; i < 5; i++)
      //  prunsigned longf("%d ", array[i]);
    if (pivot != 0)
    quicksort(array, low, pivot - 1);
    quicksort(array, pivot  + 1, high);
}

void main()
{
    unsigned long i, n, *array;
    scanf("%lu", &n);
    array = (unsigned long *)(malloc(sizeof(unsigned long) * n));
    for(i = 0; i < n ; i++)
        scanf("%lu", &array[i]);

    quicksort(array, 0, n-1);
    for(i = 0; i < n; i++)
        printf("%lu ", array[i]);
}
