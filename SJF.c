#include <stdio.h>
#include <limits.h>
//finds the minimum Arival time
int MinProcess(int arr[],int time,int no_of_processes,int arrb[],int arrc[])
{
    int min=INT_MAX;
    int pos=no_of_processes+99;
   for(int i=0;i<no_of_processes;i++)
   {  
     if(arrc[i]==0)
     {
     if(arrb[i]<min&&arr[i]<=time)
     {
     min=arrb[i];
     pos=i;
     }
     }
   }
   if(pos==no_of_processes+99)return -1;
   return pos;

}
//find turn around time 
void Turn(int*TAT,int p,int*comptime,int*ari)
{
  for(int i=0;i<p;i++)
    TAT[i]=comptime[i]-ari[i];
}
//find waiting time
void Wait(int WT[],int p,int bt[],int ta[])
{
   for(int i=0;i<p;i++)
    WT[i]=ta[i]-bt[i];
}

int main() {
  int no_of_processes;
  printf("Enter the no of processes\n");
  scanf("%d",&no_of_processes);
  int ArivalTime[no_of_processes],BrustTime[no_of_processes],CompletionTime[no_of_processes],TAT[no_of_processes],WT[no_of_processes], processcom[no_of_processes];
  
  for(int i=0;i<no_of_processes;i++)
  {
    processcom[i]=0;
    printf("Enter arival time and Brust time of Process %d\n",i+1);
     scanf("%d",&ArivalTime[i]);
     scanf("%d",&BrustTime[i]);
  }
 int i=0;
while(1)
 {
     int pos=MinProcess(ArivalTime,i,no_of_processes,BrustTime,processcom);
     if(pos==-1)
     i=i+1;
     else
     {
     processcom[pos]=1;
     CompletionTime[pos] =i+BrustTime[pos];
     i=CompletionTime[pos];
     }
     int sum =0;
     for(int j=0;j<no_of_processes;j++)
     {
        sum+=processcom[j];
     }
     if(sum==no_of_processes)
     break;
 }
 Turn(TAT,no_of_processes,CompletionTime, ArivalTime);
 Wait(WT,no_of_processes,BrustTime,TAT);
 printf("Process\tA.T\tB.T\tC.T\tTAT\tWT\n");
 for(int j=0;j<no_of_processes;j++)
 {  

    printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",j+1,ArivalTime[j],BrustTime[j],CompletionTime[j],TAT[j],WT[j]);

 }
    return 0;
}