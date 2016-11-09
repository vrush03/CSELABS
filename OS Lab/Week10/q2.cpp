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
void secondChance(int a[],int ans[],int n,int nf)
{

	int i,k=0,ref[1000];
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
	//LRU(a,ans,n,nf);
	//LFU(a,ans,n,nf);
	secondChance(a,ans,n,nf);
	return 0;
}
