/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 22:30:44 by imoumini          #+#    #+#             */
/*   Updated: 2022/05/22 22:54:47 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_nbr(char c)
{
	int	nbr;

	nbr = c - 48;
	return (nbr);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	i;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (((nptr[i] >= 9) && (nptr[i] <= 13)) || (nptr[i] == 32))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign = sign * -1;
		}
		i++;
	}
	while ((nptr[i] >= 48) && (nptr[i] <= 57))
	{
		nbr = ft_nbr(nptr[i]) + (nbr * 10);
		i++;
	}
	return (nbr * sign);
}
/*int	main(void)
{
	printf("mine is =>%d\n", ft_atoi("\t\n\r\v\f  469 \n"));
	printf("the real one is =>%d", atoi("\t\n\r\v\f  469 \n"));
}*/
