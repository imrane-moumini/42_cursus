/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:23:40 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/27 19:21:26 by imoumini         ###   ########.fr       */
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
		while (g->tab[i][j])
		{
			if (g->tab[i][j] == '1')
			{
				if (!(g->node -> next))
				{
					// le premier x et y c 64 * i et 64 *j
					// le dermier x et y c 64 * (i + 1) et 64 * (j + 1) 
					ptr ->first_x = i * 64;
					ptr ->first_y = j * 64;
					ptr ->last_x = (i + 1) * 64;
					ptr ->last_y = (j + 1) * 64;
				}
				else
				{
					add_node(g->node, new_node());
					ptr = last_node(g->node);
					ptr ->first_x = i * 64;
					ptr ->first_y = j * 64;
					ptr ->last_x = (i + 1) * 64;
					ptr ->last_y = (j + 1) * 64;
				}
				
			}
			j++;
		}
		i++;
	}
}
