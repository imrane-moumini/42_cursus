


#include "../so_long.h"

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

	i = 0;
	j = 0;
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
					e = 1;
				if (tab[i][j] == 'P')
					p = 1;
				j++;	
			}
			j = 0;
			i++;
	}
	if (zero == 0 || one == 0 || c == 0 || e == 0 || p == 0)
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