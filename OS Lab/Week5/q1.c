#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	int n,pri[1000],burst[1000],arr[1000],process[100],wt[1000]={0},tat[1000]={0},awt=0,atat=0;
	printf("Enter Number of process:\n");
	scanf("%d",&n);
	int i=0,j,temp;
	for(i=0;i<n;i++)
	{
		process[i]=i+1;
		printf("Enter Arrival for process:%d\n",i+1 );
		scanf("%d",&arr[i]);
		printf("\n");
		printf("Enter BurstTime for process:%d\n",i+1 );
		scanf("%d",&burst[i]);
		printf("\n");
		/*printf("Enter Priority for process:%d\n",i+1 );
		scanf("%d",&pri[i]);*/
		printf("\n");
	}	
		for(i=0;i<n;i++)
			for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];	
				arr[j+1]=temp;

				temp=process[j];
				process[j]=process[j+1];
				process[j+1]=temp;
/*
				temp=pri[j];
				pri[j]=pri[j+1];	
				pri[j+1]=temp;*/

				temp=burst[j];
				burst[j]=burst[j+1];	
				burst[j+1]=temp;			
			}		
		}
		
    wt[0]=0;  
    atat = tat[0] = burst[0];  
    int btt = burst[0];
    //int i;  
    for(i=1; i<n; i++)
    {  
        wt[i] = btt - arr[i];  
        btt += burst[i];        
        awt += wt[i];     
        tat[i] = wt[i] + burst[i];   
        atat += tat[i];    
    }  
    atat/=n;  
    awt/=n;       
	
	
		printf("ID\tArrival\tBurst\tWaiting\tTurnAround\n"); 
		for(i=0;i<n;i++)
		{
			//printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnAround Time\n");
			 printf("%2d\t%2d\t%2d\t%2d\t%2d\n", process[i], arr[i], burst[i], wt[i], tat[i]); 
	
}
	printf("Average TurnAround And Waiting time is:%d and %d\n",atat,awt);
	return 0;
}