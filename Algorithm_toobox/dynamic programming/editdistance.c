#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int min(int i, int j, int k)
{
    if ( i <= j && i <= k)
        return i;
    else if (j <= i && j <= k)
        return j;
    else if (k <= i &&  k <= j)
        return k;
}

void main()
{
    char s[101], s1[101];
    int i, j, k, m ,n;
    //int **dp;

    int dp[102][10];
    scanf("%s",&s);


    scanf("%s",&s1);

    m = strlen(s);
    n= strlen(s1);

   // **dp = (int **)(malloc(sizeof(int) * (m +1)));

   // for (i = 0; i <= m; i++)
     //   *dp[i] = (int *)(malloc(sizeof(int) * (n+1)));

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if (s[i - 1] == s1[j - 1])
            {
                dp[i][j] = dp[i - 1][j -1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    printf("\n ARRAY : :) ");
    for(i = 0;i <= m; i++)
    {
        printf("\n");
        for(j = 0;j <= n; j++)
        {
            printf(" %d", dp[i][j]);
        }
    }

    printf("%d", dp[m][n]);
    //printf("String : %s length:%d  String : %s length: %d", s, m, s1, n);

}
