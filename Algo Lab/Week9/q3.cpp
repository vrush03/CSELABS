#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int a[10000],n,data,i,ch,rem,flag=0,val=0;
	cin>>n;
	for(i=0;i<n;i++)
		a[i]=9999;
	
	while(1)
	{
		cout<<"1.Enter 2.Display 3.Search 4.Exit:\n";
		cin>>ch;
		if(ch == 1)
		{
			cin>>data;
			rem=data%10;
			if(a[rem] == 9999)
				a[rem]=data;
			else
			{
				for(i=rem+1;i!=rem;i=(i+1)%n)
				{	
					if(i == n)
						i=0;
					if(a[i] == 9999)
					{
						a[i]=data;
						break;
					}	
				}
				if(i == rem)
				{
					cout<<"Memory Full\n";
					break;
				}
				
			}
		}	
		else if(ch==2)
		{
			for(i=0;i<n;i++)
				cout<<a[i]<<" ";
			cout<<endl;
		}
		else if(ch == 3)
		{
			cout<<"Enter Element to Search:";
			cin>>data;
			rem=data%10;
			flag=0;
			val++;
			if(a[rem] == data)
				flag=1;
			else
			{
				for(i=rem+1;i!=rem;i=(i+1)%n)
				{	
					if(i == n)
						i=0;
					if(a[i] == data)
					{
						flag=1;
						break;
					}	
					val++;
				if(i == rem)
				{
					cout<<"Memory Full\n";
					break;
				}
				}
				
			}
			if(flag)
				printf("Element Found and No of Comparisons:%d\n",val);
			else
				printf("Element Not Found and No of Comparisons:%d\n",val);
		
		}
		else
			break;
	}
	return 0;
}