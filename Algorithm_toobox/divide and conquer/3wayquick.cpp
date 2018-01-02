// C++ program for 3-way quick sort
#include <bits/stdc++.h>
using namespace std;

/* This function partitions a[] in three parts
   a) a[l..i] contains all elements smaller than pivot
   b) a[i+1..j-1] contains all occurrences of pivot
   c) a[j..r] contains all elements greater than pivot */
void partition(long long a[], long long l, long long r, long long &i, long long &j)
{
    i = l-1, j = r;
    long long p = l-1, q = r;
    long long v = a[r];

    while (true)
    {
        // From left, find the first element greater than
        // or equal to v. This loop will definitely terminate
        // as v is last element
        while (a[++i] < v);

        // From right, find the first element smaller than or
        // equal to v
        while (v < a[--j])
            if (j == l)
                break;

        // If i and j cross, then we are done
        if (i >= j) break;

        // Swap, so that smaller goes on left greater goes on right
        swap(a[i], a[j]);

        // Move all same left occurrence of pivot to beginning of
        // array and keep count using p
        if (a[i] == v)
        {
            p++;
            swap(a[p], a[i]);
        }

        // Move all same right occurrence of pivot to end of array
        // and keep count using q
        if (a[j] == v)
        {
            q--;
            swap(a[j], a[q]);
        }
    }

    // Move pivot element to its correct index
    swap(a[i], a[r]);

    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    j = i-1;
    for (long long k = l; k < p; k++, j--)
        swap(a[k], a[j]);

    // Move all right same occurrences from end
    // to adjacent to arr[i]
    i = i+1;
    for (long long k = r-1; k > q; k--, i++)
        swap(a[i], a[k]);
}

// 3-way partition based quick sort
void quicksort(long long a[], long long l, long long r)
{
    if (r <= l) return;

    long long i, j;

    // Note that i and j are passed as reference
    partition(a, l, r, i, j);

    // Recur
    quicksort(a, l, j);
    quicksort(a, i, r);
}


// Driver program
int main()
{
    long long *a;
    long long n, i;
    // = sizeof(a) / sizeof(long long);
    scanf("%lld", &n);
    a = (long long *)(malloc(sizeof(long long) * n));
    for(i = 0; i < n; i++)
    {
        scanf("%lld" , &a[i]);
    }

   // prlong longarr(a, n);
    quicksort(a, 0, n - 1);
    //prlong longarr(a, n);
    for (long long i = 0; i < n; ++i)
        printf("%d  ", a[i]);

    return 0;

}
