/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countpointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:23:49 by imoumini          #+#    #+#             */
/*   Updated: 2022/06/30 23:23:52 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>


int	countpointer(unsigned long long int n)
{
	int	power;
	unsigned long  long int	nbr;
	//printf("\nn is %lld\n", n);
	power = 0;
	nbr = n;
	// if (n < 0)
	// {
	// 	nbr = nbr * -1;
	// 	power++;
	// }
	if ((n < 16) && (n > 0))
	{
		return (1);
	}
	//printf("%u\n",n);
	while (nbr >= 16)
	{
		//printf("\nim here\n");
		nbr = nbr / 16;
		power++;
		//printf("\npower after division is %d\n", power);
	}
	return (power + 1);
}
