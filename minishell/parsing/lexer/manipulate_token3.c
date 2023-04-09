/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_token3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:42:55 by imoumini          #+#    #+#             */
/*   Updated: 2023/04/09 18:24:40 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
int tokenize_while(t_source *src, t_info_tok *info, char c)
{
	printf("c is =>%c\n", c);
	if (c == '"' || c == '\'')
	{
		printf("a1\n");
		if (c == '"')
		{
			printf("a2\n");
			if (tokenize_double_quote(c, src, info) == 1)
				return (1);
		}
		else
		{
			printf("a3\n");
			if (tokenize_single_quote(c, src, info) == 1)
				return (1);
		}
	}
	if ((c == ' ' || c == '\t' || c == '\n') && (does_str_has_quotes(info -> tok_buf)) == 0 )
	{
		printf("a4\n");
		if (tokenize_space(c, src, info) == 1)
			return (1);
	}
	else if (c == '|' && (does_str_has_quotes(info -> tok_buf)) == 0)
	{
		printf("a5\n");
		if (tokenize_pipe(c, src, info) == 1)
			return (1);
	}
	else if ((c == '<' || c == '>') && (does_str_has_quotes(info -> tok_buf)) == 0)
	{
		printf("a6\n");
		if (tokenize_in_out(c, src, info) == 1)
			return (1);	
	}
	else if (c != '"' && c != '\'')
	{
		printf("a7\n");
		info -> tok_bufindex++;
		add_to_buf(c, info);
	}
	
	printf("a8\n");
	return (0);
}

void init_buf_size(t_info_tok *info)
{
	info -> tok_bufsize = 1024;
	info -> tok_buf = ft_calloc(info -> tok_bufsize, sizeof(char));
}

int does_str_has_quotes(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

int does_str_has_single_quotes(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

int does_str_has_double_quotes(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

int is_just_tok_quotes(char *str)
{
	int i;

	i = 0;
	
	if (str)
		printf("str is =>%s\n", str);
	if (str)
	{
		if (str[i] != '"' && str[i] != '\'')
			return (1);
	}
	while (str[i])
	{
		printf("cond 1\n");
		if (str[i] == '"' || str[i] == '\'')
		{
			printf("cond 2\n");
			i++;
			while (str[i] && str[i] != '"' && str[i] != '\'')
			{
				printf("cond 3\n");
				i++;	
			}
			if (str[i] == '\'' || str[i] == '"')
			{
				printf("cond 4\n");
				return (1);
			}
				
			printf("cond 5\n");
		}
		i++;
	}
	printf("cond 6\n");
	return (0);
}