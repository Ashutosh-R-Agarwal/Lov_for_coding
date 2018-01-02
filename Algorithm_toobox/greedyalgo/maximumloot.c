#include<stdio.h>
#include<stdlib.h>

void main()
{
    int num;
    unsigned int w, *weight, *value;
    float added_wieght = 0, added_value = 0;
    unsigned int j, k;
    int i, index;
    float temp, *temparray, tempw, caldiff;

    scanf("%d", &num);
    scanf("%u", &w);

    weight = (unsigned int *)(malloc (num * sizeof(unsigned int)));
    value = (unsigned int *)(malloc (num * sizeof(unsigned int)));
    temparray = (float *)(malloc (num * sizeof(float)));

    for (i = 0; i < num; i++) {
        scanf("%u", &value[i]);
        scanf("%u", &weight[i]);
        temparray[i] = value[i] / weight[i];
    }

    //printf("\nNumber of objects are : %d", num);
    //printf("\nMaximum weight is : %u", w);

   // for (i = 0; i < num; i++) {
     //   printf("\nValue at i : %d is :%u", i, value[i]);
     //   printf("\nWeight at i : %d is :%u", i, weight[i]);
   // }


    for(i = 0; i < num && added_wieght < w; i++) {
       index = -1;
       temp = 0;
       for(j = 0; j < num; j++) {
           if(temp < temparray[j]) {
               temp = temparray[j];
               index = j;
           }
       }
           // break;
       }

       temparray[index] = 0;
    }
    printf("%f", added_value);
}
