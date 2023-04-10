/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env9.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:45:52 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/10 21:39:02 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"


void after_multiple_dollar_while(int nbr, int *i, int *save)
{
    		if (nbr % 2 == 0)
			{
				while (nbr)
				{
					*(i) = *(i) + 1;
					nbr--;
				}
				*(save) = *(i);
			}
			else
			{
				while (nbr > 1)
				{
					*(i) = *(i) + 1;
					nbr--;
				}
				*(save) = *(i);
			}
}
void init_str_nbr(char *str_nbr)
{
    str_nbr[0] = '3';
	str_nbr[1] = '1';
	str_nbr[2] = '0';
	str_nbr[3] = '5';
    str_nbr[4] = '1';
	str_nbr[5] = '6';
	str_nbr[6] = '0';
	str_nbr[7] = '\0';
}

int expand_guillemets(char *str, int index_dol)
{
	/* si ya pas de guillemets simple ouverte avant 
	+  ou si ya des guillemets simple ouverte mais avant des doubles
	ou si ls guilleemts simple avant sont fermer*/
	int i;
	int simple;
	int double_q;
	
	i = 0;
	simple = 0;
	double_q = 0;
	while (i < index_dol)
	{
		if (str[i] == '\'')
			simple++;
		if (str[i] == '"')
			double_q++;
		i++;
	}
	if (simple % 2 == 0 )
		return (1);
	if (simple % 2 != 0 && double_q % 2 != 0)
		return (1);
	return (0);
}

t_node *attribue_here_doc(t_node *root)
{

	t_node *ptr;
	printf("attribute heredoc 1\n");
	if (!root)
		return (NULL);
	printf("attribute heredoc 2\n");
	ptr = root -> first_child;
	printf("attribute heredoc 3\n");
	while (ptr)
	{
		printf("node is =>%s\n", ptr -> txt);
		if (is_it_heredoc(ptr) == 1)
		{
			printf("im heredoc\n");
			ptr -> heredoc = 0;
			ptr -> next_sibling -> heredoc = 1;
			return (ptr -> next_sibling);
		}
		else
		{
			printf("im NOT heredoc\n");
			ptr -> heredoc = 0;
			ptr -> after_here_doc = 0;
		}
		ptr = ptr -> next_sibling;
	}
	return (NULL);
}
void attribute_atfer_here_doc(t_node *node)
{
	t_node *ptr;
	if (!node)
		return ;
	ptr = node -> next_sibling;
	while (ptr)
	{
		ptr -> after_here_doc = 1;
		ptr = ptr -> next_sibling;
	}
}

