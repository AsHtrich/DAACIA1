#include<stdio.h>
#define humans 5
#define INF 99999;
int G[humans][humans] = {{0,4,2,0,0},{0,0,3,2,3},{0,1,0,4,5},{0,0,0,0,0},{0,0,0,-5,0}};

int main() {
  int human_no=0;  
  int zombies[humans]={0};
  zombies[0] = 1;
  int row;  
  int col;  
  printf("Humans : steps\n");

  while (human_no < humans - 1) 
  {
    int min = INF;
    row = 0;
    col = 0;

    for (int i = 0; i < humans; i++) 
    {
      if (zombies[i]) 
      {
        for (int j = 0; j < humans; j++) 
        {
          if (zombies[j]!=0 && G[i][j]>-INF) 
          {  
            if (min > G[i][j]) 
            {
              min = G[i][j];
              row = i;
              col = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", row, col, G[row][col]);
    zombies[col] = 1;
    human_no++;
  }
  return 0;
}
