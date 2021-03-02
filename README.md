# Walmart-Theatre-Seating-Problem
Solution for Theatre Seating Problem for Walmart Interview

Instructions to run the code:
1. Simply clone or download the repository and run the code! But please keep the following in mind before running
  a. The solution uses some of C++11 STL functions so your compiler has to be at least g++ 7.0.0 or later edition
  b. Before running the solution, the input and output files have to be in the same folder as the solution.cpp
  c. If the input or output files are in the different directory, simply change the paths in line 62(input) and line 65(output).

The main approach I took to solve this problem:
Challenges during solving the problem:
1. Reading the input file from the text file.
2. After reading the file, choosing which data structure to store the reservation information optimally.
3. Choosing data structure/method to figure the availability of specific seat.
4. Building a function to optimally assign the seats to each reservation.
5. Deciding what to do with the reservation that are not possible to assign the seats.
6. Choosing data structure/method to store the seating information of each seat.
7. Outputing the answer to a text file.

Solution to each challenges:
1. Used fstream STL to input the file line by line.
2. Chose map(dictionary) to store the input.
3. Chose 2-D boolean array to check the availability of each seats.
4. A simple recursive function that solves the problem dynamically.
5. Decided to simply mark unassigned reservations as "Waitlisted".
6. Chose another map(dictionary) to store the ticket information of each reservation.
7. Used fstream STL to output the result to a text file.

Pros of the solution:
1. Assigns seats and uses remaining available seats as optimally as possible.
2. Commented the code neatly so easier for the user to understand.
3. Uses the most optimal data structures(hashtable, 2-D array) at each step (in my opinion).
4. Uses resursive method to solve the problem.
5. Checks the seating from the very last row to check if we are using the seating resources optimally.

Things to optimize / work on:
1. Verifying whether the input file is valid or not
2. Handle the problem when reservations with more than 20 seats occur.
3. Since I used map, the keys in the output are automatically sorted so the reservation order might be mixed up. 
   For example, if you have more than 10 reservations R0010 comes out before R002.

