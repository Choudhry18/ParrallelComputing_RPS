# CSCI-2321 Homework 7

For this assignment you will write a program that demonstrates the difficulty of multithreading, by creating race conditions that allow the program to randomly select among three options. You may complete this assignment in groups of up to 3 people.

## Behavior
* The program will play rock-paper-scissors against input from the command line.
* When run, the program should ask the user to enter `r`, `p`, or `s`. You may optionally allow longer strings, but it is simplest to read a single character from the command line.
* After printing the prompt, but before reading the input, the program should determine which of rock, paper, and scissors it is going to play.
* After the input is read, the program should print a string noting what the user played, what the computer played, and who won the round.
* The program should then repeat until an end condition is met: the user enters a blank line, the input reaches `EOF`, or the program is halted with `ctrl-c` or `ctrl-d`.


## Requirements
* The program should be written in C.
* The choice of rock, paper, and scissors should emerge from race condition(s) between threads.
   * You may not use random number generators.
   * You may use any form of explicit multithreading, but I highly recommend [pthreads](https://www.tutorialspoint.com/multithreading-in-c) are the simplest way to create threads.
   * Your program must create at least two threads, and should have a race condition between those threads.
   * You do not have to equally weight all three options. All three behaviors should be observed in most 20-round games.
   * If you have a hard time getting the race condition to manifest, consider putting it inside a loop.

## Deliverables

This assignment has the following deliverables:
* The full source code for your program, uploaded as a file to this respository.
* A transcript of running the programs multiple times, uploaded as a file to this repoistory.
  * For full credit the program should have different outputs. However, include the transcript even if you cannot.
* A written description covering the following points, as a modification of this README.md file.
  * Where is the race condition in your code.
  * What computer, compiler, and settings did you use to generate your transcript.
  * A brief (2-4 sentence) reflection on getting (or attempting to get) the race condition to manifest.

## Explanation
* The race condition is in line 12 and 22 where where both threads are accessing and modifying the dice variable simultaneously. The outcome depends on which thread gets to access the dice variable first. 
* I ran the program on a 2020 macbook Pro with a 1.4 GHz Quad-Core Intel Core i5 Processor. I used gcc from the GNU compiler collection as my compiler. My terminal command was gcc hw7.c -lpthread. 
* My race condition used two different functions (Rat1 and Rat2 cause it's a Rat race (◠﹏◠) ) that were called by different threads. They both accessed one variable. I tried different combinations of arthimetic operations in the end what worked was multiplication in one thread and subtraction in the other. If one thread was able to run a few multiply instructions the dice variable will grow quite large and the end result will be great than 0. If subtractions are done first the dice variable will go to negative. In case they both cancel each other out it becomes 0. I did the arthimetic operation inside a huge loop in order for it to work.   
