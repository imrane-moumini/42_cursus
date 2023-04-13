/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:14:54 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/13 18:48:24 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void supp_quotes(t_node *root)
{
	t_node *ptr;
	
	if (!root)
		return ;
	ptr = root -> first_child;
	while (ptr)
	{
		if (does_str_has_quotes(ptr -> txt) == 1)
			str_without_quotes(ptr);
		ptr = ptr -> next_sibling;
	} 
}

void str_without_quotes(t_node *ptr)
{
	char *new_str;
	int i;
	int j;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) *(ft_strlen(ptr -> txt) + 1));
	printf("c2.1\n");
	while (ptr -> txt[i] != '\0')
	{
		printf("c2.2\n");	
		if (ptr -> txt[i] == '"')
		{
			i++;
			if (!ptr)
				break;
			while (ptr -> txt[i])
			{
				if (ptr -> txt[i] == '"')
				{
					i++;
					break;
				}
				printf("char j : %c\nchar i %c", new_str[j], ptr -> txt[i]);
				new_str[j] = ptr -> txt[i];
				j++;
				i++;
			}
		}
		if (!ptr)
				break;
		if (ptr -> txt[i] == '\'')
		{
			i++;
			if (!ptr)
				break;
			while (ptr -> txt[i])
			{
				if (ptr -> txt[i] == '\'')
				{
					i++;
					break;
				}
				new_str[j] = ptr -> txt[i];
				j++;
				i++;
			}
		}
		if (ptr -> txt[i] != '\'' && ptr -> txt[i] != '"')
		{
			new_str[j] = ptr -> txt[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	free(ptr -> txt);
	ptr -> txt = new_str;
}
