# graham-scan
An implementation of the Graham Scan algorithm written in C.

## About
The program takes in an input from `stdin` in the form:

```
N
x_0 y_0
x_1 y_1
... ...
x_N y_N
```

Where N is the number of points in a 2D cartesian plane and the corresponding x- and y-values are separated by a newline. There is a helper script written in Python to help generate data of a given size.


When ran, the program will output the points of the convex hull while also showing how long it took to run. This code also serves to show examples of proper memory management and being free of errors. 

## Usage
In case you want to try the program out for yourself, you'll first need to clone the repository:

```
$ git clone https://github.com/iamtheburd/graham-scan && cd graham-scan
```

Use `make` to generate the executable:

```
$ make
```

Execute the Python script to generate some random data:

```
$ python gen_point_data.py 1000000 # generates 1,000,000 random 2D points
```

Finally, execute the program:

```
$ ./chull < large_data.txt
```

You can also use `valgrind` to confirm that there are no errors and no memory leaks, even with a large file. The following results are on a virtual machine with the following specs:

* Lubuntu 18.04
* 2 cores
* 2 GB RAM

```
$ valgrind --leak-check=full ./chull < large_data.txt
==8692== Memcheck, a memory error detector
==8692== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==8692== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==8692== Command: ./chull
==8692== 
Found convex hull in 12.71408500 seconds:
(18.84, 0.94)  (334.59, 0.07)  (654.80, 0.04)  (2408.12, 0.01)  (7195.13, 0.00)  (8320.53, 0.03)  (9519.31, 0.18)  (9978.81, 0.62)  (9994.74, 5.74)  (9996.71, 28.93)  (10000.59, 124.68)  (10000.86, 451.79)  (10000.98, 687.49)  (10001.00, 2456.11)  (10001.00, 3297.43)  (10000.95, 6108.34)  (10000.90, 7521.07)  (10000.75, 9373.16)  (10000.57, 9875.90)  (9998.68, 9967.00)  (9996.56, 9981.09)  (9990.99, 9996.01)  (9968.69, 10000.89)  (5605.88, 10000.99)  (2652.26, 10000.99)  (120.56, 10000.96)  (77.15, 10000.03)  (8.13, 9997.96)  (6.36, 9986.13)  (4.09, 9958.70)  (0.59, 9915.83)  (0.07, 9840.56)  (0.04, 9465.24)  (0.03, 9146.69)  (0.03, 4144.98)  (0.03, 249.72)  (0.71, 29.29)  (2.47, 9.20)  
==8692== 
==8692== HEAP SUMMARY:
==8692==     in use at exit: 0 bytes in 0 blocks
==8692==   total heap usage: 1,000,004 allocs, 1,000,004 frees, 48,005,104 bytes allocated
==8692== 
==8692== All heap blocks were freed -- no leaks are possible
==8692== 
==8692== For counts of detected and suppressed errors, rerun with: -v
==8692== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
$
```

Note: this takes 12 seconds since the input file is very large and valgrind has to keep track of a LOT of memory. In normal usage on this virtual machine, this program can find the convex hull of one million points in roughly half a second (without optimizations enabled for the compiler).

## Credit
This implementation is heavily derived from the C++ implementation by Manish Bhojasia written on Sanfoundry. You can find his work [here](https://www.sanfoundry.com/cpp-program-implement-graham-scan-algorithm-find-convex-hull/).
