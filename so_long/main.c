/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:41:37 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/23 20:15:25 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// check maps in main
void ft_free_map(t_game game, char **tab)
{
	int save;
	
	save = game.ligne;
	while (game.ligne  >= 0)
	{
		free(game.tab[game.ligne]);
		game.ligne--;
	}
	free(game.tab);
 	while (save  >= 0)
 	{
 		free(tab[save]);
 		save--;
 	}
 	free(tab);
}

int ft_result_false(t_game game, char** tab, t_game testvalidpath)
{
	if (game.testcar == 0 )
	{
		ft_printf("error false caracter\n");
		ft_free_map(game, tab);
		return (0);
	}
	if ( game.testrect == 0)
	{
		ft_printf("error map is not a rectangle\n");
		ft_free_map(game, tab);
		return (0);
	}
	if (game.testclose == 0  )
	{
		ft_printf("error map is not close\n");
		ft_free_map(game, tab);
		return (0);
	}
	if (testvalidpath.map_nb_of_c != game.nb_of_c || testvalidpath.is_an_exit != 1 )
	{
		ft_printf("error no valid path\n");
		ft_free_map(game, tab);
		return (0);
	}
	return (1);
	
}

void ft_test(t_game game, char **tab)
{
	int i;

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

t_game check_map_part(char *argv)
{
	t_game game;

	game.tab = NULL;
	game.tab = allocate_line(game.tab, argv);
	if (game.tab == NULL)
	{
		free(game.tab);	
		exit(1);
	}
	game.tab = allocate_column(game.tab, argv);
	if (game.tab == NULL)
	{
		free(game.tab);	
		exit(1);
	}
	game.tab = fill_tab(game.tab, argv);
	game.testcar = is_car_ok(game.tab);
	game.column = nb_column(game.tab);
	game.ligne = nb_ligne(argv);
	game.testrect = is_car_rect(game.tab, game.ligne, game.column);
	game.testclose = is_car_close(game.tab, game.ligne, game.column);
	return (game);
}
// lancer le jeux in main
void ft_free_mlx_error(void *ptr)
{
	free(ptr);
	exit(1);
}

int	handle_no_event(void *game)
{
	(void)game;
	return (0);
}
void move_w(t_game *game)
{
	find_start_position(game -> tab, game);
	if (game -> x - 1 >= 0 &&  game -> tab[game -> y][game -> x - 1] == 'E' && game -> nb_of_c == 0)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if(game -> x - 1 >= 0 && game -> tab[game -> y][game -> x - 1] == 'C')
	{
				game -> nb_of_c = game -> nb_of_c - 1;
				ft_printf("c : %i\n", game -> nb_of_c);
	}	
	if (game -> x - 1 >= 0 && game -> tab[game -> y][game -> x - 1] != '1' && game -> tab[game -> y][game -> x - 1] != 'E')
	{
		
		game -> tab[game -> y][game -> x -1 ] = 'P';
		game -> tab[game -> y][game -> x] = '0';
		game -> walk = game -> walk + 1;
		ft_printf("Tu as fait %i coups\n", game -> walk);
		ft_put_img_to_window(*game);	
	}
}
void move_a(t_game *game)
{
	find_start_position(game -> tab, game);
	if (game -> y - 1 >= 0 && game -> tab[game -> y - 1][game -> x] == 'E' && game -> nb_of_c == 0)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game -> y - 1 >= 0 && game -> tab[game -> y - 1][game -> x] == 'C')
	{
				game -> nb_of_c = game -> nb_of_c - 1;
				ft_printf("c : %i\n", game -> nb_of_c);
	}
	if (game -> y - 1 >= 0 && game -> tab[game -> y - 1][game -> x] != '1' && game -> tab[game -> y - 1][game -> x] != 'E')
	{
			game -> tab[game -> y - 1][game -> x] = 'P';
			game -> tab[game -> y][game -> x] = '0';
			game -> walk = game -> walk + 1;
			ft_printf("Tu as fait %i coups\n", game -> walk);
			ft_put_img_to_window(*game);	
	}
}
void move_s(t_game *game)
{
	find_start_position(game -> tab, game);
	if (game -> x + 1 < game -> column && game -> tab[game -> y][game -> x + 1] == 'E' && game -> nb_of_c == 0)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game -> x + 1 < game -> column  && game -> tab[game -> y][game -> x + 1] == 'C')
	{
				game -> nb_of_c = game -> nb_of_c - 1;
				ft_printf("c : %i\n", game -> nb_of_c);
	}
	if (game -> x + 1 < game -> column && game -> tab[game -> y][game -> x + 1] != '1' && game -> tab[game -> y][game -> x + 1] != 'E')
	{
		game -> tab[game -> y][game -> x + 1 ] = 'P';
		game -> tab[game -> y][game -> x] = '0';
		game -> walk = game -> walk + 1;
		ft_printf("Tu as fait %i coups\n", game -> walk);
		ft_put_img_to_window(*game);
	}
}
void move_d(t_game *game)
{
	find_start_position(game -> tab, game);
	if(game -> y + 1 < game -> ligne && game -> tab[game -> y + 1][game -> x] == 'E' && game -> nb_of_c == 0 )
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if(game -> y + 1 < game -> ligne && game -> tab[game -> y + 1][game -> x] == 'C')
	{
				game -> nb_of_c = game -> nb_of_c - 1;
				ft_printf("c : %i\n", game -> nb_of_c);
	}
	if(game -> y + 1 < game -> ligne && game -> tab[game -> y + 1][game -> x] != '1' && game -> tab[game -> y + 1][game -> x] != 'E')
	{
		game -> tab[game -> y + 1][game -> x] = 'P';
		game -> tab[game -> y][game -> x] = '0';
		game -> walk = game -> walk + 1;
		ft_printf("Tu as fait %i coups\n", game -> walk);
		ft_put_img_to_window(*game);	
	}
}

