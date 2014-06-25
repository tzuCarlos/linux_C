#include<stdio.h>

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


unsigned int factorial_iteration(int n)
{
  int i=1;
  int result=1;

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
  printf(" %d \n",factorial_iteration(10));

}
