#include <bits/stdc++.h>

using namespace std;
int cal(int need[][100],int work[],int m,int i)
{
	int j;
	for(j=0;j<m;j++)
			if(need[i][j] > work[j])
			{
				return 0;
				
			}
	return 1;
}
int main(int argc, char const *argv[])
{
	int avail[100],alloc[1000][1000],request[1000][1000],m,n,max[1000][1000],work[100];
	int i,j,need[100][100],finish[100]={0},flag=0,flag1=0,next,count1=0;
	cout<<"Enter number of Processes:";
	cin>>n;
	cout<<"Enter number of Resources:";
	cin>>m;
	cout<<"Enter avaiable Resources:";
	for(i=0;i<m;i++)
		cin>>avail[i];

	for(i=0;i<n;i++)
	{	cout<<"Enter Details for P"<<i<<":\n";
		cout<<"Enter Allocation:";
		
		for(j=0;j<m;j++)
			cin>>alloc[i][j];
		
		cout<<"Enter Max:";
		
		for(j=0;j<m;j++)
			cin>>max[i][j];
	}
	
	for(i=0;i<m;i++)
		work[i]=avail[i];
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout<<need[i][j]<<" ";
		cout<<endl;
	}
	while(1)
	{
		
		
		flag=0;
		for(i=0;i<n;i++){			
			if(finish[i] == 0 && cal(need,work,m,i)){
				for(j=0;j<m;j++){
					work[j] = work[j] + alloc[i][j];
				}
				finish[i]=1;
				flag++;
				cout << i <<endl;
				count1++;
			}
		}

		if(flag==0)
			break;
	}

	if(count1 == n)
		cout<<"Safe\n";
	else
		cout<<"Unsafe\n";
	
	return 0;
}