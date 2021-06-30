//this file receives three command line arguments 

//first is path to   
//second is nvars 
//third  is nclauses 


#define or(a,b)  (a||b)
#define and(a,b) (a&&b)
#define not(a)   (!a)
#define one      true
#define zero     false 
#define in(a)    (a-'0')
#define sign(a)  a?' ':'-'

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
		exit(1);
	}
	//printf("file opened successfully \n");	
	
	int times = 0; // keeps count that how many solutions possible
	//i i loop variable  
	n = 512 ; // 2**n ,max 9 variable possible 
        //for(int k=1;k<n && k<max;k++)
	{
		//
		int counter=1,set = 1;
		counter = 1 ;
		while((	read = getline(&line1,&len1,fptr2)) != -1 && (counter<=max)){
			set = 1; 
			while(set <= nvars){
			var[set] = false ;
			//initialize everyone to false ,those get overridden 
			set++ ;
			}
			for(int j=0;line1[j]!='\0';j++)
			{
				if(line1[j] == '1'){
					var[j+1]=true;
					//printf("var[%d]=%d,",j+1,one);			
				}
				else if (line1[j] == '0'){ 
					var[j+1]=false;
					//printf("var[%d]=%d,",j+1,zero);  		
				}
				else if (line1[j] == '\0' )
					continue ;
				//printf("here\n");
			}

			//printf("\n");
		
		fptr = fopen(argv[1],"r");
		if(fptr == NULL ){
			printf("failed to open the file !! \n");
			exit(1);
		}
		cnf_expr=true ;
		int commit_clause = 1;
		
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
					//printf("%c%c ",line[i],line[i+1]);
					i = i + 2;
				}
				else if((int)in(line[i])<=9 && line[i]!=' ' && line[i]!='0'){
					clause = or(var[(int)(line[i] - '0')],clause) ;
					//printf("%c ",line[i]);
					i = i + 1 ;
				}
				else if(line[i] == '0' || line[i] == ' '){
					i = i + 1 ;
					continue ;
				}
			}
			if(commit_clause <=nclauses){ // how many updates to cnf	
				//printf("clause:%d\n",clause);
				cnf_expr = and(clause,cnf_expr);
				commit_clause ++;
			}
			//printf("I am here");	
		}
		if(cnf_expr == true){
			//printf("Sat\n");
			//here output the vars to stdout
			for(int z=1;z<=nvars;z++){	//this block prints 
				printf("%c%d ",sign(var[z]),z);
			}	
			times+=1;
			printf("\n"); // to have new line after each sol 
		}
		else{ 
			//printf("Unsat\n");	
		}
		counter = counter + 1 ;
		fclose(fptr);
		}		

	}
	if (times > 0)
		printf("SAT\n");
	else 
		printf("UNSAT\n");
	fclose(fptr2);
	return 0 ;
}

