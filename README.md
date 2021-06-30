# SAT SOLVER 

## PREREQUISITES 
Linux Environment with gcc installed .

## INSTALLATION 

1.clone the repo 
```
https://github.com/sarvesh-kale/sat_testing_project.git
``` 
## USAGE 

*this project accepts file input in dimacs format given < a href="https://jix.github.io/varisat/manual/0.2.0/formats/dimacs.html">here</a> 
*This project will not produce correct output if the number of variables is greater than 9.
*the program takes three arguments ,first is cnf file ,second is number of varaibles ,third is number of clauses 
```
./doge_sat example.cnf 3 3 
```
This will print all possible solutions to the terminal 
It will print UNSAT if solution is not possible 
