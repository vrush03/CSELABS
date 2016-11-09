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
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		if(start<a[i])
			{
				cout<<a[i]<<" ";
				break;
			}
	}
	int j=i,k;
	int ans = abs(start-a[i-1]);
	for(k=i;k<n;k++)
	{
		if(k == i)
			ans=abs(a[k]-start);
		else
			ans=abs(a[k] - a[k-1]);
		cout<<"Tracks Reversed:"<<a[k]<<endl;
		cout<<"Difference Between Tracks:"<<ans<<"\n\n";
		sum+=ans;		
	}

	cout<<"Break\n\n";


	for(k=0;k<=i-1;k++)
	{
		if(k==0)
			ans=abs(a[k] - a[n-1]);
		else
			ans = abs(a[k]-a[k-1]);
		cout<<"Tracks Reversed:"<<a[k]<<endl;
		cout<<"Difference Between Tracks:"<<ans<<"\n\n";
		sum+=ans;
	}

	
	int c=0;
	
	cout<<(float)sum/n<<endl;
	return 0;
}