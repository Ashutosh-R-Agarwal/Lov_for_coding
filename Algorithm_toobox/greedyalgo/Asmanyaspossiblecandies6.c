#include<stdio.h>
#include<stdlib.h>

void main()
{
    long n, temp;
    int array[1000000] = { 0 };
    int index;
    int sub, i;
    scanf("%lu",&n);
   // printf("Entered number is: %lu",n);
    temp = n;
   // printf("\nTemp is : %lu", temp);
    //printf("\nEntered Number is: %lu", n);
    index = 0;
    sub = 1;
    if (temp <= 2) {
        printf("1\n");
        printf("%lu",temp);
    }
    else {
        while(1)
        {
            array[index] = sub;
            temp = temp - array[index];
         //   printf("\nIndex is : %d, Element inserted is: %d and temp is : %lu", index, array[index], temp);

            if (array[index] < temp)
            {
                sub++;
                index++;

            }else if (temp != 0){
                // Real square, Example = 8;

                array[index] = array[index] + temp;
     //           printf("\n IN ELSE : %d", array[index]);

                //index--;
                break;
            } else
            {
                // PERFECT SQUARE, Evenly divisible, Example = 6
                break;
            }

        }
        printf("%d\n",index+1);
        for(i = 0; i <= index; i++)
        {
            printf("%d ", array[i]);
        }
    }
}
