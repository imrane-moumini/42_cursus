/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:41:57 by imoumini          #+#    #+#             */
/*   Updated: 2022/06/27 22:42:00 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int printpointer(unsigned long long p)
{
	int	i;
	write(1, "0x", 2);
	ft_putnbr_hex_mini(p);
	i = count_hex_spe(p);
	return (i);
}
