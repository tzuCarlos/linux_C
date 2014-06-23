#include<stdio.h>


int func1()
{
   printf("WAT WAT WAT \n");
}
main()
{
   /*declare a function pointer*/
   int (*p)();
  
   /*invoke the function*/
   func1();
   p=&func1;
   p();
   (*p)();

   printf("%x %x %x \n",p,*p,func1);
}
