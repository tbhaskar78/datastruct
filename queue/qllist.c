/*
 * Author: Bhaskar Tallamraju
 * Description: queue implementation using linkedlist
 *
 * Queue: its a data structure which works based on principle of first in first out (FIFO).
 * In computing world, queue data structure can be applied in many applications where order is important
 * such as holding messages. enqueue and dequeue are the operations that are provided for insertion 
 * of an element into the stack and the removal of an element from the queue.
 *
 *   head -> |6|next| -> |5|next| -> |7|next| -> |newData|next|->NULL
 *                                               q ->
 *
 *   head ptr points to the first element inserted and q points to the latest element added. 
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS   10
typedef struct queue
{
   int data;
   struct queue *next;
} queue_t;

queue_t *head = NULL;
int top = -1;

void enqueue(queue_t **q, int data)
{
   if (top >= MAX_ELEMENTS-1)
      printf ("Queue full\n");
   else
   {
      queue_t *temp;
      ++top;
      temp = (queue_t *) malloc (sizeof (struct queue));
      temp->data = data;
      temp->next = NULL;
      if (*q == NULL)
      {
         head = *q = temp;
      }
      else
      {
         (*q)->next = temp; 
         *q = temp;
      }
   }
}

void dequeue(queue_t **q)
{
   if (head == NULL)
      printf ("Queue empty\n");
   else
   {
      queue_t *temp = head;
      printf ("data dequeued %d\n", temp->data);
      head = head->next;
      free (temp);
      --top;
   }
}

int main()
{
   int i;
   queue_t *q = NULL;

   for (i=0;i<MAX_ELEMENTS+4;i++)
      enqueue(&q, i+1);

   for (i=0;i<MAX_ELEMENTS+2;i++)
      dequeue(&q);
   
   return 0;
   
}
