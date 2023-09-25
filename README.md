# README

## Things to be aware of
> [!WARNING]
> Please read before testing

- In order to run cat <myshell.cpp [&] as specified in the test cases myshell.cpp needs to be in the current working directory
 - myshell.cpp is not in the root directory since the program structure is split up into separate directories, for easy of use for graders I have copied the file and added it to the root directory, however, the cpp file in the root directory is not for compiling purposes

## How to Compile Program

Run the `make all` command to compile the program.

## How to Run Program

Run `./myshell` to run the program. You can add `./myshell -Debug` to view debug information.


## Overview
This program is a functioning shell, which allows for the viewing, storage, and modification of files.

## Use
The following instructions are examples of programs that can be executed using this shell:
```
ls -l (show list of files in current directory)
ls -l >testfile.txt
grep -i shell testfile.txt
cat ./src/myshell.cpp >test.txt
exit
``````
## Contact:
Chase Lamkin: cml81@students.uwf.edu
Caleb Shafer: cjs81@students.uwf.edu
