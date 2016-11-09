#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main()
{
	int a[100];
	int n;
	cin>>n;	
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];		
	int j=0,temp;
	for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];	
				a[j+1]=temp;			
			}		
		}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";	
return 0;
}
