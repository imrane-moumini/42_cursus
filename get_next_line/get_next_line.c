/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:28:39 by imoumini          #+#    #+#             */
/*   Updated: 2022/07/10 16:28:44 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
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

char	*get_next_line(int fd)
{  
	char	*buff;
	char	*entireline;
	int		nbr_of_bytes_read;
	static int		begin_of_new_line;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1); //have to free
    while (is_end_of_line(buff) != 1)
    {
		nbr_of_bytes_read = read(fd, buff, BUFFER_SIZE);
		if (nbr_of_bytes_read == -1)
		{
			return (NULL);
		}
		begin_of_new_line = begin_of_new_line + nbr_of_bytes_read;
		entireline = ft_strjoin(entireline, buff); // have to free
	}
	begin_of_new_line = begin_of_new_line + 1;
	return (entireline);
}

int main(void)
{

    int fd;
	char *p;
    fd = open("text.txt", O_RDONLY);
    p = get_next_line(fd);
	int i = 0;
	while (p[i] != '\0')
	{
		printf("im here\n");
		if (p[i] == 'e')
		{
			printf("im here 92\n");
			p[i] = 'a';
		}
		i++;
	}
	printf("%s", p);
}
