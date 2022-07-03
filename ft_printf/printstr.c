/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:43:08 by imoumini          #+#    #+#             */
/*   Updated: 2022/06/27 22:43:10 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int	printstr(char *str)
{
	int	len;

	len = ft_putstr_spe_fd(str, 1);
	return (len);
}
