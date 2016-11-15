#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[1000],i;
	int n;
	cin>>n;
	for(i=0;i<n;i++)
	{	
		cin>>a[i];
	}
	
	for(i=0;i<=n/2;i++)
	{
		if(a[i]<a[2*i+1] || a[i]<a[2*i+2])
		{
			cout<<"Not a Heap\n";
			return 0;
		}
	}
	/*for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	*/cout<<"Its a Heap\n";
	
	return 0;
}