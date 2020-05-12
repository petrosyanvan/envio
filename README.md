# Envio
Envio Systems GmbH - Technical Assessment

# The Problem
## Coding Task-Abstract
Sort an array of 0s, 1s and 2s in linear time complexity, like this one:
```c
int arr[30] = { 2, 2, 1, 0, 1, 0, 1, 1, 0, 2, 2, 1, 1, 1, 2, 0, 0, 1, 1, 0, 1, 0, 1, 2, 0, 0, 0, 1, 1, 2};
```
### Description
Given an array consisting only 0s, 1s and 2s, please provide an algorithm sorting that array in
O(n) time complexity. So in the resulting sorted array, 0s will be at starting, then the 1s & then the 2s.
- The usage of built-ins or libraries, like `std::sort` or `boost::sort` is not allowed.
- Coding style and quality is more important than feature completeness.
- What to submit: A git repository of the work and all commits made on the way.

# Solution

Current problem is very similar to the [Dutch national flag problem](https://en.wikipedia.org/wiki/Dutch_national_flag_problem), which is a computer science programming problem proposed by Edsger Dijkstra. The flag of the Netherlands consists of three colors: red, white and blue. Given balls of these three colors arranged randomly in a line (the actual number of balls does not matter), the task is to arrange them such that all balls of the same color are together and their collective color groups are in the correct order.

This problem can also be viewed in terms of rearranging elements of an array. Suppose each of the possible elements could be classified into exactly one of three categories (bottom, middle, and top). The problem is then to produce an array such that all "bottom" elements come before (have an index less than the index of) all "middle" elements, which come before all "top" elements.

In our particular scenario, 1 is the "middle" element or the pivot, so all 0's should come on the left side of the pivot and all 2's on the right side of the pivot. To achieve it we are using linear-time partition routine to separate all elements smaller than the pivot, equal to the pivot and greater than the pivot. With current solution we are rearranging the array with the single traversal, with time complexity of `O(n)` and space complexity of `O(1)`.

# Prerequisites
- GCC
- GNU Make


# Building and Running
Use the following commands in the command line to clone, build and run the program.
```
git clone https://github.com/petrosyanvan/envio
cd envio
make
./runner
```
