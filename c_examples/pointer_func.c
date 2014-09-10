#include <stdio.h>
#include <stdlib.h>

 
#define ARRAY_LEN(x) (sizeof(x)/sizeof((x)[0]))  
#define FUNC_NUM ARRAY_LEN(CmdTable) 
typedef void (*MYFUNC)();
 
typedef struct{
char *CmdName;
MYFUNC Cmdfunc;
}CMD;
 
void func1()
{
 printf("\n%s\n",__func__);
}
 
void func2()
{
 printf("\n%s\n",__func__);
}
 
void func3()
{
 printf("\n%s\n",__func__);
}
 
CMD CmdTable[]={
{"39",func1},
{"66",func2},
{"99",func3}
};
 
int main(int argc, char *argv[])
{
   int i=0;
      
    if(argc <2)
         exit(0);
  
    for(i=0; i< FUNC_NUM ;i++){
        if( !strcmp(argv[1],CmdTable[i].CmdName) )
                     (*(CmdTable[i].Cmdfunc))();
    }
}
