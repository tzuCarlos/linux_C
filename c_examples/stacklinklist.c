/* Stack array implementation 
* reference:
* http://www.c4learn.com/c-programs/c-program-to-implement-stack-operations-using-array.html
* http://www.cs.usfca.edu/~galles/visualization/Algorithms.html
* http://www.zentut.com/c-tutorial/c-stack-using-array/
*/

/* pass struct pointer
void modify_item(struct item **s){
   struct item *retVal = malloc(sizeof(struct item));
   retVal->element = 5;
   *s = retVal;
}

int main(){
   struct item *stuff = NULL;
   modify_item(&stuff);
or

struct item *modify_item(void){
   struct item *retVal = malloc(sizeof(struct item));
   retVal->element = 5;
   return retVal;
}

int main(){
   struct item *stuff = NULL;
   stuff = modify_item();
}

*/

#include <stdio.h>
#include<stdlib.h>

typedef struct node{ 
    int data; 
    struct node *next; 
}node;





push(int data,node **top)
{
  node *newNode;
  
  newNode=(node *)malloc(sizeof(node));
   if(newNode == NULL) { 
        printf("\n malloc fail"); 
        exit(1); 
    } 

  newNode->data=data;
  newNode->next=*top;
  *top=newNode;
  printf("newNode at=%p top at=%p \n",newNode, *top);
  
}

pop(node **top)
{
  node *temp;
  if(*top==NULL)
  {
    printf("Stack is empty \n");
	return 0;
  }
  else
  {
    printf("pop value=%d \n",(*top)->data);
	temp=*top;
	*top=(*top)->next;
	free(temp);
  }  
}


display(node *ptr)
{
  while(ptr)
  {
     printf("%d\n", ptr->data);
	 ptr=ptr->next;
  }
}

int main()
{
 node *top=NULL;
 
 int value;
 int item;


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
    
            push(item,&top);
			printf("top at %p\n",top);
			display(top);
         break;
      case 2: 
            pop(&top);
            display(top);
         break;
      case 3:
         display(top);
         break;
      case 4:
         exit(0);
      default:
         printf("invalid input \n");
         exit(0);
      }
   }

}
