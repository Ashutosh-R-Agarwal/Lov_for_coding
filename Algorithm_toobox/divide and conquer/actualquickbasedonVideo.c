#include<stdio.h>
#include<stdlib.h>
//int array[100];

static int index = 0;
int ar[2];

void swap(int array[], int l, int r)
{
    int temp;
    printf("Before swap elements : %d : %d index : %d  %d", array[l], array[r], l, r);
    temp = array[l];
    array[l] = array[r];
    array[r] = temp;
}

void partition(unsigned long array[], unsigned long left, unsigned long right)
{
    unsigned long pivot, i ,j, k, l;
    unsigned long no_elements, temp, tmep1;
    no_elements = right - left + 1;
    unsigned long less_array[no_elements]; //= (int *)(malloc(sizeof(int) * no_elements));
    unsigned long equal_array[no_elements];// = (int *)(malloc(sizeof(int)* no_elements));
    unsigned long greater_array[no_elements];// = (int *)(malloc(sizeof(int)*no_elements));

    // smaller -------- equal ------- greater
    //        j             k                i
    // i = discovered elements / greater elements
    // j= smaller elements / last
    // k = equal elements
   // printf("\n IN PARTITION LEFT : %d AND RIGHT : %d", left, right);
    pivot = array[left];
    //j = left;
    //k = j+1;
    // less equal greater
    j = 0;
    k = 0;
    l = 0;
    //printf("\nPIVOT ELEMENTS IS : %d\n ELEMENT: ", pivot);
    for(i = left +1; i <= right; i++)
    {
        //printf(" %d", array[i]);
        if(pivot > array[i])
        {
          less_array[j] = array[i];
          j++;

        }
        else if (pivot == array[i])
        {
            equal_array[k] = array[i];
            k++;
        }
        else
        {
                greater_array[l] = array[i];
                l++;
        }
    }
    //swap(array, left, j);

    temp = 0;
    for(i = left; i < j + left; i++)
    {
        array[i] = less_array[temp];
        temp++;
    }
    temp = 0;
    for(i = j + left; i < j + k + left; i++)
    {
        array[i] = equal_array[temp];
        temp++;

    }

    array[j+k+ left] = pivot;
    temp = 0;
   // if(j+k != 0)
    //{
      //  temp = j+k +1;
    //}

    for(i = (j+k+1+left); i < (j + k + 1 + l+left); i++)
    {
        array[i] = greater_array[temp];
        temp++;
    }
    //printf("\nComplete array is:\n");
    //for(i = 0; i < j+ k+ l+left +1; i++)
    //{
     //   printf("%d ", array[i]);
    //}
    //getchar();

   // if(j >= left)
    ar[0] = j;
    //else
      //  ar[0] = left;
    //if((j+k) >= left)
    ar[1] = j+k;


    //else
    //ar[1] = left;
    //printf("\nIMPORTANT PIVOT RETURNED IS %d :%d", ar[0], ar[1]);
   // return ar;

}

void quicksort(unsigned long array[], unsigned long left, unsigned long right)
{
    unsigned long i;

    if (left >= right)
    {
        return;
    }
    if(index > 4)
    {
        return;


    }
    //printf("\nLeft is : %d and right: :%d", left, right);
    //printf("\nIndex: %d ELements are \n", index);
   // for(i = left; i <= right; i++)
    //{
    //    printf(" %d", array[i]);
    //}
    //printf("\nPartition called");
    partition(array, left, right);
    //printf("pivot is : %d :%d", ar[0], ar[1]);
    index++;

    //prf("\nQUICK SORT 1 called with left : :%d and right : %d", left, ar[0] -1);

    if(left < (ar[0])) {
     //   printf("\nQUICK SORT 1 called with left : :%d and right : %d", left, ar[0] -1);

         quicksort(array, left, ar[0] - 1);
    }
    //printf("\nQUICK SORT 2 called with left : :%d and right : %d",ar[1] + 1, right);
    if(ar[1] + 1 < right) {
   // printf("\nQUICK SORT 2 called with left : :%d and right : %d",ar[1] + 1, right);
    quicksort(array, ar[1] + 1, right);
    }

}

void main()
{
    unsigned long *array, i ,j, mid, n;

    //printintf("\nEnter number of elements : ");
    scanf("%lu",&n);
   // printf("\n Value of N is : %lu", n);
    //printf("\nEnter elements: ");
    array = (unsigned long *)(malloc(sizeof(long) * n));
    for(i = 0; i < n; i++)
    {
        scanf("%lu", &array[i]);
    }
    //printf("\n Entered array is :\n");
    //for( i = 0; i < n; i++)
      //  printf("%d ", array[i]);

    quicksort(array, 0, (n-1));
    //printf("\n\nSORTED ARRAY: \n");
    for(i = 0; i < n; i++)
    {
        printf("%lu ", array[i]);
    }
}
