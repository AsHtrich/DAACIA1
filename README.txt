AMOGHAVARSH 21011102014

Q. Solve the given graph for MST using PRIM'S ALGORITHM, KRISKAL's ALGORITHM and .
Ans. Prims algorithm and Kriskal's algorithm do not give optimal results for a directed graphs.
But they are ok with negative weights as they only focus on the difference between edge weights.
The most optimal answer being:
Humans : steps
0 - 2 : 2
2 - 1 : 1
1 - 3 : 2
1 - 4 : 3

code:
PRIMS ALGORITHM:

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
KRUSKAL's ALGORITHM:

#include<stdio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[9][9],parent[9];
int find(int);
int uni(int,int);
void main()
{
	
	printf("\n\tImplementation of Kruskal's algorithm\n");
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the cost adjacency matrix:\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	printf("The edges of Minimum Cost Spanning Tree are\n");
	while(ne < n)
	{
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n\tMinimum cost = %d\n",mincost);
}
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}
int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}

DIJKSTRA's ALGORITHM does not work for negative weights because by definition its supposed to find the most optimal path.It does not reconsider a node once it marks it as visited even if a shorter path exists than the previous one.
This example cannot be worked with this algorithm just because of the presence of the negative weight.
