[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9916143&assignment_repo_type=AssignmentRepo)
# Assignment 1 Description

Name: Donald Lei

All parts of class Points2D were finished. While doing this assignment, I faced issues in figuring out how to implement the functions because the private member sequence_ was defined to be an array. I thought that sequence_ could only contain two objects, and it took me a while to decide on how to approach it. Until I realized that the size could be used to allocate more space than just those two objects, and actually create a sequence that we had to make. 

To run the program I compiled points2d.h doing g++ test_points2d.cc -std=c++17 -o test_points2d, and then testing my program using ./test_point2d < test_input_file.txt.


## Information about the repository

This repository contains the following:
- Starter code: `points2d.h`, `test_points2d.cc`,`test_input_file.txt`, `expected_output.txt`, `Makefile` and `README.md`
- Assignment specification: `Spring23-Assignment1.pdf`

## Running the assignment

You will use this exact `Makefile` for your Assignment 1. Failure to do so will result in *deduction* of points.

To compile on terminal, type:

```bash
make clean
make all
```

To delete executables and object files, type:

```bash
make clean
```

To run, type:

```bash
./test_points2d
```

## Providing Input from Standard Input

To run with a given file that is redirected to standard input:

```bash
./test_points2d < test_input_file.txt
```
