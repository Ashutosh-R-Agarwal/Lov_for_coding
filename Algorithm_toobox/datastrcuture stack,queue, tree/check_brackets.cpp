#include <iostream>
#include <stack>
#include <string>
#include<stdio.h>

struct Bracket {
   // Bracket(char type, int position):
     //   type(type),
      //  position(position)
    //{}


    char type;
    int position;
};

/*bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
}*/

struct Bracket b;
int global = 0;
std::stack <Bracket> opening_brackets_stack;


 int handling(std::string text)
 {
     char c;

        for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
        global++;
       // printf("\nNEXT IS :%c", next);

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            //printf(" %c", next);
            b.type = next;
            b.position = (position  + 1);
            opening_brackets_stack.push(b);

           // opening_brackets_stack.type = next;

            //opening_brackets_stack.position = position;
            //opening_brackets_stack.push(next);


        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
    //       printf(" %c", next);
           //global++;
           if(!opening_brackets_stack.empty()) {
       //         printf("CHAR IS : %c and pop element : %c ", next, opening_brackets_stack.top().type);
                b = opening_brackets_stack.top();
                opening_brackets_stack.pop();
               if((next == ')' && b.type != '(') ||
                  (next == ']' && b.type != '[') ||
                  (next == '}' && b.type != '{'))
               {
                //   rem = b;


            //     printf("%c and global is : %d", next, global);
                   printf("%d", global);
                   return 0;

               }
           }
           else {

                printf("%d", global);
                return 0;

           }

        }
    }
    if(!opening_brackets_stack.empty())
    {

        return 1;
    }
    return 2;
 }
int main() {
    std::string text;
    //char c;
    getline(std::cin, text);

    int result = handling(text);
  /*  if(!opening_brackets_stack.empty())
        printf("%d", opening_brackets_stack.top().position);
    else
    result == true ? printf("Success") : printf("%d", global);
*/
    if(result == 1)
        printf("%d",opening_brackets_stack.top().position);

    if(result == 2)
            printf("Success");
    // Printing answer, write your code here

    return 0;
}
