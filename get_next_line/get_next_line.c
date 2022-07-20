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

void	cut_until_end_of_line(char	*buff)
{
	int	i;

	i = 0;
	while(buff[i] != '\0')
	{
		while(buff[i] != '\n')
		{
			buff[i] = '\0';
			i++;
		}
		if(buff[i] == '\n')
		{
			break;
		}
		i++;
	}
}

int	count_lenght_of_line_to_return(char *buff)
{
	int	i;

	i = 0;
	while(buff[i] != '\0')
	{
		while(buff[i] != '\n')
		{
			i++;
		}
		if(buff[i] == '\n')
		{
			break;
		}
		i++;
	}
	return (i);
}

char	*line_to_return(int nbr, char *buff)
{
	int		i;
	char	*p;

	p = malloc((sizeof(char) * nbr) + 2);

	i = 0;
	while(buff[i] != '\0')
	{
		while(buff[i] != '\n')
		{
			p[i] = buff[i];
			i++;
		}
		if(buff[i] == '\n')
		{
			p[i] = buff[i];
			i++;
			break;
		}
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	is_buff_empty(char *buff)
{
	int	i;

	i = 0;
	if (buff[i] == '\0')
	{
		return (1);
	}
	return (0);
}
char	*ft_strcpy(char *src)
{
	int	i;
	char	*dest;
	int		lenght;

	lenght = ft_strlen(dest);
	dest = malloc((sizeof(char) * lenght) + 1);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char	*get_next_line(int fd)
{  
	static char	*buff;
	static char	*curentline;
	int		nbr_of_bytes_read;
	static int		nbr_of_call;
	int		nbr_char_to_return;
	char	*begining_of_next_line;

	nbr_of_call++;
	if (BUFFER_SIZE == 0)
		return (NULL);
	if (nbr_of_call > 1)
	{
		printf("%i\n",is_end_of_line(buff));
		printf("buff in next call is %s", buff);
		// pk ya un saut de ligne alors que dan bo normalement ya pas puisque apres c b
		if((is_buff_empty(buff)) == 0 && (is_end_of_line(buff) == 1))
		{
			nbr_char_to_return = count_lenght_of_line_to_return(buff);
			curentline = line_to_return(nbr_char_to_return, buff);
			cut_until_end_of_line(buff);
			return(curentline);
		}
	}
	if (nbr_of_call == 1)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1); //have to free
		curentline = malloc(sizeof(char) * BUFFER_SIZE + 1);
	}
	if (buff == NULL)
		return (NULL);
		// en gros la le pb c quand ce qui depasse ne contient pas de \n 
		// parce que du coup la faut rapeler et joindre avec le debut de la nouvel ligne
	printf("nbr of call is %i\n",nbr_of_call);
	if (nbr_of_call > 1)
	{
		printf("im here\n");
		begining_of_next_line = ft_strcpy(buff);
	}
	//printf("beging of nextline is =>%s\n",begining_of_next_line);
    while (is_end_of_line(buff) != 1)
    {
			nbr_of_bytes_read = read(fd, buff, BUFFER_SIZE);
			// faut que je joigne ce qui depasse avec le nouvel appel

			// jappel read et le buff je le joigne avec le debut puis c ca que je met dans curentline 
		if (nbr_of_bytes_read == 0)
		{
			break;
		}
		if (nbr_of_bytes_read == -1)
		{
			return (NULL);
		}
		if (nbr_of_call > 1)
			curentline = begining_of_next_line;
		curentline = ft_strjoin(curentline, buff); // have to free
	}
	//printf("curentline after loop is =>%s", curentline);
	nbr_char_to_return = count_lenght_of_line_to_return(curentline);
	//printf("nbr of char to return is %i\n", nbr_char_to_return);
	curentline = line_to_return(nbr_char_to_return, curentline);
	//printf("curentline after line to return is =>%s", curentline);
	cut_until_end_of_line(buff);
	return (curentline);
}

int main(void)
{
    int fd;
	char *p;
	int i = 0;
    fd = open("text.txt", O_RDONLY);

	while (i <= 5)
    {
		p = get_next_line(fd);
		printf("%s", p);
		i++;
	}
}
