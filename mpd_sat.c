//this file receives three command line arguments 

//first is path to   
//second is nvars 
//third  is nclauses 


#define or(a,b)  a||b
#define and(a,b) a&&b
#define not(a)   !a
#define one      T
#define zero     F
#define in(a)    a-'0'

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
int main(int argc ,char **argv)
{	
 	FILE *fptr ;
	char *line = NULL ;
	size_t len =0 ;
	ssize_t read ;
	fptr = fopen(argv[1],"r");
	int nvars = atoi(argv[2]),nclauses=atoi(argv[3]);
	bool cnf_expr=true;
	bool clause=false;
	int i = 1,n ; // just for looping 
	// define cnf  variables here 
	bool var[i+1] ;

	if(fptr == NULL ){
		printf("failed to open the file !! \n");
		exit(1);
	}

	//printf("file opened successfully \n");	
	
	//i i loop variable  
	n =(int)pow(2,nvars) ; // 2**n 
	//for(i=0;i<n;i++)
	{
		
		while((read = getline(&line , &len ,fptr)) != -1 )// 
		{
			if(line[0] == 'c' || line[0] == 'p') // imagine line is pointing to string 	
				continue ;                   // this skips line starting with c which are comments  
			//len contains the length of line 
			clause = false ;// initialize to false 
			for(i=0 ; line[i] != '\0' ; i++) // loop condition is good 
			{
				//we are going to construct the cnf first 
				
				if(line[i] == '-')
					clause = or(not(var[(int)(line[i+1] - '0')]),clause);
				else if((int)in(line[i])<=9)
					clause = or(var[(int)(line[i] - '0')],clause) ;
				else if(line[0] == '\0')
					continue ;
				
			}
			cnf_expr = and(clause,cnf_expr);
				
		}
		if(cnf_expr == true)
			printf("Solution :");
	}
	return 0 ;
}

