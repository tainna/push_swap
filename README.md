*This project has been created as part of the 42 curriculum by taalmeid.*

# Push_swap

## Description

The Push_swap project is a coding challenge that requires us to sort a list of random numbers. The catch is that we cannot just swap numbers however we like. We are limited to using two stacks (called Stack A and Stack B) and a specific set of operations.

The goal is to write a program that calculates the most efficient sequence of moves to sort the numbers. The grade depends on how few moves the program uses:
- For 100 numbers: The goal is less than 700 moves.
- For 500 numbers: The goal is less than 5500 moves.

### The Logic Used (Turk Algorithm)
To solve this, I used a "Greedy" algorithm. Here is how it works in simple terms:
1. Move almost all numbers from Stack A to Stack B.
2. Look at the numbers in Stack B. For each number, calculate how many moves it would take to put it in the right place in Stack A.
3. Pick the number that requires the fewest moves (the "cheapest" one).
4. Move that number to Stack A.
5. Repeat until Stack B is empty, then make a final rotation to ensure the list starts with the smallest number.

## Instructions

### How to Compile
To create the program, open your terminal in the project folder and run:

make

This will generate an executable file named push_swap.

### How to Run
You run the program by giving it a list of numbers to sort.

Example:
./push_swap 2 1 3 6 5 8

The program will print the instructions (like sa, pb, ra) needed to sort these numbers.

### How to Test
You can use the provided checker tool to confirm the numbers are sorted and count the moves.

To check if it sorts correctly:
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

To count the number of moves (for 500 random numbers):
ARG=$(shuf -i 1-500 | tr '\n' ' '); ./push_swap $ARG | wc -l

## Resources

### References
- Sorting Algorithms: Basic concepts of how computers sort data.
- Stack Data Structure: Understanding how Last-In, First-Out (LIFO) works.
- Big O Notation: Understanding code efficiency.
- Ocean Github and Youtube chanel

### AI Usage
As part of the learning process, Artificial Intelligence was used for specific tasks in this project:

1. Debugging Memory Errors:
AI helped identify a crash caused by allocating 0 bytes of memory. It pointed out that the stack capacity variable was not initialized correctly in the init_stack function, which caused "Invalid write" errors in Valgrind.

2. Code Optimization (Norminette):
AI suggested ways to shorten the init_stack function to fit the 42 Norm limit (maximum 25 lines) by combining variable assignments and error checks without changing the logic.

3. Math Logic for Costs:
AI explained the correct math for calculating the cost of double moves (rr and rrr). It clarified that when both stacks rotate in the same direction, the cost is the maximum of the two rotations, not the sum. This helped reduce the total operations for 500 numbers to below the 5500 limit.
