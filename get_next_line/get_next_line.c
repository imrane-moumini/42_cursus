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
	static char	*nextline;
	int		nbr_of_bytes_read;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1); //have to free

    while (is_end_of_line(buff) != 1)
    {
		nbr_of_bytes_read = read(fd, buff, BUFFER_SIZE);
		if (nbr_of_bytes_read == 0)
		{
			break;
		}
		if (nbr_of_bytes_read == -1)
		{
			return (NULL);
		}
		if (is_end_of_line(buff) == 1)
		{
			// supprimer la partie de buff qui depasse
			cutbuff(buff);
			curentline = ft_strjoin(curentline, buff); // have to free
			break; 
		}
		curentline = ft_strjoin(curentline, buff); // have to free
	}
	// gerer la deuxieme ligne
		// il faut faire en sorte que a chaque fois que jqppel get next line
		// seulement la pochaine ligne est appelee
		// du coup a la prochaine iteration je reprebd a la ou ct arrete read
		// mais moi  jaffiche seulement la prochaine ligne
		// du coup faut que je me souvienne de la lettre apres le \n
		// je le strjoin avec les nouveaux eleemts de read si ya pas de \n dedans
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
