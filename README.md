# 42_push_swap
Stack sorting algorithm with limited moves available

This project was done as part of my education at Codam, part of the 42 network of coding schools.

<h3>Assignment</h3>

Write 2 programs:

• The first, named **checker** which takes integer arguments and reads instructions onthe standard output. Once read,\ 
  checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.\
• The second one called **push_swap** which calculates and displays on the standard output the smallest progam using \
  Push_swap instruction language that sorts integer arguments received.

All the integers in the input should be unique.

The push_swap instruction language consists of the following options:

**sa:** swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.\
**sb:** swap the first 2 elements at the top of stack b. Do nothing if thereis only one or no elements.\
**ss:** sa and sb at the same time.\
**pa:** take the first element at the top of b and put it at the top of a. Do nothing if b is empty.\
**pb:** take the first element at the top of a and put it at the top of b. Do nothing if a is empty.\
**ra:** rotate a - shift up all elements of stack a by 1. The first element becomes the last one.\
**rb:** rotate b - shift up all elements of stack b by 1. The first element becomes the last one.\
**rr:**   ra and rb at the same time.\
**rra:**  reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.\
**rrb:**  reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.\
**rrr:**  rra and rrb at the same time.

The full assignment can be found here:\
[push_swap subject](https://github.com/LER1990/42_subjects/blob/master/push_swap.en.pdf)

<h4>Criteria for evaluation</h4>

The evaluation of this project depends on how many operations it takes the implementation to sort any gives list.\

For a list of 3 values, the maximum number of operations is 3.

For a list of 5 values, the maximum number of operations is 12.

For a list of 100 values, the scale looks as follows:\
• Less than 700 operations: 5 points\
• Less than 900 operations: 4 points\
• Less than 1100 operations: 3 points\
• Less than 1300 operations: 2 points\
• Less than 1500 operations: 1 point

My solution requires around 550 moves on average

For a list of 500 values, the scale looks as follows:\
• Less than 5500 operations: 5 points\
• Less than 7000 operations: 4 points\
• Less than 8500 operations: 3 points\
• Less than 10000 operations: 2 points\
• Less than 11500 operations: 1 point

My solution requires around 5200 moves on average

<h3>Solution</h3>

Initially I started out with a variation on the quicksort algorithm, but I found that this didn't quite allow me
to make efficient use of the possible operations, so I came up with a different, simpler solution that makes more
use of the option to rotate both lists at the same time.

My algorithm consists of the following steps:

1. Push two items from stack a to stack b and sort them in descending order
2. Then, while there are more than three items on stack a:
    + calculate the distance of every item in a to its correct position in b
    + calculate, based on the distances, how many moves every item would require to arrive at it's correct position
    + execute the moves required by the item that has the lowest number of moves to it's position
3. Sort the remaining items in a
4. Repeat the sorting process mentioned in step 2, only from b to a this time, until b is empty
5. Rotate a so that the lowest integer in it is at the top of the stack
