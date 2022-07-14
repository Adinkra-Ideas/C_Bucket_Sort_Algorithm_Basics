# push_swap 42 schools project
Push_Swap is a sorting algorithm project written in C.

This program sorts, from lower to bigger, the integers given as parameters. Integers received as arguments from the command line are saved as a stack (called stack A), where the first parameter given is at the top of it and the last one is at the bottom, and it is possible to use a second stack (called stack B) to help the sorting.

## Project's Limitations
Only the following movements are allowed:

sa: swap A, swaps the top two elements of the stack A;

sb: swap B, swaps the top two elements of the stack B;

ss: sa and sb at the same time;

pa: push A, pushes the top element from B and puts it onto A (does nothing if B is empty);

pb: push B, pushes the top element from A and puts it onto B (does nothing if A is empty);

ra: rotate A, takes the top element of stack A puts it onto the bottom;

rb: rotate B, takes the top element of stack B puts it onto the bottom;

rr: ra and rb at the same time;

rra: reverse rotate A, takes the element at the bottom of A and puts it onto the top;

rrb: reverse rotate B, takes the element;at the bottom of B and puts it onto the top;

rrr: rra and rrb at the same time.
