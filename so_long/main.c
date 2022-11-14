/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:41:37 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/14 20:43:06 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **allocate_line(char **tab, char *file)
{
	char *p;
	int fd;
	int counter;

	counter = 0;

	fd = open(file,O_RDONLY);
	p = get_next_line(fd);
	if (p == NULL)
	{
		free(p);
		return(NULL);
	}
	while (p != NULL)
	{
		free(p);
		p = get_next_line(fd);
		counter++;
	}
	free(p);
	close(fd);
	tab = ft_calloc((counter + 1),sizeof(char *));
	if (tab == NULL)
		return(NULL);
	tab[counter] = NULL;
	return (tab);
}
char **allocate_column(char **tab, char *file)
{
	int counter;
	int i;
	int j;
	char *p;
	int fd;
	
	counter = 0;
	i = 0;
	j = 0;
	fd = open(file,O_RDONLY);
	p = get_next_line(fd);
	if (p == NULL)
	{
		free(p);
		return(NULL);
	}
	while (p != NULL)
	{
		while (p && p[i] != '\0')
		{
			while (p[i] != '\n' && p[i] != '\0')
			{
				counter++;
				i++;
			}
			if (p[i] == '\n' || p[i] == '\0')
			{
				tab[j] = ft_calloc(counter + 1, sizeof(char));
				if (tab[j] == NULL)
					return(NULL);
				counter = 0;
				j++;
				i = 0;
				free(p);
				p = get_next_line(fd);
			}
		}
	}
	free(p);
	close(fd);
	return (tab);
}
char **fill_tab(char **tab, char *file)
{
	int i;
	int j;
	int k;
	int fd;
	char *p;
	j = 0;
	i = 0;
	k = 0;
	
	fd = open(file,O_RDONLY);
	p = get_next_line(fd);
	if (p == NULL)
	{
		free(p);
		return(NULL);
	}
	while (p != NULL && tab[j] != NULL )
	{
		while (p[i] != '\0' && tab[j] != NULL )
		{
			while (p[i] != '\n' && p[i] != '\0' && tab[j] != NULL)
			{
				tab[j][k] = p[i];
				i++;
				k++;
			}
			k = 0;
			j++;
			if (p[i] != '\0')
				i++;
		}
		i = 0;
		free(p);
		p = get_next_line(fd);
	}
	free(p);
	close(fd);
	return (tab);
}

int is_car_ok(char **tab)
{
	int i;
	int j;
	int c = 0;
	int zero = 0;
	int one = 0;
	int e = 0;
	int p = 0;
	int count_p;
	int count_e;

	i = 0;
	j = 0;
	count_e = 0;
	count_p = 0;
	while (tab[i] != NULL)
	{
			while(tab[i][j] != '\0')
			{
				if (tab[i][j] != '0' && tab[i][j] != '1' && tab[i][j] != 'C' && tab[i][j] != 'E' && tab[i][j] != 'P'  )
					return (0);
				j++;	
			}
			j = 0;
			i++;
	}
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
			while(tab[i][j] != '\0')
			{
				if (tab[i][j] == '0')
					zero = 1;
				if (tab[i][j] == '1')
					one = 1;
				if (tab[i][j] == 'C')
					c = 1;
				if (tab[i][j] == 'E')
				{	e = 1;
					count_e++;
				}
				if (tab[i][j] == 'P')
				{
					p = 1;
					count_p++;
				}
				j++;	
			}
			j = 0;
			i++;
	}
	if (zero == 0 || one == 0 || c == 0 || e == 0 || p == 0)
		return (0);
	if (count_e > 1 || count_p > 1)
		return (0);
	return (1);
}

int is_car_close(char **tab, int number_of_ligne, int number_of_column)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (tab[1] != NULL)
	{
		while (tab[0][j] != '\0')
		{
			if (tab[0][j] != '1')
			{
				return 0;
			}
			j++;
		}	
	}
	j = 0;
	if (tab[number_of_ligne -1] != NULL)
	{
		while (tab[number_of_ligne -1][j] != '\0' )
		{
			if (tab[number_of_ligne -1][j] != '1')
			{
				return 0;
			}
			j++;
		}	
	}
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (j == 0)
			{
				if (tab[i][j] != '1')
				{
					return (0);
				}	
			}
			if (j == number_of_column - 1)
			{
				if (tab[i][j] != '1')
				{
						return (0);
				}	
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int is_car_rect(char **tab, int number_of_ligne, int number_of_column)
{
	int i;
	int j;
	

	i = 0;
	j = 0;
	if (number_of_column == number_of_ligne)
		return (0);
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			j++;
		}
		if (j != number_of_column)
		{
				return (0);
		}
		j = 0;
		i++;
	}
	if (i != number_of_ligne)
	{
			return (0);
	}
	return (1);	
}

int is_car_path_valid(char **tab)
{
	(void)tab;
	return (1);
}

int nb_column(char **tab)
{
	int i;
	int j;
	int counter;

	i = 0;
	j = 0;
	counter = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == '\0')
				return (counter);
			counter++;
			j++;
		}
		i++;	
	}
	return(counter);
}

int nb_ligne(char *file)
{
	char *p;
	int fd;
	int counter;

	counter = 0;

	fd = open(file,O_RDONLY);
	p = get_next_line(fd);
		if (p == NULL)
		{
			free(p);
			return(0);
		}
	while (p != NULL)
	{
		free(p);
		p = get_next_line(fd);
		counter++;
	}
	free(p);
	close(fd);
	return (counter);
}

