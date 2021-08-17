# SAT SOLVER 

## PREREQUISITES 

Linux Environment with gcc installed .

## INSTALLATION 

1.clone the repo 
```
https://github.com/sarvesh-kale/sat_testing_project.git
```
<!-- USAGE -->
## USAGE 

1.this project accepts file input in dimacs format given here https://jix.github.io/varisat/manual/0.2.0/formats/dimacs.html

2.This project will not produce correct output if the number of variables is greater than 9.

3.copy paste the cnf file you want to execute in the cloned directory 

4.the program takes three arguments ,first is cnf file ,second is number of varaibles ,third is number of clauses.</br>
If the name of file is example.cnf then execute it using following -->

```
This will print all possible solutions to the terminal </br>

$ ./sat example.cnf 3 3 
 1 -2 -3 
-1 -2  3 
 1 -2  3 
-1  2  3 
SAT
```
The first line says that when variable 1 is true , 2 is false and 3 is false then all </br>
CNF expressions written in example.cnf evaluates to true therefore SAT is printed .
It will print UNSAT if solution is not possible .
