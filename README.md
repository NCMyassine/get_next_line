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

### Compilation

Compile the project with your usual flags:

```sh
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -D BUFFER_SIZE

