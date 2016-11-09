#include <stdio.h>
#include <unistd.h>
int main()
{
	FILE *rp,*wp;
	char *c;
	size_t len;
	rp=fopen("test1.txt","r");
	wp=fopen("test2.txt","w");
	while(getline(&c,&len,rp)!=-1)
	{
		sleep(10);
		printf("%s\n",c );
	}
	return 0;
}