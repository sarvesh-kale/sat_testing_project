//this file receives three command line arguments 

//first is path to   
//second is nvars 
//third  is nclauses 


#define or(a,b)  a||b
#define and(a,b) a&&b
#define not(a)   !a
#define one      T
#define zero     F


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
int main(int argc ,char **argv)
{	
 	FILE *fptr ;
	char *line = NULL ;
	size_t len =0 ;
	ssize_t read ;
	fptr = fopen(argv[1],"r");
	int nvars = atoi(argv[2]),nclauses=atoi(argv[3]);
	
	struct boolean{
		bool value ;

	};
	int i = 1; // just for looping 
	while(i<=nvars){ // define variables here 
		bool var[i] ;
		i ++ ;
	}

	if(fptr == NULL ){
		printf("failed to open the file !! \n");
		exit(1);
	}

	//printf("file opened successfully \n");	
	
	while((read = getline(&line , &len ,fptr)) != -1 )// 
	{
		if(line[0] == 'c' || line[0] == 'p') // imagine line is pointing to string 	
			continue ;                   // this skips line starting with c which are comments  
		//len contains the length of line 
		for(i=0 ; line[i] != '\0' ; i++) // loop condition is good 
		{
				
		}
				
	}
	return 0 ;
}

