/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_env4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:37:52 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/10 18:25:12 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*return_matching_value(t_env *head, char *str)
{
	t_env *ptr;

	ptr = head;
	if (!ptr || !str)
		return (NULL);
	while (ptr != NULL)
	{
		if (ft_stcmp(str, ptr -> txt) == 1)
			return (ptr -> var_value);
		ptr = ptr -> next;
	}
	return (NULL);
}

void	cut_dollar_sign(char *str)
{
	int i;
	int length;

	i = 0;
	length = ft_strlen(str);
	while (str[i + 1])
	{
		str[i] = str[i + 1];
		i++;
	}
	length = length -1;
	str[length] = '\0';
}

char *catch_var(char *str)
{
	if (!str)
		return (NULL);
	int i;
	int length;
	char *var;
	
	printf ("E2.1\n");
	printf("str is =>%s\n", str);
	length = 0;
	i = 0;
	while (str[length] != '\0' && str[length] != '$' && str[length] != ' ' && str[length] != '\t' && str[length] != '\'' && str[length] != '"')
		length++;
	printf ("E2.2\n");
	printf ("length is %i\n", length);
	var = malloc(sizeof(char) * (length + 1));
	printf("str[i] is =>%c\n", str[i]);
	while(str[i] != '\0' && str[i] != '$' && str[i] != ' ' && str[i] != '\t' && str[i] != '\'' && str[i] != '"')
	{
		printf("c is =>%c\n", str[i]);
		var[i] = str[i];
		i++;
	}
	var[i] = '\0';
	printf ("E2.3\n");
	printf("var is =>%s\n", var);
	return (var);
}

char *before_dollar(char *str)
{
	int i;
	int length;
	char *before;

	
	i = 0;
	length = 0;
	while (str[length] != '$')
		length++;
	before = malloc(sizeof(char) * (length + 1));
	
	while(str[i] != '$')
	{
		before[i] = str[i];
		i++;
	}
	before[i] = '\0';
	return (before);
}

char *after_dollar(char *str)
{
	int j;
	int save;
	j = 0;

	while (str[j] != '\0')
	{
		if (str[j] == '$')
			break;
		j++;
	}
	if (str[j] == '\0')
		return (NULL);
	j++;
	while (str[j] != '\0')
	{
		if (str[j] == '$')
			break;
		j++;
	}
	if (str[j] == '\0')
		return (NULL);
	save = j;
	return (return_after(str, j, save));
}

char *find_end_of_var(char *str)
{
	if (!str)
		return (NULL);
	int i;
	
	i = 0;
	while (str[i] != '\0' && str[i] != '$' && str[i] != ' ' && str[i] != '\t' && str[i] != '\'' && str[i] != '"')
		i++;
	if (str)
		str = str + i;
	return (str);
}
char *after_dollar_deux(char *str)
{
	int i;
	char *after;
	int length;

	if (!str)
		return (NULL);
	length = 0;
	i = 0;
	while (str[length] != '\0')
		length++;
	after = malloc(sizeof(char) * (length + 1));
	while (str[i] != '\0')
	{
		after[i] = str[i];
		i++;
	}
	return (after);
	
}