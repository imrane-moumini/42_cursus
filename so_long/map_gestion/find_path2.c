/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:33:37 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/17 23:34:50 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

s_game ft_up(s_game flood, s_game game)
{
	s_game copy;
	
	copy = flood;
	
	copy.ps_y = game.ps_y - 1;
	copy.ps_x = game.ps_x;
	return(copy);
}

s_game ft_down(s_game flood, s_game game)
{
	s_game copy;
	
	copy = flood;
	
	copy.ps_y = game.ps_y + 1;
	copy.ps_x = game.ps_x;
	return(copy);
}

s_game ft_left(s_game flood, s_game game)
{
	s_game copy;
	
	copy = flood;
	
	copy.ps_y = game.ps_y;
	copy.ps_x = game.ps_x - 1;
	return(copy);
}

s_game ft_right(s_game flood, s_game game)
{
	s_game copy;
	
	copy = flood;
	
	copy.ps_y = game.ps_y;
	copy.ps_x = game.ps_x + 1;
	return(copy);
}



int is_path_valid(char **t, s_game g)
{
	static int count_c;
	s_game flood;
	
	flood = initialize_flood_and_position_and_count(t,g, &count_c);
	if (g.ps_y - 1 >= 0 && t[g.ps_y - 1][g.ps_x] != '1' && t[g.ps_y - 1][g.ps_x] != 'E' )
	{
		flood = ft_up(flood, g);
		is_path_valid(t, flood);
	}
	if (g.ps_y + 1 < g.tab_nbligne && t[g.ps_y + 1][g.ps_x] != '1' && t[g.ps_y + 1][g.ps_x] != 'E')
	{
		flood = ft_down(flood, g);
		is_path_valid(t, flood);
	}
	if (g.ps_x - 1 >= 0 && t[g.ps_y][g.ps_x - 1] != '1' && t[g.ps_y][g.ps_x - 1] != 'E')
	{
		flood = ft_left(flood, g);
		is_path_valid(t, flood);
	}
	if (g.ps_x + 1 < g.tab_nbcolumn && t[g.ps_y][g.ps_x + 1] != '1' && t[g.ps_y][g.ps_x + 1] != 'E')
	{
		flood = ft_right(flood, g);
		is_path_valid(t, flood);
	}
	return (count_c);
}