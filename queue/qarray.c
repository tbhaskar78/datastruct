/*
 * Author: Bhaskar Tallamraju
 * Description: queue implementation using arrays
 *
 * Queue: its a data structure which works based on principle of first in first out (FIFO).
 * In computing world, queue data structure can be applied in many applications where order is important
 * such as holding messages. enqueue and dequeue are the operations that are provided for insertion 
 * of an element into the stack and the removal of an element from the queue.
 *
 *   two indexes, readq follows writeq. After reading, check if readq equals writeq and then 
 *   re-initialize the indexes. 
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS   10
int queue[MAX_ELEMENTS] = {0};
int readq = 0;
int writeq = -1;

void enqueue(int data)
{
   if (writeq >= (MAX_ELEMENTS-1))
      printf ("Queue full\n");
   else
   {
      ++writeq;
      queue[writeq] = data;
   }
}

void dequeue(void)
{
   if (writeq == -1)
      printf ("Queue empty\n");
   else
   {
      printf ("data dequeued %d\n", queue[readq]);
      queue[readq] = 0;  /* erase the value */
      if (readq == writeq)
      {
          readq = 0;
          writeq = -1;
      }
      else
          ++readq;
   }
}

int main()
{
   int i;
   for (i=0;i<MAX_ELEMENTS+2;i++)
      enqueue(i+1);

   for (i=0;i<MAX_ELEMENTS+4;i++)
      dequeue();
   
   return 0;
}
