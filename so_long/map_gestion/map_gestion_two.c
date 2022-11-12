
#include "../so_long.h"

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