#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	printf("Hello \n");
	fork();
	printf("Bye\n");
	return 0;
}