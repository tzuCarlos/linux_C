/* Stack array implementation 
* reference:
* http://www.c4learn.com/c-programs/c-program-to-implement-stack-operations-using-array.html
* http://www.cs.usfca.edu/~galles/visualization/Algorithms.html
* http://www.zentut.com/c-tutorial/c-stack-using-array/
*/

#include <stdio.h>
#include<stdlib.h>
#define STACK_SIZE 5 







int stempty(int top)
{
  return top == 0 ? 1: 0;
}

push(int item,int *top, int array[])
{
  array[*top]=item;
  (*top)++;
}

pop(int *top,int array[])
{
  int i=0;
  i=array[*top-1];
  (*top)--;
  return i;
}
int stfull(int top)
{

   return top >=STACK_SIZE ? 1: 0;
}

display(int array[], int top)
{
 int i;
 printf("TOP=%d \n",top);
 for(i=0 ; i<top ; i++)
    printf("stack[%d]=%d ",i,array[i]);
 printf("\n");
}

int main()
{
 unsigned int top=0;
 int stack[STACK_SIZE]={0};  
 int value;
 int item;
 char ans;

 printf("\n Stack example");
    while(1)
    {
      printf("\nMain Menu");
      printf("\n1.Push \n2.Pop \n3.Display \n4.exit");
      printf("\nEnter Your Choice");
      scanf("%d", &value);  //I know getchar better
      switch (value) {
      case 1:
         printf("\nEnter The item to be pushed");
         if(!scanf("%d", &item))
         {
              printf("Invalid input \n");
              exit(0);
         }
         if (stfull(top))
            printf("\nStack is Full!");
         else
            push(item,&top,stack);
         break;
      case 2:
         if (stempty(top))
            printf("\nEmpty stack!!!");
         else {
            item = pop(&top,stack);
            printf("\nThe popped element is %d", item);
         }
         break;
      case 3:
         display(stack,top);
         break;
      case 4:
         exit(0);
      default:
         printf("invalid input \n");
         exit(0);
      }
   }

}
