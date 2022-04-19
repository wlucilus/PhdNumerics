## How to compile the serial code (linux based)
gcc serial.c -o serial.out -lm

## How to compile the parallel code (linux based)
gcc parallel.c -o parallel.out -fopenmp -lm

## How to measure performance time while running the code (linux terminal)
time ./serial.out  
time ./parallel.out
 
 
##Syllabus
-lm ? math library to account for mathematicam function: cos(), sin(), atan() ...etc.  
-fopenmp ? Flag to the compiler to interpret openmp codes
