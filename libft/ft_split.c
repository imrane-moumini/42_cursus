/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:28:54 by imoumini          #+#    #+#             */
/*   Updated: 2022/05/27 19:28:58 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int	number_of_tab(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (s[i] != '\0'))
		{
			count++;
			i++;
		}
		while ((s[i] != c) && (s[i] != '\0'))
			i++;
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
	}
	return (count);
}

void	fill_tab(char const *s, char c, char **p, int l)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c) && (i <= l - 1))
			i++;
		while ((s[i] != c) && (i <= l - 1))
			p[j][k++] = s[i++];
		if (i <= l - 1)
			p[j][k] = '\0';
		if (i <= l - 1)
		{
			k = 0;
			j++;
			i++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		j;
	int		count;
	char	**p;

	i = 0;
	j = 0;
	count = 0;
	p = (char **)ft_calloc(sizeof(char *), (number_of_tab(s, c) + 1));
	if (number_of_tab(s, c) == 0)
		return (p);
	while (i <= (ft_strlen(s) - 1))
	{
		while ((s[i] == c) && (s[i]))
			i++;
		while ((s[i] != c) && (s[i++]))
			count++;
		if (count != 0)
			p[j++] = ft_calloc((char) sizeof(char), (count + 1));
		count = 0;
		i++;
	}
	fill_tab(s, c, p, ft_strlen(s));
	return (p);
}

// int        main(void)
// {
//     char    **tabstr;
//     // int        i;
//     tabstr = ft_split("  tripouille  42  ", ' ');

//     // i = 0;
//     if (tabstr[2] == NULL)
//         printf("NULL\n");
// }
// 	return 0;
	//  (!(tabstr = ft_split("  tripouille  42  ", ' ')))
	// 	printf("NULL");
	// else
	// {
	// 	while (tabstr[i] != NULL)
	// 	{
	// 		printf("%s\n", tabstr[i]);
	// 		//write(1, "\n", 1);
	// 		i++;
	// 	}
	// }
// }
