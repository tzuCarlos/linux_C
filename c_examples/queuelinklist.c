/*
*
 * Queue using an Array
 * reference:
 *http://www.cs.usfca.edu/~galles/visualization/QueueArray.html
 *https://www.youtube.com/watch?v=okr-XE8yTO8
 */

#include <stdio.h>
#include<stdlib.h>


struct Node
 {
        int Data;
        struct Node* next;
 }*rear=NULL, *front=NULL;    //declare two pointer  front and rear.



int enqueue(int data)
{

    struct Node *newNode; 
    newNode = (struct Node *)malloc(sizeof(struct Node));  // allocate a new memory for newNode. 
    if(newNode)
    {
         if(front == NULL)
         {
               newNode->Data=data;
               newNode->next=front;
               front=newNode;
               rear=front;
         }
         else
         {
              newNode->Data=data;
               newNode->next=NULL;
               rear->next=newNode;
               rear=newNode;
         }
    }
    else 
    {
        printf("error when malloc");
    }   
}

int dequeue()
{
  struct Node *temp;
  
      if(front)
      {
          printf(" dequeue %d  \n", front->Data);
          temp=front;
          front=front->next;
          free(temp);
       }
      else
         printf("Queue is empty \n");
   
    
     

}

display()
{
   int i=0;
   struct Node *list;
   list=front;
   while(list)
   {
          printf(" %d = %d  \n",i, list->Data);
          list=list->next;
          i++;
    }
}
int main()
{

   int value;
   int data;
   
 printf("\n Queue link list example");
    while(1)
    {
      printf("\nMain Menu");
      printf("\n1.Enqueue \n2.Dequene \n3.Display \n4.exit");
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

