/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:13:40 by imoumini          #+#    #+#             */
/*   Updated: 2022/06/04 18:13:43 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>


int	count_int(long long n)
{
	int	power;
	power = 0;

	if (n < 10)
	{
		return (1);
	}
	while (n > 9)
	{
		n = n/10;
		power++;
	}
	return (power + 1);
}
// regarder pk min int quqnd on multiplie par -1 ca fait pas la valeur positive
char	*ft_itoa(int n)
{		
	char		*p;
	int			i;
	long long 	nbr;
	int			lenght;
	char		c;

	i = 0;
	if (n < 0)
		nbr = n * -1;
	else
		nbr = n;
	lenght = count_int(nbr);
	if (n < 0)
		lenght  = lenght + 1;
	p = malloc(sizeof(char) * (lenght + 1));
	p[lenght] = '\0';
	while (i < lenght)
	{
		c = (nbr % 10) + '0';
		p[lenght - 1] =  c;
		nbr = nbr / 10;
		lenght--;
	}
	if (n < 0)
		p[0] = '-';
	return (p);
}

int	main(void)
{
	printf("%s", ft_itoa(-2147483648));
}