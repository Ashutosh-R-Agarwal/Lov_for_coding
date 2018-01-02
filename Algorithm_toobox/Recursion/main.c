#include <stdio.h>

int m,n;

int checkall(int i, j)
{

}

int main() {
	int t;
	char mat[20][20];

	int j,k;
	int temp;
	int flag = 0;
    t = 1;
//	scanf("%d",&t);
	while(t-- > 0) {
       printf("\n Enter ROW:");
	   scanf("%d", &m);
       printf("\n Enter Column:");
	   scanf("%d", &n);
	   for(j = 0; j < m; j++) {
	       for(k = 0; k < n; k++) {
	           scanf(" %c",&mat[j][k]);
	       }
	   }

	   printf("\n Entered ROW: %d AND COLUMN : %d", m, n);

	   printf("\n Entered Elements are \n");
	   for(j = 0; j < m; j++) {
        printf("\n");
        for(k = 0; k < n; k++) {
            printf("\t %c", mat[j][k]);
        }
	   }

	   for(j = 1; j < (m - 1); j++) {
	       for(k = 1; k < (n - 1); k++) {
	           if (mat[j][k] == 'O'){
	               if (flag){
	                   mat[j][k] = 'X';
	               }

	           }

	       }
	   }
	   printf("\n OUTOUT IS\n");
	    for(j = 0; j < m; j++) {
            printf("\n");
	        for(k = 0; k < n; k++) {
	            printf("%c ", mat[j][k]);
	        }
	    }
	    printf("\n");
	}

	return 0;
}
