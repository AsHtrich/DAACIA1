#include<stdio.h>
#include<limits.h>
void swap(int*x,int*y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void bubbleSort(int arr[],int src[],int dst[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
                swap(&src[j], &src[j + 1]);
                swap(&dst[j], &dst[j + 1]);
            }
        }
}
}
int findabsroot(int v,int parent[]){
    if(parent[v]==-1)
		return v;
	return findabsroot(parent[v],parent);
}
void union1(int from,int to,int parent[]){
	from = findabsroot(from,parent);
	to= findabsroot(to,parent);
	parent[from]=to;
}
 int main(){
  
 
  int n;
  printf("enter no of vertices: ");
  scanf("%d",&n);

  int edges;
  int smst[n],dmst[n],parent[n];
  printf("enter no of edges: ");
  scanf("%d",&edges);

  for(int i=0;i<edges;i++){
       parent[i]=-1;
  }
 int src[7]={0,0,1,1,1,2,2,2,4};
 int dst[7]={1,2,2,3,4,1,3,4,3};
 int cost[7]={4,2,3,2,3,1,4,5,-5};
 
  bubbleSort(cost,src,dst,edges);
  for(int i=0;i<n-1;i++){
      int a=findabsroot(src[i],parent);
      int b=findabsroot(dst[i],parent);
      if(a!=b){
          smst[i]=src[i];
          dmst[i]=dst[i];
          union1(src[i],dst[i],parent);
      }
  }
  for(int i=0;i<n-1;i++){
    printf("%d --> %d ",smst[i],dmst[i]);
    printf("\n");
}
  return 0;
 }
