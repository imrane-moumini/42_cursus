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
char	*get_next_line(int fd)
{  
    int nbr_bytes_read;
	char	*buff;
	buff = malloc(sizeof(char)*BUFFER_SIZE + 1);
    nbr_bytes_read = read(fd, buff, BUFFER_SIZE);
	printf("%s",buff);
}

int main(void)
{
    int fd;
    fd = open("text.txt", O_RDONLY);
    get_next_line(fd);
}
