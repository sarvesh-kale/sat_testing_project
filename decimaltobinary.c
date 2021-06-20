#include<stdio.h>
#include<stdlib.h>
int main(int argc , char **argv)
{	
	int n;
	n=atoi(argv[1]);
	while(n>0)
	{		
		printf("%d",n%2);
		n=n/2 ;
	}
	printf("\n");
	return 0;
}
