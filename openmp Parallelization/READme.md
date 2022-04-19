# Description
Two codes:   
+ One that computes some costly matrix operations in serial manner (1 processor 1 thread) 
+ One that computes some costly matrix operations in parallel manner (1 processor 2 thread) 

Main resources  
https://computing.llnl.gov/tutorials/openMP/




## How to compile the serial code (linux based)
gcc serial.c -o serial.out -lm

## How to compile the parallel code (linux based)
gcc parallelSections.c -o parallelSections.out -fopenmp -lm

## How to measure performance time while running the code (linux terminal)
time ./serial.out  
time ./parallel.out
 
 
## Syllabus  
-lm ? math library to account for mathematicam function: cos(), sin(), atan() ...etc.  
-fopenmp ? Flag to the compiler to interpret openmp codes
