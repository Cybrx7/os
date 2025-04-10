#include <stdio.h>
#define MAX_PARTITIONS 10
#define MAX_PROCESS 10

struct partition{
  int size;
  int allocated;
};
struct process{
  int id;
  int size;
};
int main()
{
  struct partition partitions[MAX_PARTITIONS];
  struct process processes[MAX_PROCESS];
  int numPartitions,numProcesses;
  printf("Enter the number of partitions: ");
  scanf("%d",&numPartitions);
  printf("Enter the sizes of partitions: \n");
  for(int i=0;i<numPartitions;i++)
  {
     printf("Partition %d size: ",i+1);
     scanf("%d",&partitions[i].size);
     partitions[i].allocated=0;
  }
  printf("Enter the number of Processes:");
  scanf("%d",&numProcesses);
  printf("Enter the size of Processes : \n");
  for(int i=0;i<numProcesses;i++)
  {
     printf("Process %d size: ",i+1);
     scanf("%d",&processes[i].size);
     processes[i].id=i+1;
  }
  printf("\n File Number \t File Size \t Block Number \t Block Size \t Fragment \n");
  
  for(int i=0;i<numProcesses;i++)
  {
    int worstFitIndex=-1;
    for(int j=0;j<numPartitions;j++)
    {
      if(!partitions[j].allocated && partitions[j].size >= processes[i].size)
      {
        if(worstFitIndex==-1 || partitions[j].size>partitions[worstFitIndex].size)
        {
          worstFitIndex=j;
        }
      }
    }
    if(worstFitIndex != -1)
    {
      partitions[worstFitIndex].allocated=processes[i].id;
      printf("%d \t\t %d\t\t %d \t\t %d\t\t%d\n",processes[i].id,processes[i].size,worstFitIndex+1,partitions[worstFitIndex].size,partitions[worstFitIndex].size-processes[i].size);
    }
    else{
      printf("%d \t\t %d\t\t %s \t\t %s \t\t %s \n",processes[i].id,processes[i].size,"N/A" ,"N/A","N/A");
    }
  }
  return 0;
}
