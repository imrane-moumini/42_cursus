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
}

char	*get_next_line(int fd)
{  
	char	*buff;
	char	*curentline;
	char	*nextline;
	int		nbr_of_bytes_read;
	static int		begin_of_new_line;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1); //have to free
	// je dois gerer le cas ou ya pas de \n et du coup ca va juska la fin du doc et ca sarrette
	// ya 2 cas
		// le cas oou g lu lentiereter du doc et ya pas de \n 
			// je sais que c la fin du doc quand read return 0
			// du couil retourne le nbr delement puis je lance une deuxieme fois
			// c la deuxieme fois quil etourne 0
		// le cas ou g lun petit morceau et du coup ya pas de \n
    while (is_end_of_line(buff) != 1)
    {
	
		nbr_of_bytes_read = read(fd, buff, BUFFER_SIZE);
		if (nbr_of_bytes_read == -1)
		{
			return (NULL);
		}

		begin_of_new_line = begin_of_new_line + nbr_of_bytes_read;
		if (is_end_of_line(buff) == 1)
		{
			// supprimer la partie de buff qui depasse
			cutbuff(buff);
			curentline = ft_strjoin(curentline, buff); // have to free
			break; 
		}
		curentline = ft_strjoin(curentline, buff); // have to free
	}
	begin_of_new_line = begin_of_new_line + 1;
	 return (curentline);
}

int main(void)
{

    int fd;
	char *p;
    fd = open("text.txt", O_RDONLY);
    p = get_next_line(fd);
	printf("%s", p);
}
