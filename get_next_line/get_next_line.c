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
	if (str == NULL)
		return (0);
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

void put_extra_in_buff(char *savetext,char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(savetext[i] != '\0')
	{
		while((savetext[i] != '\n') && (savetext[i] != '\0'))
		{
			i++;
		}
		if(savetext[i] == '\n')
		{
			i++;
			while (savetext[i] != '\0')
			{
				buff[j] = savetext[i];
				j++;
				i++;
			}
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
		while((buff[i] != '\n') && (buff[i] != '\0'))
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

void	line_to_return(char *buff)
{
	int		i;

	i = 0;
	while(buff[i] != '\0')
	{
		while((buff[i] != '\n') && (buff[i] != '\0'))
		{
			buff[i] = '\0';
			i++;
		}
		i++;
	}
}

int	is_empty(char *buff)
{
	int	i;

	i = 0;
	if (buff == NULL)
		return (1);
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

	lenght = ft_strlen(src);
	dest = ft_calloc((lenght + 1), (sizeof(char)));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
void	ft_free_str(char **str)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}
void erase_buff(char * buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		buff[i] = '\0';
		i++;
	}
}
char	*get_next_line(int fd)
{  
	static char	buff[BUFFER_SIZE + 1];
	char	*savetext;
	int		nbr_of_bytes_read;

	savetext = NULL;
	if (is_empty(buff) == 0)
	{
		savetext = ft_strjoin(savetext, buff);
	}
	if	(fd == -1)
		return (NULL);
	if (BUFFER_SIZE == 0)
		return (NULL);
    while (is_end_of_line(buff) != 1)
    {
		nbr_of_bytes_read = read(fd, buff, BUFFER_SIZE);
		if (nbr_of_bytes_read == 0)
		{	
			if (is_empty(buff) == 1)
				return (NULL);
			if (is_empty(buff) == 0)
				erase_buff(buff);
			return(savetext);
		}
		if (nbr_of_bytes_read == -1)
		{
			return (NULL);
		}
		savetext = ft_strjoin(savetext, buff); // have to free
	}
	// vider buff
	erase_buff(buff);
	// prendre la partie de save text apres le \n et le mettre dans buff
	put_extra_in_buff(savetext, buff);
	// mettre des \0 apres le \n
	line_to_return(savetext); // have to free
	return (savetext);
}
// enfqit c4est savetext que je ne free jamais
int main(void)
{
    int fd;
	char *p;
	char c = 'c';
    fd = open("text.txt", O_RDONLY);
	p = &c;
	while (p != NULL)
    {
		p = get_next_line(fd);
		if (p != NULL)
		{
			printf("%s", p);
		}
		free(p);
	}
	close(fd);
}

// si j'affiche pas tout le text je dois free
// si tout le text a fini dêtre affiché je dois free
// utiliser valgrind pour savoir