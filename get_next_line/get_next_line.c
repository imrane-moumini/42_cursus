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

char	*cut_until_end_of_line(char	*buff, int index)
{
	// je vais copier enfait a partir de l'adresse où ya plus le \n
	int	i;
	char	*p;
	//printf("index is => %i\n",index);
	i = index;
	p = ft_strcpy(&buff[i]);
	return (p);
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

char	*line_to_return(int nbr, char *buff)
{
	int		i;
	char	*p;

	p = malloc((sizeof(char) * nbr) + 2);
	if (p == NULL)
		return (NULL);
	i = 0;
	while(buff[i] != '\0')
	{
		while((buff[i] != '\n') && (buff[i] != '\0'))
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
	//printf("lenght of new truc a save is =>%i", lenght);
	dest = ft_calloc((lenght + 1), (sizeof(char)));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		//printf("dest de i =>%c", dest[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{  
	static char	*buff;
	static char	*savetext;
	char		*curentline;
	int		nbr_of_bytes_read;
	static int		nbr_of_call;
	int		nbr_char_to_return;
	char	*begining_of_next_line;
	int		lenght_of_curentline;
	int		lenght_of_savetext_before_cut;

	nbr_of_call++;
	
	if	(fd == -1)
		return (NULL);
	if (BUFFER_SIZE == 0)
		return (NULL);
	if (!savetext)
	{
		// je crois que savetext c ega a '\0' comme c satic du coup c initalise dans tous les cas
		// du coup on ne rentre pas dedans
		// du coup buff ya jamais malloc (mais normalent si ya pas malloc bah ca fait segfault)
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char)); //have to free
		savetext = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (buff == NULL)
			return (NULL);
		if (savetext == NULL)
			return (NULL);
	}
    while (is_end_of_line(savetext) != 1)
    {
		nbr_of_bytes_read = read(fd, buff, BUFFER_SIZE);
		if (nbr_of_bytes_read == 0)
		{
			break;
		}
		if (nbr_of_bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		savetext = ft_strjoin(savetext, buff); // have to free
	}
	nbr_char_to_return = count_lenght_of_line_to_return(savetext);
	lenght_of_savetext_before_cut = ft_strlen(savetext);
	// copier save text dans un static char puis free
	// creer une fonction qui free et retourne la static char dans save mais on aura deja free avant
	curentline = line_to_return(nbr_char_to_return, savetext); // have to free
	// copier curentline dans un static char puis free 
	// creer une fonction qui free et retourne la static char dans curentline mais on aura deja free avant
	lenght_of_curentline = ft_strlen(curentline);
	savetext = cut_until_end_of_line(savetext, lenght_of_curentline); // have to free
	// copier savetext dans un static char puis free 
	// creer une fonction qui free et retourne la static char dans savetext mais on aura deja free avant

	// free savetext si jamais en fait on appel pas jusquq lq fin du text la fonction
	// free tous les malloc quand on a plus besoin du truc
	// normalement je dois free tous les malloc ac
	return (curentline);
}

int main(void)
{
    int fd;
	char *p;
	int i = 0;
    fd = open("text.txt", O_RDONLY);

	while (i <= 17)
    {
		p = get_next_line(fd);
		printf("%s", p);
		i++;
	}
}

// si j'affiche pas tout le text je dois free
// si tout le text a fini dêtre affiché je dois free
// utiliser valgrind pour savoir