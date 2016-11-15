#include <stdio.h>
int opcount=0;
int gcd(int m, int n)
{
    int r;
	while(r!=0)
    {    
    	r = m % n;
       	m = n;
        n = r;
        opcount+=4;
   }

    printf("%d\n",opcount );
    return n;
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