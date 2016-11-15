#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int c=0;
int main()
{
	char a[1000],b[1000],i,j,flag,m,n;
	scanf("%s",a);
	scanf("%s",b);
	m=strlen(a);
	n=strlen(b);
	for(i=0;i<=m-n;i++)
	{
		int f=i;
		flag=0;
		for(j=0;j<n;j++,f++)
		{
			if(a[f]!=b[j])
			{
				flag=1;
				break;
			}
		c++;
		}
		if(!flag)
		{
			printf("Substring Found at: %d\n",i );
			printf("%d\n",c );
			return 0;
		}
	}
	printf("Substring Not Found\n");
	printf("%d\n",c );

	return 0;
}