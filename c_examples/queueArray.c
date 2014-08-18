/*
*
 * Queue using an Array
 * reference:
 *http://www.cs.usfca.edu/~galles/visualization/QueueArray.html
 *https://www.youtube.com/watch?v=okr-XE8yTO8
 */

#include <stdio.h>
#include<stdlib.h>


#define MAX 5

int queue_array[MAX]={0};

int rear = -1;

int front = -1;


// To check wheter Queue is empty or not
int IsEmpty()
{
        return (front == -1 && rear == -1);
}

//To check if full or not.
int IsFull()
{
     return (rear+1)%MAX == front ? 1 : 0;
}



int enqueue(int data)
{

            if(IsFull())
            {
                    printf("Queue is full \n");
                    return -1;
            }
            if (IsEmpty())
            {
                    front = rear = 0;
            }
            else
            {
                    rear = (rear+1)%MAX;
            }
                    queue_array[rear] = data;
   
}

int dequeue()
{
      
        if(IsEmpty())
        {
                printf("Queue is empty \n");
                return;
        }
        else if(front == rear )
        {       
                //queue clear
               if(   queue_array[front] != -1)
               {
                         printf("item %d is %d \n",front,  queue_array[front]);
                           front = (front+1)%MAX;
               }
               else
                        printf("Queue is empty!!");
        }
        else
        {
                  printf("item %d is %d \n",front,  queue_array[front]);
                  queue_array[front]=-1;
                front = (front+1)%MAX;
        }
     

}

display()
{
   int i;

   for(i = 0 ;  i < MAX ; i++)
       printf("queue i=%d \n",queue_array[i]);
   
}
int main()
{

   int value;
   int data;
   
 printf("\n Queue array example");
    while(1)
    {
      printf("\nMain Menu");
      printf("\n1.Enqueue \n2.Dequene \n3.Display \n4.exit");
      printf("current front %d rear %d\n",front,rear);
      printf("\nEnter Your Choice");
      scanf("%d", &value);  //I know getchar better
      switch (value) {
      case 1:
         printf("\nEnter The item to be pushed");
         if(!scanf("%d", &data))
         {
              printf("Invalid input \n");
              exit(0);
         }
        enqueue(data);
         break;
      case 2:
          dequeue();

         break;
      case 3:
         display();
         break;
      case 4:
         exit(0);
      default:
         printf("invalid input \n");
         exit(0);
      }
   }

}

