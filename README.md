*This project has been created as part of the 42 curriculum by yabouzel.*

# get_next_line

## Description

**get_next_line** is a C function that reads a file descriptor line by line.  
Each call returns the next line from the given file descriptor including the
newline character (`\n`) when present.

The goal of this project is to deeply understand:
- File descriptors
- Static variables
- Memory allocation and lifetime
- Reading data in chunks
- Proper error and EOF handling

The bonus version extends the function to handle **multiple file descriptors simultaneously**.


## Instructions

All you have to do is to copy the ssh and clone it to use this function.

### Compilation

Compile the project with the usual flags:

cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c

For the bonus part:

cc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c

And you can add this flag to change the buffer_size as it's set to 42:

-D BUFFER_SIZE=n

## Resources

read man page: https://man7.org/linux/man-pages/man2/read.2.html

open man page: https://man7.org/linux/man-pages/man2/open.2.html

close man page: https://www.man7.org/linux/man-pages/man2/close.2.html

anything related to file tables and syscalls: https://www.geeksforgeeks.org/c/input-output-system-calls-c-create-open-close-read-write/

### AI was mainly used for:

-Understanding memory ownership rules

-Validating edge cases (EOF, empty files, errors)

-Reviewing algorithm logic

Coding, testing, and fixes were manually done by me.

## Algorithm explaination

The algorithm is based on a persistent static buffer:

1- A static buffer stores leftover data between function calls.

2- Each call checks if a newline already exists in the buffer.

3- If found:

*The line is extracted

*The remaining data is kept for the next call

4- If not found:

*The function reads from the file descriptor into the buffer

*Appends data until a newline or EOF is reached

5- At EOF:

*If data exists, it is returned as the last line

*Otherwise, NULL is returned

# Why?

Avoids rereading data

Handles large files efficiently

Minimizes system calls

Respects memory ownership and lifetime rules

For the bonus version, a static buffer array indexed by file descriptor is used, allowing multiple descriptors to be handled independently.