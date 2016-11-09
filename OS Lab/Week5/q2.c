#include<stdio.h>
#include<stdlib.h>

void main()
{
int p[4]={0,1,2,3};
int at[4]={0,4,3,2};
int bt[4]={8,5,2,1};
int priority[4]={4,2,1,3};
int ct[4],wt[4],tat[4];

int n=4;int i ;int j;



int copybt[4];
for(i=0;i<n;i++)
{
copybt[i]=bt[i];
}
int copyat[4];
for(i=0;i<n;i++)
{
copyat[i]=at[i];
}


int sbt;
int t;int now;
for(t=0;t<16;t++)
{
int g=0;
 for(i=0;i<=3;i++)
   {
         
    if(at[i]<=t && at[i]>=0) 
       {
        if(g==0) // checks at the beginning of every second
           {
                sbt=bt[i];
                g++;
                now=i;
           }
            
         
         if(bt[i]<sbt)
                { 
                  sbt=bt[i];
                  now =i; 
                }
        }
    }

//printf("\n now i is %d \n",now);

bt[now]=bt[now]-1;
if(bt[now]==0)
{
ct[now]=t+1;
at[now]=-1;
}
}



printf("\n ct is \n");
for(i=0;i<n;i++)
{
    printf(" %d ",ct[i]);
}



for(i=0;i<n;i++)
{
tat[i]=ct[i]-copyat[i];
wt[i]=tat[i]-copybt[i];
}




int s=0;
printf("\ntat is \n");
for(i=0;i<n;i++)
{
s=s+tat[i];
printf(" %d ",tat[i]);
}

printf("\n the avg tat is %f",(float)s/4);
s=0;

printf("\n wt is \n");

for(i=0;i<n;i++)
{
s=s+wt[i];
printf(" %d ",wt[i]);
}


printf("\n the avg wt is %f",(float)s/4);

}