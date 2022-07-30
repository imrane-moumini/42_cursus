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
		if (buff[j] != '\0')
		{
			i++;
		}
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
		if((buff[i] == '\n')) 
		{
			i++;
			while(buff[i] != '\0')
			{
				buff[i] = '\0';
				i++;
			}
		}
		if (buff[i] != '\0')
		{
			i++;
		}
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
	static	int	nbr_of_call;

	nbr_of_call++;
	// printf("----------------------------------------\n");
	// printf("number of call is %i\n", nbr_of_call);
	// printf("buff before while is     =>%s||\n", buff);
	savetext = NULL;
	// printf("savetext before while is =>%s||\n", savetext);
	if (is_empty(buff) == 0)
	{
		savetext = ft_strjoin(savetext, buff);
		// printf("savetext before while after join is =>%s||\n", savetext);
	}
	if	(fd == -1)
		return (NULL);
	if (BUFFER_SIZE == 0)
		return (NULL);
	// printf("------------------------------------------------------\n");
    while (is_end_of_line(buff) != 1)
    {
		// printf("i am in while \n");
		nbr_of_bytes_read = read(fd, buff, BUFFER_SIZE);
		buff[nbr_of_bytes_read] = '\0';
		// printf("buff after read is =>%s||\n", buff);
		// printf("nbr of bytes read is =>%i\n", nbr_of_bytes_read);
		if (nbr_of_bytes_read == 0)
		{	
			// printf("i am in nbr of read bytes is 0\n");
			// if (is_empty(buff) == 1)
			// {
			// 	printf("i am in the case where buff is empty\n");
			// 	return (NULL);
			// }
			// if (is_empty(buff) == 0)
			// 	erase_buff(buff);
			// printf("savetext to return if nbr of bytes reqd is 0 is =>%s||\n", savetext);
			return(savetext);
		}
		if (nbr_of_bytes_read == -1)
		{
			return (NULL);
		}
		savetext = ft_strjoin(savetext, buff); // have to free
		// printf("savetext in while is =>%s||\n", savetext);
	}
	// printf("-----------------------------------------------------------\n");
	// printf("buff after while is     =>%s||\n", buff);
	// printf("savetext after while is =>%s||\n", savetext);
	erase_buff(buff);
	// printf("buff after erase is     =>%s||\n", buff);
	put_extra_in_buff(savetext, buff);
	// printf("buff after put extra is =>%s||\n", buff);
	line_to_return(savetext); // have to free
	// printf("savetext to return is   =>%s||\n", savetext);
	return (savetext);
}

// int main(void)
// {
//     int fd;
// 	char *p;
// 	char c = 'c';
//     fd = open("text.txt", O_RDONLY);
// 	p = &c;
// 	while (p != NULL)
//     {
// 		p = get_next_line(fd);
// 		if (p != NULL)
// 		{
// 			printf("%s", p);
// 		}
// 		free(p);
// 	}
// 	close(fd);
// }

