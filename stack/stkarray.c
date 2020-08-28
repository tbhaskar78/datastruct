/*
 * Author: Bhaskar Tallamraju
 * Description: stack implementation using arrays
 *
 * Stack: its a data structure which works based on principle of last in first out (LIFO).
 * In computing world, stack data structure can be applied in many applications such as 
 * parsing syntax of expressions and solving search problem. Push and pop are the operations 
 * that are provided for insertion of an element into the stack and the removal of an element 
 * from the stack.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS   10
int stack[MAX_ELEMENTS] = {0};
int top = -1;

void push(int data)
{
   if (top >= MAX_ELEMENTS-1)
      printf ("Stack overflow\n");
   else
   {
      ++top;
      stack[top] = data;
   }
}

void pop(void)
{
   if (top == -1)
      printf ("Stack underflow\n");
   else
   {
      printf ("data popped %d\n", stack[top]);
      stack[top] = 0;  /* erase the value */
      --top;
   }
}

int main()
{
   int i;
   for (i=0;i<MAX_ELEMENTS+2;i++)
      push(i+1);

   for (i=0;i<MAX_ELEMENTS+4;i++)
      pop();
   
   return 0;
}
