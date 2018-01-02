
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
int a;
char name[10];
}Node;

typedef struct Employee
{
    int employee_id;
    Node *n;
}Employee;

void main()
{
    Employee e;
    e.employee_id = 10;
    e.n = (Node *)(malloc(sizeof(Node)));
    e.n->a = 10;
    strcpy(e.n->name,"ashu");

    printf("Employee id : :%d , name : %s  , Misc : %d", e.employee_id, e.n->name, e.n->a);

   printf("NAME IS ASHUTOSH and Employee id  is : %d and misc is : %d", e.employee_id, e.n->a  );
   getch();

}
