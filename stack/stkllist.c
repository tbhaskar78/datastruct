/*
 * Author: Bhaskar Tallamraju
 * Description: stack implementation using linkedlist
 *
 * Stack: its a data structure which works based on principle of last in first out (LIFO).
 * In computing world, stack data structure can be applied in many applications such as 
 * parsing syntax of expressions and solving search problem. Push and pop are the operations 
 * that are provided for insertion of an element into the stack and the removal of an element 
 * from the stack.
 *
 *   topstack -> |newElement|next| -> |5|next| -> |7|next| -> |firstelement|next|->NULL
 *
 *   topstack ptr points to the new element pushed and gets popped from there too. 
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS   10
typedef struct stack
{
   int data;
   struct stack *next;
} stack_t;

int top = -1;

void push(struct stack **topstack, int data)
{
   if (top >= MAX_ELEMENTS-1)
      printf ("Stack overflow\n");
   else
   {
      struct stack *temp;
      ++top;
      temp = (struct stack *) malloc (sizeof (struct stack));
      temp->data = data;
      temp->next = *topstack; 
      *topstack = temp;
   }
}

void pop(struct stack **topstack)
{
   if (top == -1)
      printf ("Stack underflow\n");
   else
   {
      struct stack *temp;
      printf ("data popped %d\n", (*topstack)->data);
      temp = *topstack;
      *topstack = (*topstack)->next;
      free (temp);
      --top;
   }
}

int main()
{
   int i;
   stack_t *topstack = NULL;

   for (i=0;i<MAX_ELEMENTS+4;i++)
      push(&topstack, i+1);

   for (i=0;i<MAX_ELEMENTS+2;i++)
      pop(&topstack);
   
   return 0;
   
}
