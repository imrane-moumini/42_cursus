

#include "../so_long.h"

int is_path_valid(char **tab, s_game game)
{
	static int count_c;
	static int result;
	s_game flood;
	
	flood.tab_number_of_ligne = game.tab_number_of_ligne;
	flood.tab_number_of_column = game.tab_number_of_column;
	flood.number_of_c = game.number_of_c;
	if (tab[game.position_y][game.position_x] == 'C')
		count_c++;
	if (tab[game.position_y][game.position_x] == 'E')
			result = 1;
	tab[game.position_y][game.position_x] = '1';
	if (game.position_y - 1 >= 0 && tab[game.position_y - 1][game.position_x] != '1')
	{
		flood.position_y = game.position_y - 1;
		flood.position_x = game.position_x;
		is_path_valid(tab, flood);
	}
	if (game.position_y + 1 < game.tab_number_of_ligne && tab[game.position_y + 1][game.position_x] != '1')
	{
		flood.position_y = game.position_y + 1;
		flood.position_x = game.position_x;
		is_path_valid(tab, flood);
	}
	if (game.position_x - 1 >= 0 && tab[game.position_y][game.position_x - 1] != '1')
	{
		flood.position_y = game.position_y;
		flood.position_x = game.position_x - 1;
		is_path_valid(tab, flood);
	}
	if (game.position_x + 1 < game.tab_number_of_column && tab[game.position_y][game.position_x + 1] != '1')
	{
		flood.position_y = game.position_y;
		flood.position_x = game.position_x + 1;
		is_path_valid(tab, flood);
	}
	if (result == 1 && count_c == game.number_of_c)
		return(1);
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