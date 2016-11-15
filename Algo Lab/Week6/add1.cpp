#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int fast_pow(int a,int b)
{
	if(b==1)
		return a;
	else
	{
		if(b%2 == 0)
		{
			int ans=pow(fast_pow(a,b/2),2);
			return ans;
		}
		else
		{
			int ans= a*pow(fast_pow(a,(b-1)/2),2);
			return ans;
		}
	}
}
int main(int argc, char const *argv[])
{
	int a,b;
	cin>>a>>b;
	cout<< fast_pow(a,b) <<endl;
	return 0;
}