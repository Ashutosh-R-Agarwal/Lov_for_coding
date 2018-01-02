#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<iostream>
int main()
{
    std::string s;
    int i, j, len;
    scanf("%s", &s);
    len = strlen(s);
   // cin << s;
    for(i = 0; i < len; i++)
    {
            if(!isalphanum(s[i]))
            {

                printf(" %c", s[i];)
            }
    }
    return 0;
}
