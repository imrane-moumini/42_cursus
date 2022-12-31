/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 19:10:13 by imoumini          #+#    #+#             */
/*   Updated: 2022/12/31 20:34:42 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_int_limit(char **argv)
{
	long	content;
	int		i;

	i = 1;
	while (argv[i])
	{
		content = ft_atoi_long(argv[i]);
		if (content < -2147483648 || content > 2147483647)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
