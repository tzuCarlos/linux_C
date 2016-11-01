/*
 *  DFS floodfill 
 *  reference: http://www.books.com.tw/products/0010656544 
 *
*/
#include <stdio.h>

#define X 5
#define Y 10

/* use 2D array to represent a island where  0=sea ,1~9 = land */
int island[X][Y]={ {1,2,3,0,0,0,0,0,2,3},
                    {3,0,3,0,1,2,3,0,1,2},
                    {3,0,0,1,2,3,4,1,0,1},
                    {0,0,0,1,2,3,4,1,0,0},
                    {1,1,1,0,1,1,1,0,0,0}};
/*next x and y */
int next[4][2]={{0,1}, /*right*/
                {1,0}, /*down*/
                {0,-1}, /*left*/
                {-1,0}}; /*up*/

int book[X][Y]={0};

void dfs(int x, int y, int color){

    int i=0;
    int nx=0;
    int ny=0;

    /*fill it*/
    island[x][y]=color;

    /*try all directions*/
    for(i=0; i<4 ; i++){

       nx=x+next[i][0];
       ny=y+next[i][1];
       
       /*check boarder */
       if(nx < 0 || nx >= X || ny < 0 || ny >= Y)
            continue;

       /*check if land and haven't been yet */
       if(island[nx][ny] > 0 && book[nx][ny]==0)
       {
           book[nx][ny]=1;
           dfs(nx,ny,-8);
       }    
       
    }  
}    

int main()
{
    int x=X;
    int y=Y;
    int i,j;
    int startX=2;
    int startY=3;

    for(i=0; i < x ; i++){
        for(j=0; j<y; j++)
          printf("%2d",island[i][j]);
      
        printf("\n");
    }

    dfs(startX,startY,-8);

    printf("After dfs \n\n");

    /*pinrt the result */
    for(i=0; i < x ; i++){
        for(j=0; j<y; j++)
          printf("%2d",island[i][j]);
      
        printf("\n");
    }

}    
