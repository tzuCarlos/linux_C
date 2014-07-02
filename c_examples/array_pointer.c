#include<stdio.h>


#define LEN 11

int main()
{

  char array[LEN]={0,1,2,3,4,5,6,7,8,9,10};
  char *ptr;
  int i;
  char inta [3]={0};

  for(i=0 ; i<LEN ; i++)
    printf("array[%d]=%d address=%p array+i=%p\n",i,array[i],&array[i],(array+i));

  printf("\n========================================================= \n"); 
  ptr=array;
  printf(" ptr=array %p \n",ptr);
  ptr=(char *)&array;
  printf(" ptr=&array %p \n",ptr);
  ptr=&array[0];
  printf(" ptr=&array[0] %p \n",ptr);


  /* &array[i] = (ptr+i) */
  printf("array+i=&array[i] *(array+i)=array[i] %d %p \n",*(array+1),(array+1));
  printf("array+i implicitly array+i * sizeof(array[0] \n");
  printf("%d %p",*array,*array); 

  printf("\n2-D \n");
  int b[2][3]={
  {1,2,3},
  {4,5,6}
  };
  int (*ptrb)[3]=b; 
  int j;

  printf("b, &b[0], *b, b[0],&b[0][0] are start address \n");
  for(i=0 ; i < 2 ; i++)
    for(j=0 ; j < 3 ; j++)
	   printf("b[%d][%d], &b[i][j]=%p b=%p &b=%p *b=%p b[0]=%p \n",i,j,&b[i][j],b,&b,*b,b[0]);
  


  printf("b is pointer to int(*)[3] +1=3*int b+1 or &b[1] or &b[1][0] or *(b+1) or = %p \n",*(b));
  printf("b[i][j] = *(b[i]+j) = *(*(b+i)+j) \n");
  printf("*b is a int[], **b is int");
}
