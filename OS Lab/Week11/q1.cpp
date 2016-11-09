#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,a[1000],start,sum=0;
	cout<<"Enter Number of Tracks:";
	cin>>n;
	cout<<"Enter Track:";
	int i;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"Enter Start:";
	cin>>start;
	int ans = abs(a[0]-start);
	for(i=0;i<n;i++)
	{
	
	
	if(i!=0)
		ans=abs(a[i] - a[i-1]);
	cout<<"Tracks Reversed:"<<a[i]<<endl;
	cout<<"Difference Between Tracks:"<<ans<<"\n\n";
	sum+=ans;
	}
	cout<<(sum/n)<<endl;
	return 0;
}