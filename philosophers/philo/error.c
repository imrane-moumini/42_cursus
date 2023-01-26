/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:57:34 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/26 23:16:54 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_first_error(int argc, char *argv[])
{
	int	tmp;

	tmp = argc;
	if (argc < 5 || argc > 5)
	{
		printf("wrong nummber of arguments\n");
		return (0);
	}
	if (check_negative(argc, argv) == 0)
		return (0);
	if (ft_atoi_parsing(argv[1]) <= 0)
	{
		printf("parsing error\n");
		return (0);
	}
	while (tmp > 1)
	{
		tmp--;
		if (check_only_number(argv[tmp]) == 0)
		{
			printf("parsing error\n");
			return (0);
		}
	}
	return (1);
}

int	handle_second_error(int argc, char *argv[])
{
	int	i;

	i = 0;
	if(handle_first_error(argc, argv) == 0)
		return (0);
	if (check_int_limit(argv) == 0)
		return (0);
	while (i + 1 < argc)
	{
		if (count_nbr_of_car(ft_atoi_long_parsing(argv[i + 1])) == 1)
		{
			printf("parsing error\n");
			return (0);
		}
		i++;
	}
	if (ft_atoi_parsing(argv[1]) == 1)
	{
		printf("0 1 has taken a fork\n");
		printf("0 1 died\n");
		return (0);
	}
	return (1);
}

int	check_negative(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i + 1 < argc)
	{
		if (ft_atoi_parsing(argv[i + 1]) < 0)
		{
			printf("parsing error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

long	ft_atoi_long_parsing(char *str)
{
	long	i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == '0')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = (sign * -1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (sign * nb);
}

int	count_nbr_of_car(long nb)
{
	int	i;

	i = 1;
	if (nb < 0)
		return (1);
	while (nb > 10)
	{
		nb = nb / 10;
		i++;
	}
	if (i > 10)
		return (1);
	return (0);
}
