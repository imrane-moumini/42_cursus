/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:47:11 by imrane            #+#    #+#             */
/*   Updated: 2023/02/19 22:16:59 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char    *ft_strcpy(char *str)
{
	int i;
	int length;
	char *ptr;
	
	if (!str)
		return (NULL);
	i = 0;
	length = ft_strlen(str);
	ptr = malloc((sizeof(char) *length) + 1);
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

t_env	*new_node_env(void)
{
	t_env *node;
	
	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node -> next = NULL;

	return (node);
}
t_env   *add_node_env(t_env *head)
{
	t_env *ptr;

	if (!head)
		return (NULL);
	ptr = head;
	if (head -> next == NULL)
	{
		head -> next = new_node_env();
		return (head);
	}
	else
	{
		while (ptr -> next != NULL)
			ptr = ptr -> next;
		ptr -> next = new_node_env();
	}
	return (head);
}

void    create_var_value(t_env *node)
{
	int i;
	int equal;

	if (!node)
		return ;
	if (node -> txt == NULL)
		return ;
	equal = 0;
	while(node -> txt[equal] != '=')
		equal++;
	i = equal;
	while (node -> txt[i] != '\0')
		i++;
	node -> var_value = malloc((sizeof(char) *(i - equal)) + 1);
	if (node -> var_value == NULL)
		return ;
	i = 0;
	while(node -> txt[equal] != '\0')
	{
		node -> var_value[i] = node -> txt[equal];
		i++;
		equal++;
	}
	node ->var_value[i] = '\0';
}

void    create_var_name(t_env *node)
{
	int i;
	
	if (!node)
		return ;
	if (node -> txt == NULL)
		return ;
	i = 0;
	printf("var name 1\n");
	while(node -> txt[i] != '=')
		i++;
	printf("var name 2\n");
	node -> var_name = malloc((sizeof(char))*i + 1);
	printf("var name 3\n");
	if (node -> var_name == NULL)
		return ;
	printf("var name 4\n");
	i = 0;
	printf("var name 5\n");
	while(node -> txt[i] != '=')
	{
		printf("var name 6\n");
		node -> var_name[i] = node -> txt[i];
		printf("var name 7\n");
		i++;
	}
	printf("var name 8\n");
	node ->var_name[i] = '\0';
	printf("var name 9\n");
}

t_env   *copy_env(char *original[])
{
    int i;
	t_env *mini_env;
	t_env	*ptr;

	i = 0;
	printf("c1\n");
	if (!original || original[0] == NULL)
		return (NULL);
	mini_env = malloc(sizeof(t_env));
	printf("c2\n");
	if (mini_env == NULL)
		return (NULL);
	mini_env -> next = NULL;
	printf("c3\n");
	while (original[i])
		i++;
	printf("c4\n");
	while(i > 0)
	{
		printf("c5\n");
		mini_env = add_node_env(mini_env);
		printf("c6\n");
		i--;
	}
	ptr = mini_env;
	printf("c7\n");
	while (original[i] && ptr != NULL)
	{
		printf("c8\n");
		ptr -> txt = ft_strcpy(original[i]);
		printf("c9\n");
		ptr = ptr -> next;
		printf("c10\n");
		i++;
	}
	ptr = mini_env;
	printf("c11\n");
	while(ptr != NULL)
	{
		printf("c12\n");
		create_var_name(ptr);
		printf("c13\n");
		create_var_value(ptr);
		printf("c14\n");
		ptr = ptr -> next;
	}
	return (mini_env);
}

void    print_env(t_env *head)
{
	t_env *ptr;

	ptr = head;
	while (ptr != NULL)
	{
		ft_printf("%s\n", ptr -> txt);
		ptr = ptr -> next;
	}
}