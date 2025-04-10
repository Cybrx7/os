#include <stdio.h>
int main()
{
  int n,m,i,j,k=0,pf=0,f=0;
  printf("Enter the number of pages: ");
  scanf("%d",&n);
  printf("Enter the size of cache memory: ");
  scanf("%d",&m);
  int a[n],b[m];
  printf("Enter the page number of each page: ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++)
  {
    for (j=0;j<m;j++)
    {
      if(a[i]==b[j])
      {
        f=0;
        break;
      }
      else{
        f=1;
      }
    }
    if(k>=m)
    { 
      k=0;
    }
    if(f==1)
    {
      b[k]=a[i];
      k++;
      pf++;
    }
  }
  printf("Contents of Cache after page replacement : \n");
  for(i=0;i<m;i++)
  {
    printf("%d\t",b[i]);
    printf("\n NUmber of page faults: %d\n",pf);
    return 0;
  }
  
}



























