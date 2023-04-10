/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_token2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:16:47 by imrane            #+#    #+#             */
/*   Updated: 2023/04/10 16:46:23 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int tokenize_space(char c, t_source *src, t_info_tok *info)
{
	(void)c;
	if (info -> tok_bufindex != -1)
	{
		info -> tok_bufindex++;
		info -> tok_buf[info -> tok_bufindex] = '\0';
		src -> curpos++;
		return (1);	
	}
	return (0);
}


int tokenize_pipe(char c, t_source *src, t_info_tok *info)
{
	(void)c;
	if (info -> tok_bufindex != -1)
	{
		info -> tok_bufindex++;
		info -> tok_buf[info -> tok_bufindex] = '\0';
		return (1);	
	}
	else
	{
		info -> tok_bufindex++;
		add_to_buf(c, info);
		src -> curpos++;
		return (1);
	}
	return (0);
}

void tokenize_end(char c, t_source *src, t_info_tok *info)
{
	(void)c;
	if (info -> tok_bufindex != -1)
	{
		info -> tok_bufindex++;
		info -> tok_buf[info -> tok_bufindex] = '\0';
	}
	src -> end_input = 1;
}

int tokenize_in_out(char c, t_source *src, t_info_tok *info)
{
	(void)c;
	if (info -> tok_bufindex != -1)
	{
		info -> tok_bufindex++;
		info -> tok_buf[info -> tok_bufindex] = '\0';
		return (1);	
	}
	else
	{
		info -> tok_bufindex++;
		add_to_buf(c, info);
		src -> curpos++;
		return (1);
	}
	return (0);
}
int tokenize_single_quote(char c, t_source *src, t_info_tok *info)
{
	
	if (info -> tok_bufindex != -1 && (does_str_has_single_quotes(info -> tok_buf) == 1) && (is_double_quotes_str_closed(info -> tok_buf) == 1) && (next_src_is_legit(src) == 0))
	{
		printf("d3\n");
		info -> tok_bufindex++;
		add_to_buf(c, info);
		info -> tok_bufindex++;
		info -> tok_buf[info -> tok_bufindex] = '\0';
		src -> curpos++;
		return (1);	
	}
	else
	{
		printf("d4\n");
		info -> tok_bufindex++;
		add_to_buf(c, info);
		src -> curpos++;
		return (0);
	}
	return (0);
}
int tokenize_double_quote(char c, t_source *src, t_info_tok *info)
{
	if (info -> tok_bufindex != -1 && (does_str_has_double_quotes(info -> tok_buf) == 1) && (is_single_quotes_str_closed(info -> tok_buf) == 1) && (next_src_is_legit(src) == 0))
	{
		printf("d1\n");
		info -> tok_bufindex++;
		add_to_buf(c, info);
		info -> tok_bufindex++;
		info -> tok_buf[info -> tok_bufindex] = '\0';
		src -> curpos++;
		return (1);	
	}
	else
	{
		printf("d2\n");
		info -> tok_bufindex++;
		add_to_buf(c, info);
		src -> curpos++;
		return (0);
	}
	return (0);
}

int next_src_is_legit(t_source *src)
{
	printf("legit 1\n");
	if (!src)
		return (0);
	printf("legit 2\n");
	if (!(src -> buffer[src -> curpos + 1]))
		return (0);
	printf("legit 3\n");
	if (src -> buffer[src -> curpos + 1])
	{
		printf("legit 4\n");
		if (src -> buffer[src -> curpos + 1] != ' ' && src -> buffer[src -> curpos + 1] != '\t')
		{
			printf("legit 5\n");
			return (1);
		}
	}
	printf("legit 6\n");
	return (0);
	
}