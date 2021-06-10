# Introduction
The project get_next_line compiles as a library
Compiling with the get_next_line library allows the get_next_line function to be used

# How to compile and run
git clone <link> <name_directory>
cd <name_directory>
make
# add your own main.c 
# path_to_library is relative to main.c
gcc main.c -L<path_to_library> -lget_next_line -o get_next_line
./get_next_line

# Makefile options
make - compiles the library
make bonus - compiles the library with extra functionality:
	managing multiple file descriptors without losing the reading thread on each of the file descriptors
make clean - removes all object files
make fclean - removes all object files and the library
make re - first removes all object files and the library and then compiles the project

# Functionality
get_next_line reads a line from a file descriptor up but not including a newline or EOF

# Protoype
int get_next_line(int fd, char **line);

# Parameters
line is the address of a string in which the line that was read will be placed in the form of a dynamically allocated string
fd is the file discriptor from which get_next_line will read

# Return value
Returns -1 in case of an error
Returns 0 once EOF has been reached
Return 1 if a line has been successfully read
