#include <stdio.h>
#include <stdlib.h>
int opcount=0;
int gcd(int m,int n)
{
	int t;
	if(m>n)
		t=n;
	else
		t=m;
	while(t!=1)
	{
		if(m%t==0)
		{
			if(n%t==0)
				return t;
			
			t--;
		}
		else
			t--;
		opcount++;
	}
	printf("%d\n",opcount );
	return t;
}
int main()
{
	/* code */
	int m,n;
	scanf("%d %d",&m,&n);
	int ans=gcd(m,n);
	printf("%d\n",ans );
	return 0;
}