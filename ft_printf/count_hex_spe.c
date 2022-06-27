/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_hex_spe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:35:00 by imoumini          #+#    #+#             */
/*   Updated: 2022/06/27 22:35:02 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>


int	count_hex_spe(long long n)
{
	int	power;
	//printf("\nn is %lld\n", n);
	power = 0;
	if (n < 0)
	{
		n = n * -1;
	}
	if (n < 16)
	{
		return (1);
	}
	while (n >= 16)
	{
		//printf("\nim here\n");
		n = n / 16;
		power++;
		//printf("\npower after division is %d\n", power);
	}
	return (power + 1);
}