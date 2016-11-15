#include <bits/stdc++.h>
using namespace std;
int c=0;
void heapify(int a[],int n,int i)
{
	int min=i;
	int ch1=2*i+1;
	int ch2=2*i+2;
	if(ch1<n && a[min]>a[ch1])
		min=ch1;
	if(ch2<n && a[min]>a[ch2])
		min=ch2;
	if(min!=i)
	{
		swap(a[min],a[i]);
		c++;
		heapify(a,n,min);
	}
}
void buildheap(int a[],int n)
{
	int i;
	for(i=n/2;i>=0;i--)
	{
		heapify(a,n,i);
	}
}

int main(int argc, char const *argv[])
{
	int a[1000],i;
	int n;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	//sort(a,0,n-1);
	buildheap(a,n);
	//heapsort(a,n);
	swap(a[0],a[n-1]);
	int ans=a[n-1];
	heapify(a,n-1,0);
	cout<<"Minimum Element:"<<ans<<endl;
	for(i=0;i<n-1;i++)
		cout<<a[i]<<" ";
	cout<<"Count:";
	cout<<c<<endl;
	
	return 0;
}