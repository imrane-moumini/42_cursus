/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 21:59:01 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/26 13:56:57 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_dot(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

void	ft_free_mlx_error(void *ptr)
{
	free(ptr);
	exit(1);
}

void	ft_test(t_game game, char **tab)
{
	int	i;

	i = 0;
	ft_printf("the real one is :\n");
	while (game.tab[i] != NULL)
	{
		ft_printf("%s\n", game.tab[i]);
		i++;
	}
	ft_printf("------------------------------\n");
	ft_printf("the copy is :\n");
	i = 0;
	while (tab[i] != NULL)
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}
