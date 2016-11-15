#include <stdio.h>
#include <stdlib.h>
int opcount=0;
void sieve(int pr[],int n)
{
	int p,i;
	for(p=1;p<n;p++)
		pr[p]=1;
	for (p=2; p*p<=n; p++)
    {
        
        if (pr[p]==1)
        {
            
            for (i=p*2; i<=n; i += p)
                pr[i] = 0;
        }
    }

}

int gcd(int m,int n,int p[])
{
	int i,j=0;
	int max,f1[1000],f2[1000],l=0,r=0;
	if(m>n)
		max=m;
	else
		max=n;
	i=2;
	while(i<max)
	{
		if(p[i]==1 && m%i==0)
			{
				int x=m;
				while(x>0 && x%i==0)
				{
					f1[l++]=i;
					x=x/i;
					opcount++;
				}
			}
		if(p[i]==1 && n%i==0)
			{

				int x=n;
				while(x>0 && x%i==0)
				{
					f2[r++]=i;
					x=x/i;
					opcount++;
				}
			}
		i++;
	}
	int k=0,b=0;
	int ans=1;
	while(k<l && b<r)
	{
		if(f1[k]==f2[b])
		{
			ans=ans*f1[k];
			k++;
			b++;
		}
		else if(f1[k]>f2[b])
			b++;
		else
			k++;
	}	
	
	printf("%d\n",opcount );
	return ans;
}
int main(int argc, char const *argv[])
{
	int m,n;
	int p[2000];
	sieve(p,2000);
	scanf("%d %d",&m,&n);
	printf("%d\n",gcd(m,n,p));
	return 0;
}