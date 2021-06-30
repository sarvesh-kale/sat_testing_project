##SAT SOLVER 
*this project accepts file input in dimacs format given at https://jix.github.io/varisat/manual/0.2.0/formats/dimacs.html
*clone the project into a directory ,cp the cnf file into the directory .
*This project will not produce correct output if the number of variables is greater than 9.
*the program takes three arguments ,first is cnf file ,second is number of varaibles ,third is number of clauses 
```
./doge_sat example.cnf 3 3 
```
This will print all possible solutions to the terminal 
It will print UNSAT if solution is not possible 
