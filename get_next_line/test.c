#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    int i;
	char *p;
    char *buff;
    
    buff = malloc(sizeof(char) * BUFFER_SIZE);
    
    i = 1;
    fd = open("text.txt", O_RDONLY);
    
    while (i != 0)
    {
        i = read(fd, buff, BUFFER_SIZE);
        printf("%i\n", i);
	    printf("%s", buff);
    }
}