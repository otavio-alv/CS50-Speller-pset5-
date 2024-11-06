# CS50-Speller (Problem Set 5)
My own personal solution of the CS50 Speller Problem Set (https://cs50.harvard.edu/x/2024/psets/5/speller/)!

# Objectives
The problem set consists on the implementation of a program that spell-checks a text file based on a dictionary file. This problem aims at understanding and improving the use of data structures (like hash tables and linked lists) and file management in C. The second goal of the project is to create and change hash tables to perfom with better execution time within reasonable memory usage.

For the set completion, the following functions implementations was necessary (on dictionary.c):

* **load:** loads the dictionary in the memory using a hash table. Returns true if it was succesful.
* **unload:** unload the dictionary from the memory. Returns true if it was succesful.
* **check:** searches a word in the hash table and returns true if it's in the table.
* **hash:** hashes a word and returns the corresponding index in the table.
* **size:** if loaded in memory, returns the number of words stored in the table.

Example of expected output (time of execution varies depending on the implementation and system specs):

![image](https://github.com/user-attachments/assets/ab4b18ca-2750-45a1-8218-0735f26f5bef)


# Solution
The aproach used in the program, was to use a imense hash table that index words bases on the first three characters of a word. So in the hash table, the index[0] == AAA, index[1] == AAB, index[2] == AAC, ..., all the way to index[17575] == ZZZ. 

So for example, the word "Computer" would fall in the index that represents index[COM], being added to the linked list by prepending it.

With this implementation, with speed of the algorithm in mind, the trade-off of memory for time execution was necessary.

The functions implementations remained straightforward with that estabilished.

# IMPORTANT
Copying the provided code and submiting it as your own submission for the problem set, goes against the CS50's policy of Academic Honesty (https://cs50.harvard.edu/x/2024/honesty/) as it's considered **Not Reasonable** for the course. **Only** use the code provided as a support if needed. Use the course's provided material to come up with your own solutions and algorithms!

At last, uploading my personal code of the problem set on GitHub is considered reasonable for the course, as stated previously in https://www.reddit.com/r/cs50/comments/63235w/is_this_reasonable/!
