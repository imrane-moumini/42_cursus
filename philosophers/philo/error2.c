/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 22:25:51 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/26 22:35:12 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_only_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] != '-' && str[i] != '+' && str[i] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_int_limit(char **argv)
{
	long	content;
	int		i;

	i = 1;
	while (argv[i])
	{
		content = ft_atoi_long_parsing(argv[i]);
		if (content < -2147483648 || content > 2147483647)
		{
			printf("parsing error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_atoi_parsing(const char *nptr)
{
	int	nbr;
	int	i;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	if (!nptr)
		return (0);
	while (((nptr[i] >= 9) && (nptr[i] <= 13)) || (nptr[i] == 32) \
		|| (nptr[i] == '0'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while ((nptr[i] >= 48) && (nptr[i] <= 57))
	{
		nbr = ft_nbr(nptr[i]) + (nbr * 10);
		i++;
	}
	return (nbr * sign);
}
