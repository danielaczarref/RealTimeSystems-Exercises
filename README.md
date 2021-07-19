# Real Time Systems - Exercises

Exercises proposed for the subject of Real Time Systems of the Computer Engineering major

First implemented exercise:

1) Create a multithreaded program to calculate the product of two square integer matrices of order 4. Sixteen threads must be created, each to calculate one of the sixteen elements of the resulting matrix.


Second implemented exercise:

2) Create a multithreaded program that performs a search for a number in a random vector of 100 integers. Four threads must be created and the vector must be populated with system-generated random integer numbers.


## Running

- Make sure you have all essentials installed

```
sudo apt-get install build-essential
```

You can run my programs just by typing ./matrizes (to run my first program) or ./vetor (to run my second program) in your terminal, but, in case in want to generate the executable version of the program all by yourself, you need to run:


```
gcc programDescription.c -o outputExectableDescription -lpthread
```

After you run it, you can run your own executable (with the description of your preference):

```
./outputExectableDescription
```
