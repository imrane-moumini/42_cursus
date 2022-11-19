/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:33:37 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/19 17:50:52 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game	ft_up(t_game flood, t_game game)
{
	t_game	copy;

	copy = flood;
	copy.y = game.y - 1;
	copy.x = game.x;
	return (copy);
}

t_game	ft_down(t_game flood, t_game game)
{
	t_game	copy;

	copy = flood;
	copy.y = game.y + 1;
	copy.x = game.x;
	return (copy);
}

t_game	ft_left(t_game flood, t_game game)
{
	t_game	copy;

	copy = flood;
	copy.y = game.y;
	copy.x = game.x - 1;
	return (copy);
}

t_game	ft_right(t_game flood, t_game game)
{
	t_game	copy;

	copy = flood;
	copy.y = game.y;
	copy.x = game.x + 1;
	return (copy);
}

t_game	is_path_valid(char **t, t_game g)
{
	static t_game	result;
	t_game			flood;

	flood = initialize_flood_position_count(t, g, &result);
	if (g.y - 1 >= 0 && t[g.y - 1][g.x] != '1' && t[g.y - 1][g.x] != 'E')
	{
		flood = ft_up(flood, g);
		is_path_valid(t, flood);
	}
	if (g.y + 1 < g.ligne && t[g.y + 1][g.x] != '1' && t[g.y + 1][g.x] != 'E')
	{
		flood = ft_down(flood, g);
		is_path_valid(t, flood);
	}
	if (g.x - 1 >= 0 && t[g.y][g.x - 1] != '1' && t[g.y][g.x - 1] != 'E')
	{
		flood = ft_left(flood, g);
		is_path_valid(t, flood);
	}
	if (g.x + 1 < g.column && t[g.y][g.x + 1] != '1' && t[g.y][g.x + 1] != 'E')
	{
		flood = ft_right(flood, g);
		is_path_valid(t, flood);
	}
	return (result);
}
