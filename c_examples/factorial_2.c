#include<stdio.h>
#include<math.h>
#include <stdlib.h>

/*
*  example for recursion and iteration 
*  I know it should return error if n < 0, but this just a simple example for study.
*  Do not care about overflow issues this example. 
*/
#define SIZE_A 30
int* toArray(int number)
{
    int n = log10(number) + 1;
    int i;
    int *numberArray = calloc(n, sizeof(int));
    for ( i = 0; i < n; ++i, number /= 10 )
    {
        numberArray[i] = number % 10;
    }
    return numberArray;
}

int int_to_array(int num, int *array,int len)
{
  int i;

  /*backword assign value to arrayi*/
for (i = (len-1); i >0 ; i--) {
    array[i] = num % 10;
    num /= 10;

    if(num==0)
      break;
}

}

unsigned int factorial_recursion(int n)
{

   /* return n>=1 ? n * factorial_recursion(n-1) : 1; */

   if(n==0)
      return 1;  /*Base case */
   else
      return n * factorial_recursion(n-1); /*General case */

}

unsigned int factorial_iteration(int n)
{
  int i=1;
  int result=1;

  int a[10]= {0};

  for(i=1; i <= n  ; i++)
  {
    /*result *= i */
    result=result * i;
  }

  return result;
}

void Big_factorial_iteration(int n)
{
  int i=1;

  /*init array*/
  int a[SIZE_A]= {0};
  int tail=SIZE_A-1;
  
  a[tail]=1;

  for(i=1; i <= n  ; i++)
  {
    /*result *= i */
    int j;
    for(j= tail ; j >= 0 ; j--)
    {
      a[j]=a[j]*i;
    }

    for(j= tail ; j >= 0 ; j--)
    {
      if (a[j] >= 10)
          a[j-1]=a[j-1]+(a[j]/10);
          a[j]=a[j]%10;
    }
  }

  for(i=0; i< SIZE_A ; i++)
  {
     printf("%d",a[i]);
  }
  printf("\n");

}

int main()
{

  printf(" %d \n",factorial_recursion(10));
  printf(" %d \n",factorial_iteration(10));
  Big_factorial_iteration(20);
}
