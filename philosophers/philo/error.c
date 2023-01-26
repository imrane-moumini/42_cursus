/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:57:34 by imoumini          #+#    #+#             */
/*   Updated: 2023/01/26 16:50:15 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_error(int argc, char *argv[])
{
	if (ft_atoi(argv[1]) == 1)
	{
		printf("0 1 has taken a fork\n");
		printf("0 1 died\n");
		return (0);
	}
	if (argc < 5)
	{
		printf("wrong nummber of arguments\n");
		return (0);
	}
	if (ft_atoi(argv[1]) == 0)
	{
		printf("parsing error\n");
		return (0);
	}
	return (1);
}
