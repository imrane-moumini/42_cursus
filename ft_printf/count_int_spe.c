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

	power = 0;
	if (n < 0)
	{
		n = n * -1;
	}
	if (n < 10)
	{
		return (1);
	}
	while (n > 9)
	{
		n = n / 10;
		power++;
	}
	return (power + 1);
}