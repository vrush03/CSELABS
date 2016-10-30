#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	scanf("%lld",&n);
	long long arr1[n+10],sum[n+10];
	long long max = -9999999999999,sum1;
	for (long long i = 1; i <= n; ++i)
	{
		scanf("%lld",&arr1[i]);
		sum1 = arr1[i]+i;
		if(sum1>max)
			max = sum1;
	}
	sum[1] = max;
 	long long k=n;
	for (long long i = 1; i <n; ++i)
	{
		max--;
		if((arr1[i]+n) > (max))
		{
			sum[k] = (arr1[i]+n);
			max = sum[k];
		}
		else
			sum[k] = max;	
		k--;
	}
	for (int i = 1; i <=n; ++i)
	{
		printf("%lld ",sum[i] );		
	}

}