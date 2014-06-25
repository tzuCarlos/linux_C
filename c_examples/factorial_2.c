#include<stdio.h>
#include<math.h>
/*
*  example for recursion and iteration 
*  I know it should return error if n < 0, but this just a simple example for study.
*  Do not care about overflow issues this example. 
*/
unsigned int factorial_recursion(int n)
{

   /* return n>=1 ? n * factorial_recursion(n-1) : 1; */

   if(n==0)
      return 1;  /*Base case */
   else
      return n * factorial_recursion(n-1); /*General case */

}

int * toArray(int number)
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
unsigned int factorial_iteration(int n)
{
  int i=1;
  int result=1;

  int a[10]= {0};
  int *p;

  int_to_array(n, a,10);
  p=toArray(n);

  for(i=0 ; i <10; i++)
  printf("%d",a[i]);
  printf("........\n");

  for(i=0 ; i <10; i++)
  printf("%d",*(p+i));
  
  return 1;
  for(i=1; i <= n  ; i++)
  {
    /*result *= i */
    result=result * i;
  }

  return result;
}

int main()
{

  printf(" %d \n",factorial_recursion(10));
  printf(" %d \n",factorial_iteration(123456789));

}
