#include<stdio.h>
#include<stdlib.h>
int main(int argc , char **argv)
{	
	int n,i=0;	
	while(i<512){
	n=i ;
	while(n>0)
	{		
		printf("%d",n%2);
		n=n/2 ;
	}
	printf("\n");
	
	i++;
    }
	return 0;
}
