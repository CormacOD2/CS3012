# CS3012 Software Engineering CS3012 assignment 1

### Student Number : 15325054

## Project Overview 

A simple C program that builds a binary tree allowing you to find the lowest common ancestor of two nodes. For purposes of effciency when handling large amounts of data being inputed I gave the option to convert the binary tree into a binary search tree.

## Input

Input for building the binary tree is by text file input. If you wish to change the input you can either edit the "nodeInput.txt" file or by changing the global variable "FILE_NAME" at the top of input.c to your own text file. It will only accept numbers (including negative) separated by any number of commas, spaces or tabs. Any other char/symbol will be rejected, any number attached to those chars will also be rejected e.g (1a,a1,7-7,--7,^6,%6 .. etc).  

## Testing

When running the program it will ask if you want to use test input. By selecting this option it will use a different text file with random chars and symbols to make sure the files are inputed correctly. It will then run a small number to written tests to confirm the program is working as intended. Ran into difficulty when tring to use both CUnit and Check for unit testing this program , as such I hate to write my own small test functions. There are not that many as explained earlier in my Input section that it filters out any unwanted chars being passed into the program to ensure that only ints may enter, this means no unwanted type will access my binaryTree.c functions.

## Known Issues

My biggest oversite with this project was forgetting overflow issues when inputing from the text file and did not have enough time to fix it before the deadline. 
