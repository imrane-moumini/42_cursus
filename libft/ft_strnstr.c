/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 19:33:57 by imoumini          #+#    #+#             */
/*   Updated: 2022/05/22 22:56:46 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenght;
	size_t	save;

	i = 0;
	j = 0;
	lenght = ft_strlen(little);
	if (lenght == 0)
	{
		return ((char *)(big));
	}
	while (((big[i] != '\0') && (big[j] != '\0')) && (i < len))
	{
		j = 0;
		while ((big[i] == little[j]) && (i < len))
		{
			while ((big[i] == little[j]) && (i < len))
			{
				j++;
				save = i;
				if ((j == lenght)/* && (big[i] == little[j])*/)
				{
					j--;	
					save = save - j;
					return ((char *)(&(big[save])));
				}
				i++;
			}
			i--;
		}
		i++;

	}
	return (NULL);
}
/*int	main(void)
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	
	printf("mine is =>%s\n", ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
	printf("the real one is =>%s", strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));
}*/
