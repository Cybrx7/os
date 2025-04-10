#include <stdio.h>
struct process{
 int ps;
 int flag;
}p[50];
struct size{
 int size;
 int alloc;
}s[5];
int main(){
  int i,np,n,j;
  printf("\n First Fit \n");
  printf("Enter the number of blocks: ");
  scanf("%d",&n);
  printf("Enter the size for %d blocks \n",n);
  for(i=0;i<n;i++)
  {
    printf("Enter the size for block %d: ",i+1);
    scanf("%d",&s[i].size);
    s[i].alloc=0;
  }
  printf("\n Enter the number of processes: ");
  scanf("%d",&np);
  printf("Enter the size of %d processes\n",np);
  for(i=0;i<np;i++)
  {
    printf("Enter the size for process %d: ",i+1);
    scanf("%d",&p[i].ps);
    p[i].flag=0;
  }
  printf("\n Allocation of blocks using First Fit :\n");
  printf("Process \t Process Size \t Block\n");
  for(i=0;i<np;i++)
  {
    for(j=0;j<n;j++)
    {
      if(p[i].flag==0 && p[i].ps <= s[j].size && s[j].alloc==0)
      {
        s[j].alloc=1;
        p[i].flag=1;
        printf("%d \t %d \t\t %d \n",i+1,p[i].ps,s[j].size);
        break;
      }
    }
    if(p[i].flag==0)
    {
      printf("Sorry!Process %d must wait as there is no sufficient memory \n",i+1);
    }
  }
  return 0;
} 
