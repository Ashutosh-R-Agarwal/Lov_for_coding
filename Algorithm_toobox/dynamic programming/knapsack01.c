#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, k, i;
    unsigned long W = 0, **mat, w[301], temp, j;

    scanf("%llu", &W);

    scanf("%d", &n);
    mat = (unsigned long **)(malloc(sizeof(unsigned long *) * (n +1)));
    for (j = 0; j <= n; j++)
        mat[j] = (unsigned long *)(malloc (sizeof(unsigned long) * (W + 1) ));


   // for ( i = 0; i <=n; i++)
     // mat[i] = malloc((w+1) * sizeof(long long));


/*    mat = (malloc (n + 1) * (sizeof(long long)));
    for (i = 0; i < n; i++)
    {
        mat[i] = (unsigned long long)(malloc (W + 1) * (sizeof(unsigned long long)));
    }
    for ( i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            mat[i][j] = i + j;
        }
    } */
    for ( i = 1; i <= n; i++)
    {
        scanf("%llu", &w[i]);

    }

    for (i = 0; i <= n; i++)
    {
            mat[i][0] = 0;
    }

    for (j = 0; j <= W; j++)
    {
            mat[0][j] = 0;
    }
    //printf("here");

    for ( i = 1; i <= n; i++)
    {
        for ( j = 1; j <= W; j++)
        {
           mat[i][j] = mat[i - 1][j];
      //     printf("\n i = %d, j = %d, mat[i][j] : %llu and w[i]: %llu", i, j, mat[i][j], w[i]);
           if (j >= w[i])
           {
               temp = mat[i - 1][ j - w[i]] + w[i];
        //       printf("temp value at i=%d j =%d is : %llu", i , j , temp);
               if (temp > mat[i][j])
               {
                   mat[i][j] = temp;
               }
           }
        }
    }

    printf("%llu", mat[n][W]);
    return 0;
   /* for (i = 0; i <= n; i++)
    {
        printf("\n");
        for (j = 0; j <= n; j++)
        {
            printf("i=%d j=%d  %llu ", i, j, mat[i][j - w[i]);
        }
    }*/
}
