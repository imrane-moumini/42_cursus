/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:28:58 by imoumini          #+#    #+#             */
/*   Updated: 2022/07/10 16:29:04 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		lenght_of_s1;
	int		lenght_of_s2;
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	lenght_of_s1 = ft_strlen(s1);
	lenght_of_s2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * lenght_of_s1 + lenght_of_s2 + 1);
	if (p == NULL)
		return (NULL);
	while (i < lenght_of_s1)
	{
		p[i] = s1[i];
		i++;
	}
	while (j < lenght_of_s2)
	{
		p[i++] = s2[j++];
	}
	p[i] = '\0';
	free(s1);
	return (p);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	i;

	if (nmemb && ((nmemb * size / nmemb) != size))
		return (NULL);
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	i = 0;
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)p)[i] = '\0';
		i++;
	}
	return (p);
}


