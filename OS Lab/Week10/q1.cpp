#include <bits/stdc++.h>
using namespace std;
int flag2=0;
int check(int a[],int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		flag2=1;
		if(a[i] ==  key)
			return i;
	}
	flag2=0;
	return 1;
}
void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
void FCFS(int a[],int ans[],int n,int nf)
{

	int i,k=0;
	for(i=0;i<n;i++)
	{
		cout<<"Entering Value: "<<a[i]<<endl;
		if(check(ans,nf,a[i]))
		{
			ans[k++]=a[i];
			printf("Page Fault Here:  ");
			display(ans,nf);
		}
		else
		{
			display(ans,nf);
		}
		if(k>=nf)
			k=0;
	}
	
}
void inc(int count[],int n,int k,int f)
{
	int j=0;
	for(j=0;j<n;j++)
	{
		if(j!=k)
			count[j]++;
	}
	count[k]=0;
}
int findMaxCount(int count[],int nf)
{
	int i,max=0,index;
	for(i=0;i<nf;i++)
		if(max < count[i])
		{	
			max=count[i];
			index=i;
		}
	return index;
}
void LRU(int a[],int ans[],int n,int nf)
{

	int i,k=0,count[1000]={0},f=0;
	for(i=0;i<n;i++)
	{
		f=0;
		cout<<"Entering Value: "<<a[i]<<endl;
		int flag = check(ans,nf,a[i]);
		if(flag == 1 && flag2 == 0)
		{
			
			cout<<"Page Fault Here: ";
			k=findMaxCount(count,nf);
			ans[k]=a[i];
			display(ans,nf);
			inc(count,nf,k,f);
		}
		else
		{
			inc(count,nf,flag,f);
			display(ans,nf);
			//cout<<"Count Array:\n";
			//display(count,nf);
		}
	}
}
int findLeastCount(int count[],int n)
{
	int min=999,i,index;
	for(i=0;i<n;i++)
	{
		if(count[i] < min)
		{
			min=count[i];
			index=i;
		}
	}
	return index;
}
void LFU(int a[],int ans[],int n,int nf)
{
	int i,k=0,count[1000]={0};
	for(i=0;i<n;i++)
		count[i]=-1;
	for(i=0;i<n;i++)
	{
		cout<<"Entering Value: "<<a[i]<<endl;
		int flag = check(ans,nf,a[i]);
		if(flag == 1 && flag2 == 0)
		{
			count[a[i]]++;
			cout<<"Page Fault Here:\n";
			k=findLeastCount(count,nf);
			ans[k]=a[i];
			cout<<ans[k]<<endl<<k<<endl;
			display(ans,nf);
			
		}
		else
		{
			count[a[i]]++;
			display(ans,nf);
			cout<<"Count Array:\n";
			display(count,n);
		}
		
	}
}
int main(int argc, char const *argv[])
{
	int a[1000],n,nf,ans[1000],k;
	cout<<"Enter length of Reference String:";
	cin>>n;
	cout<<"Enter String:";
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"Enter No.of Frames:";
	cin>>nf;
	for(i=0;i<nf;i++)
		ans[i]=-1;
	//FCFS(a,ans,n,nf);
	LRU(a,ans,n,nf);
	//LFU(a,ans,n,nf);
	return 0;
}
