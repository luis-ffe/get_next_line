# Get Next Line

## Overview
**Get Next Line** is a project focused on creating a function that reads and returns one line at a time from a file descriptor, whether from a file or standard input. The function continues to return each line every time it’s called, allowing for incremental reading. This project was a great exercise in handling memory, file descriptors, and buffer management efficiently.

I learned to work with static variables in C to maintain state across function calls without relying on global variables.

## Key Features
- A `get_next_line()` function that reads and returns a line from a file descriptor.
- The function includes the newline character (`\n`) in the returned string if present.
- When there’s no more to read or in case of an error, the function returns `NULL`.
- Efficient memory usage by reading incrementally, avoiding the need to store the entire file in memory.

### Example
Here’s how `get_next_line()` can be used in a loop to read a file line by line:

```c
int fd;
char *line;

fd = open("file.txt", O_RDONLY);
line = get_next_line(fd);
while (line != NULL)
{
    printf("%s", line);
    free(line);
    line = get_next_line(fd);
}
close(fd);
```

## Bonus Features
I also added the following bonuses:
- Manage multiple file descriptors simultaneously, allowing the function to handle multiple files without losing the reading thread for each.
- The function uses only one static variable.

## Installation
1. Clone my repository:
2. Navigate to the project directory:
   ```bash
   cd Get Next Line
   ```
3. Compile the project using the provided `Makefile`:
   ```bash
   make
   ```

## Requirements
- C programming language.
- Must use the `read`, `malloc`, and `free` functions. No global variables or the `lseek()` function allowed.
  
## External Functions
The project uses the following external functions:
- `read`, `malloc`, `free`, and custom helper functions.

