# get_next_line
Epitech project get_next_line

## Info
#include "get_next_line.h"

char *get_next_line(int fd);
  
## Descritpion
The get_next_line function read the file given as parameter line by line. The first time you call it it will read the first line, the second time the next one...
  
## Return value
The function returns NULL if there is nothing left to read. It returns the line read on success.
  
## Example usage:

```
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void) {
  int fd = open("file", O_RDONLY);
  char *str;
  
  while ((str = get_next_line(fd)) != NULL) {
    printf("%s\n", str);
  }
  return (0);
}
```
