Searching algorithms and application implementation in C, C++, Python.

---> In almost all programs, we take INPUT Number of elements (n), range of numbers (r)  to generate an array/vector/list of "n" integers within range "0" to "r-1". We also take input key within same range. As the input array is randomly generated, key may or may not be present in the array/vector/list.

Output is index or element itself, depending on the problem statement.

--->In windows, you need to install GCC compiler. Easy way to install it is to install CodeBlocks IDE and set path to gcc in Windows Path variable.

--->Additional Files for Program Compilation and Execution

C : c_utilities.h and c_utilities.c

C++ : cpp_utilities.h and cpp_utilities.cpp

Download given respective files and keep in the same directory as source file.


	C Programs: 

	Compilation (Ubuntu/Windows) : gcc <source_file_name> c_utilities.c -o <object_file_name>
	
	Running (Ubuntu) : ./object_file_name
	
	Running (Windows) : object_file_name.exe

	Example: 
	
	gcc -g linear_search.c c_utilities.c -o linear_search
	
	ub: ./linear_search
	
	win: linear_search.exe


	
	C++ Programs: 
	
	Compilation (Ubuntu/Windows) : g++ -o <object_file_name> <source_file_name> cpp_utilities.cpp
	
	Running (Ubuntu) : ./object_file_name
	
	Running (Windows) : object_file_name.exe

	Example:

	gcc -g -o linear_search linear_search.cpp cpp_utilities.cpp 
	
	ub: ./linear_search
	
	win: linear_search.exe



---> Python searching programs require one addtional file to run "utilities.py". Download this file along with source file you want to run and keep all the file in same directory/folder.
	
	Executing Python programs: python <source_file_name>

	Example: python linear_search.py
