/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:23:40 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/28 17:23:04 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	nb_column(char **tab)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (tab[i][j] != '\0')
	{
		if (tab[i][j] == '\n')
			return (counter);
		counter++;
		j++;
	}
	return (counter);
}

int	nb_ligne(char *file)
{
	char	*p;
	int		fd;
	int		counter;

	counter = 0;
	fd = open(file, O_RDONLY);
	p = get_next_line(fd);
	if (p == NULL)
	{
		free(p);
		return (0);
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

t_coor *new_node()
{
	t_coor *ptr;
	ptr = malloc(sizeof(t_coor));
	if (!ptr)
		return (NULL);
	ptr -> next = NULL;
	return (ptr);
}
void add_node(t_coor *head, t_coor *node)
{
	t_coor *ptr;
	if (!head)
		return ;
	ptr = head;
	while (ptr -> next)
	{
		ptr = ptr -> next;
	}
	ptr -> next = node;
}
t_coor *last_node(t_coor *head)
{
	t_coor *ptr;

	if (!head)
		return (NULL);
	ptr = head;
	while (ptr -> next)
	{
		ptr = ptr -> next;
	}
	return (ptr);
	
}

void save_wall(t_game *g)
{
	int i;
	int j;
	t_coor *ptr;
	
	i = 0;
	j = 0;
	g->node = new_node();
	ptr = g->node;
	while (g->tab[i])
	{
		j = 0;
		while (g->tab[i][j])
		{
			if (g->tab[i][j] == '1')
			{
				if (!(g->node))
				{
					printf("im here\n");
					// le premier x et y c 64 * i et 64 *j
					// le dermier x et y c 64 * (i + 1) et 64 * (j + 1) 
					ptr ->first_y = i * 64;
					ptr ->first_x = j * 64;
					ptr ->last_y = (i + 1) * 64;
					ptr ->last_x = (j + 1) * 64;
					// ok ca normalement c 1 carrer mais jincrement pas bien le x a chauqe carrer
					// printf("first x : %i, first y : %i\n", ptr ->first_x, ptr ->first_y);
					// printf("last x : %i, last y : %i\n", ptr ->last_x, ptr ->last_y);
					// printf("----------------------------------\n");
				}
				else
				{
					add_node(g->node, new_node());
					ptr = last_node(g->node);
					ptr ->first_y = i * 64;
					ptr ->first_x = j * 64;
					ptr ->last_y = (i + 1) * 64;
					ptr ->last_x = (j + 1) * 64;
					// printf("first x : %i, first y : %i\n", ptr ->first_x, ptr ->first_y);
					// printf("last x : %i, last y : %i\n", ptr ->last_x, ptr ->last_y);
					// printf("----------------------------------\n");
				}
				
			}
			j++;
		}
		i++;
	}
}

// ok g les bonnes coordonner de carrer
// ptete in wall j'ai pas la bonne logique genre jsuis pas dans un mur
//  une histoire dinversement entre les x et y
// regarder par arrpor au graph et au valeur du printf, tu vas truver


int in_wall(int x, int y, t_game *g)
{
	t_coor *ptr;
	
	ptr = g->node;
	// je crois que le pb c aue je regarde que pour la derniere node
	while (ptr)
	{
		//if (ptr -> first_x == 128)
		// {
			// printf("------------------- in wall ---------------------------------------------------\n");
			// printf("x is : %i, y is %i\n", x, y);
			// printf("first_x is : %i, first y is %i\n", ptr -> first_x , ptr -> first_y );
			// printf("last_x is : %i, last y is %i\n", ptr -> last_x , ptr -> last_y );
		//}
		if ((x >= ptr -> first_x && x <= ptr -> last_x) && (y >= ptr -> first_y && y <= ptr -> last_y))
			return (1);
		ptr = ptr -> next;
	}
	return (0);
}
