/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_int_spe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:34:17 by imoumini          #+#    #+#             */
/*   Updated: 2022/06/27 22:34:20 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int	count_int_spe(long long n)
{
	int	power;
	long long	nbr;

	nbr = n;
	power = 0;
	//printf("\n n %lld is \n", n);
	if (n < 0)
	{
		nbr = nbr * -1;
		power++;
	}
	if ((n < 10) && (n > 0))
	{
		return (1);
	}
	while (nbr > 9)
	{
		//printf("im here");
		nbr = nbr / 10;
		power++;
	}
	//printf("\npower is %d\n", power);
	return (power + 1);
}

// int	main(void)
// {
// 	int h;
// 	h = count_int_spe(4294967287);
// 	printf("%d", h);
// }