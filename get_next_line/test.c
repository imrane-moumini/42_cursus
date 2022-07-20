#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
char	*cutbuff(char	*str)
{
	int	i;
	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			while (str[i] != '\0')
			{
				str[i] = '\0';
				i++;
			}
		}
		i++;
	}
	return(str);
}
int	is_end_of_line(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
void    test(int fd)
{
    int i;
	char *p;
    char *buff;

    buff = malloc(sizeof(char) * BUFFER_SIZE);
    i = 1;
    i = read(fd, buff, BUFFER_SIZE);
    printf("%i =>%s\n", i, buff);

}
void    testb(int fd)
{
    int i;
	char *p;
    char *buff;

    buff = malloc(sizeof(char) * BUFFER_SIZE);
    i = 1;
    i = read(fd, buff, BUFFER_SIZE);
    printf("%i =>%s\n", i, buff);

}
int main(void)
{
    //int fd;

    //fd = open("text.txt", O_RDONLY);
    //test(fd);
    //test(fd);
	char *str;
	printf("%c",str[0]);
}