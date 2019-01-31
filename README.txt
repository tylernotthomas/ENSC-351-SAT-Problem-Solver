Lab 5 SAT Problem README
Authors: Tyler Johnson, Andrew Redey

To solve an SAT problem perform the following:

1. Open the Linux terminal and, using the 'cd' command, navigate to the project folder 'lab5multithreaded'
	-The folder should contain: lab5multi.cpp, lab5utility.h, Makefile, problem.cnf and this README.txt

2. problem.cnf contains the SAT problem the program will solve
	-By default a test problem with 20 variables and 91 clauses populates the file
	-To change the SAT problem, simply copy and paste in the desired problem and save your changes to problem.cnf

3. Compile the program by using the terminal command 'make'
	-This will run the command in Makefile and produce lab5multi.o

4. Run the program using the command: ./lab5multi.o