int	handle_input(int key, t_game *game)
{
	if (key == XK_Escape)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (key == XK_w)
		move_w(game);
	if (key == XK_a)
		move_a(game);
	if (key == XK_s)
		move_s(game);
	if (key == XK_d)
		move_d(game);
	return (0);
}

void ft_put_img_to_window(t_game game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (game.tab[i] != NULL )
	{
		while (game.tab[i][j] != '\0')
		{
			if (game.tab[i][j] == '1')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_tree, j * 64, i * 64);
			if (game.tab[i][j] == '0')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_grass, j * 64, i * 64);
			if (game.tab[i][j] == 'P')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_warrior, j * 64, i * 64);
			if (game.tab[i][j] == 'E')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_house, j * 64, i * 64);
			if (game.tab[i][j] == 'C')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img_mushroom, j * 64, i * 64);
			j++;
		}
		j = 0;
		i++;
	}
}
int	check_dot(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}
int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0') || (s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
int check_ber(char *str)
{
	char	*ber;
	int		i;
		
	i = 0;	
	ber = ".ber";
	if (check_dot(str) == 0)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			if (ft_strcmp(str+i, ber) != 0)
				return (0);
		}
		i++;
	}
	return (1);
	 	
}
int main(int argc, char *argv[])
{
	char **tab;
	t_game testvalidpath;
	t_game	game;
	
	if (argc != 2)
		return(1);
	if(check_ber(argv[1]) == 0)
		return (1);
	game = check_map_part(argv[1]);
	find_start_position(game.tab, &game);
	nbr_of_collectible(game.tab, &game);
	tab = tab_copy(game.tab, game.column, game.ligne);
	testvalidpath = is_path_valid(tab, game);
	if (ft_result_false(game, tab, testvalidpath) == 0)
		return(1);
	ft_test(game, tab);
	game.mlx_ptr = mlx_init();
	if (game.mlx_ptr == NULL)
		ft_free_mlx_error(game.mlx_ptr);
	game.win_ptr = mlx_new_window(game.mlx_ptr, 64 * game.column, 64 * game.ligne, "Medieval combat");
	if (game.win_ptr == NULL)
		ft_free_mlx_error(game.win_ptr);
	game.walk = 0;
	mlx_loop_hook(game.mlx_ptr, &handle_no_event, &game);
	mlx_hook(game.win_ptr,  KeyPress, KeyPressMask, &handle_input, &game);
	//mlx_key_hook(game.win_ptr, &handle_input, &game);
	
	game.img_grass = mlx_xpm_file_to_image(game.mlx_ptr, "./image/Grass_Flat.xpm", &game.img_width, &game.img_height);
	game.img_house = mlx_xpm_file_to_image(game.mlx_ptr, "./image/Knight_House.xpm", &game.img_width, &game.img_height);
	game.img_tree = mlx_xpm_file_to_image(game.mlx_ptr, "./image/Tree.xpm", &game.img_width, &game.img_height);
	game.img_warrior = mlx_xpm_file_to_image(game.mlx_ptr, "./image/Warrior.xpm", &game.img_width, &game.img_height);
	game.img_mushroom = mlx_xpm_file_to_image(game.mlx_ptr, "./image/Mushroom_01.xpm", &game.img_width, &game.img_height);
	ft_put_img_to_window(game);
	
	mlx_loop(game.mlx_ptr);
	mlx_destroy_image(game.mlx_ptr, game.img_house);
	mlx_destroy_image(game.mlx_ptr, game.img_grass);
	mlx_destroy_image(game.mlx_ptr, game.img_tree);
	mlx_destroy_image(game.mlx_ptr, game.img_warrior);
	mlx_destroy_image(game.mlx_ptr, game.img_mushroom);
	mlx_destroy_display(game.mlx_ptr);
	ft_free_map(game, tab);
	free(game.mlx_ptr);
}