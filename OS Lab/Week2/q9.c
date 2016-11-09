#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int substr(char *a,char *b)
{
	char *p1=a;
	char *p2=b;
	char *p3=NULL;
	int i,j;
	for(i = 0; i<strlen(a); i++)
  {
    if(*p1 == *p2)
      {
          p3 = p1;
          for(j = 0;j<strlen(b);j++)
          {
            if(*p3 == *p2)
            {
              p3++;p2++;
            } 
            else
              break;
          }
          p2 = b;
          if(j == strlen(b))
          {
            	return 1;
            //printf("\nSubstring found at index : %d\n",i);
          }
      }
    p1++; 
  }
  return 0;
}
int main()
{
	
	char *b;
	char *a=(char*)calloc(sizeof(char),100);
	scanf("%s",a);
	//printf("%s\n",a);
	FILE *rp;
	size_t len;
	rp=fopen("test1.txt","rw");
	while(getline(&b,&len,rp)!=-1)
	{
		//char *p=strstr(b,a);
		int f=substr(b,a);
		//printf("%s %s\n",a,b );
		if(f)
			printf("%s",b );
	}
	return 0;
}