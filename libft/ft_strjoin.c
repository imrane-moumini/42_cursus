/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:41:17 by imoumini          #+#    #+#             */
/*   Updated: 2022/05/26 17:41:34 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (p);
}
/*int main(void)
{
    printf("%s", ft_strjoin("bob", "bob"));
}*/