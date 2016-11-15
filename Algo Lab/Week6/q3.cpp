#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int c=0;
int part(int a[],int l,int r)
{
	int p,temp,i,j;
	if(l<r)
	{
		p=a[l];
		i=l;
		j=r;
		while(i<j)
		{
			c++;
			while(a[i]<=p && i<j)
				{i++; c++;}
			while(a[i]>p && i<=j)
				{j--; c++;}
			if(i<=j)
				swap(a[i],a[j]);
		}
	}
	swap(a[j],a[l]);
	return j;
}
void sort(int a[],int l,int r)
{
	if( l<r )
	{
		int pivot=part(a,l,r);
		c++;
		sort(a,l,pivot-1);
		sort(a,pivot+1,r);

	}
}
int main(int argc, char const *argv[])
{
	int a[1000],i;
	int n;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,0,n-1);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n"<<c<<endl;
	return 0;
}