void find_start_position(char **tab, s_game *game)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == 'P')
			{
				game -> position_x = j;
				game -> position_y = i;
				return;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void nbr_of_collectible(char **tab, s_game *game)
{
	int i;
	int j;
	int counter;
	
	counter = 0;
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			if (tab[i][j] == 'C')
			{
				counter++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	game -> number_of_c = counter;
}

int is_path_valid(char **tab, s_game game)
{
	static int count_c;
	//static int result;
	s_game flood;
	
	if (tab[game.position_y][game.position_x] == 'C')
		count_c++;
	// if (tab[game.position_y][game.position_x] == 'E')
	// 	result = 1;
	tab[game.position_y][game.position_x] = '1';
	if (game.position_y - 1 >= 0 && tab[game.position_y - 1][game.position_x] != '1' && tab[game.position_y - 1][game.position_x] != 'E' )
	{
		flood.position_y = game.position_y - 1;
		flood.position_x = game.position_x;
		flood.tab_number_of_ligne = game.tab_number_of_ligne;
		flood.tab_number_of_column = game.tab_number_of_column;
		flood.number_of_c = game.number_of_c;
		is_path_valid(tab, flood);
	}
	if (game.position_y + 1 < game.tab_number_of_ligne && tab[game.position_y + 1][game.position_x] != '1' && tab[game.position_y + 1][game.position_x] != 'E')
	{
		flood.position_y = game.position_y + 1;
		flood.position_x = game.position_x;
		flood.tab_number_of_ligne = game.tab_number_of_ligne;
		flood.tab_number_of_column = game.tab_number_of_column;
		flood.number_of_c = game.number_of_c;
		is_path_valid(tab, flood);
	}
	if (game.position_x - 1 >= 0 && tab[game.position_y][game.position_x - 1] != '1' && tab[game.position_y][game.position_x - 1] != 'E')
	{
		flood.position_y = game.position_y;
		flood.position_x = game.position_x - 1;
		flood.tab_number_of_ligne = game.tab_number_of_ligne;
		flood.tab_number_of_column = game.tab_number_of_column;
		flood.number_of_c = game.number_of_c;
		is_path_valid(tab, flood);
	}
	if (game.position_x + 1 < game.tab_number_of_column && tab[game.position_y][game.position_x + 1] != '1' && tab[game.position_y][game.position_x + 1] != 'E')
	{
		flood.position_y = game.position_y;
		flood.position_x = game.position_x + 1;
		flood.tab_number_of_ligne = game.tab_number_of_ligne;
		flood.tab_number_of_column = game.tab_number_of_column;
		flood.number_of_c = game.number_of_c;
		is_path_valid(tab, flood);
	}
	if (count_c == game.number_of_c)
	{
		// ft_printf("ft c : %i\n", count_c);
		// ft_printf("game c : %i\n", game.number_of_c);
		return(1);
	}
	else
		return (0);
}

char **tab_copy(char **tab, int number_of_column, int number_of_ligne)
{
	char **tab_copy;
	int i;
	int j;

	i = 0;
	j = 0;
	tab_copy = ft_calloc(number_of_ligne + 1,sizeof(char *));
	tab_copy[number_of_ligne] = NULL;
	while (i < number_of_ligne)
	{
		tab_copy[i] = ft_calloc(number_of_column + 1, sizeof(char)); 
		i++;
	}
	i = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][j] != '\0')
		{
			tab_copy[i][j] = tab[i][j];
			j++;
		}
		tab_copy[i][j] = '\0';
		j = 0;
		i++;
	}
	return (tab_copy);
}
int main(int argc, char *argv[])
{
	int i;
	int save;
	char **tab;
	int number_of_ligne;
	int number_of_column;
	int testcar;
	int testrect;
	int testclose;
	int testvalidpath;
	s_game	game;
	
	game.tab = NULL;
	i = 0;
	if (argc != 2)
		return(1);

	game.tab = allocate_line(game.tab, argv[1]);
	if (game.tab == NULL)
		return (1);
	game.tab = allocate_column(game.tab, argv[1]);
	if (game.tab == NULL)
		return (1);
	game.tab = fill_tab(game.tab, argv[1]);
	
	
	testcar = is_car_ok(game.tab);
	number_of_column = nb_column(game.tab);
	number_of_ligne = nb_ligne(argv[1]);
	game.tab_number_of_column = number_of_column;
	game.tab_number_of_ligne = number_of_ligne;
	testrect = is_car_rect(game.tab, number_of_ligne, number_of_column);
	testclose = is_car_close(game.tab, number_of_ligne, number_of_column);
	// trouver la position initiale du p
	find_start_position(game.tab, &game);
	nbr_of_collectible(game.tab, &game);
	tab = tab_copy(game.tab, number_of_column, number_of_ligne);
	testvalidpath = is_path_valid(tab, game);

	if (testcar == 0 || testrect == 0 || testclose == 0 || testvalidpath == 0)
	{
		ft_printf("Error\n");
		return (1);
	}
	
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
	// faire copy de tab
	// gere si e est direct a cote
		// remplace a chaque fois tout par 1 et a la fin tu peux plus avancer, tu regarde ce au'il reste et si il reste des C c que c cuit
		// tant que ya un c dans la map je remplace pas le E
			
	// free
	save = number_of_ligne;
	while (number_of_ligne  >= 0)
	{
		free(game.tab[number_of_ligne]);
		number_of_ligne--;
	}
	free(game.tab);

 	while (save  >= 0)
 	{
 		free(tab[save]);
 		save--;
 	}
 	free(tab);
}