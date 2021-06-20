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
	FILE *fptr2 ; // to read the patterns pre-generated to be assigned as T ,F to vars
	char *line = NULL ;
	char *line1= NULL ;
	size_t len =0 ;
	size_t len1 =0 ;
	ssize_t read ;
	ssize_t read1 ;

	fptr2= fopen("binaries512.txt","r");
	int nvars    = atoi(argv[2]), // no of variables 
	    nclauses = atoi(argv[3]); // no of clauses 
	bool cnf_expr=true;
	bool clause=false;
	int i = 1,n ; // just for looping 
	int max=1;
	// define cnf  variables here 
	bool var[nvars+1] ;
	while(i<=nvars){
		max=max*2;
		i++ ;
	}
	if(fptr2 == NULL){
		printf("Failed to open the file !! \n");
	}
	printf("file opened successfully \n");	
	
	//i i loop variable  
	n = 512 ; // 2**n ,max 9 variable possible 
	for(int k=1;k<n && k<max;k++)
	{
		//initialize veryone to false ,those get overridden 
		//
		int counter = 1;
		while(counter <= nvars){
			var[counter] = false ;
			counter++ ;
		}
		while((	read = getline(&line1,&len1,fptr2)) != -1)
			for(int j=0;line1[j]!='\0';j++)
			{
				if(line1[j] == '1')
					var[j+1]=true;
				else if (line1[j] == '0') 
					var[j+1]=false;
				//printf("here\n");
			}
				
		fptr = fopen(argv[1],"r");
		if(fptr == NULL ){
			printf("failed to open the file !! \n");
			exit(1);
		}
		cnf_expr=true ;
		while((read = getline(&line , &len ,fptr)) != -1 )// 
		{
			if(line[0] == 'c' || line[0] == 'p') // imagine line is pointing to string 	
				continue ;                   // this skips line starting with c which are comments  
			//len contains the length of line 
			clause = false ;// initialize to false 
			for(i=0 ; line[i] != '\0' ; ) // loop condition is good 
			{
				//we are going to construct the cnf first 
				
				if(line[i] == '-'){
					clause = or(not(var[(int)(line[i+1] - '0')]),clause);
					i = i + 2;
				}
				else if((int)in(line[i])<=9 && line[i]!=' '){
					clause = or(var[(int)(line[i] - '0')],clause) ;
					i = i + 1 ;
				}
				else if(line[i] == '0' || line[i] == ' '){
					i = i + 1 ;
					continue ;
				}
				
			}
			cnf_expr = and(clause,cnf_expr);
			//printf("I am here");	
		}
		if(cnf_expr == true)
			printf("Sat\n");
		else 
			printf("Unsat\n");	
		
		fclose(fptr);
	}
	fclose(fptr2);
	return 0 ;
}

