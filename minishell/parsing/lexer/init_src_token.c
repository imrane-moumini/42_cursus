/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_src_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:00:16 by imrane            #+#    #+#             */
/*   Updated: 2023/02/25 14:53:20 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_src(t_source *src, char *input)
{
	src = malloc(sizeof(t_source));
	src -> buffer = input;
	src -> bufsize = ft_strlen(input);
	src -> curpos = 0;
	src -> end_input = 0;
	src -> exit = 0;
}

void init_global_info_token(t_info_tok *info)
{
	info = malloc(sizeof(t_info_tok));
	info -> tok_buf = NULL;
	info -> tok_bufsize = 0;
	info -> tok_bufindex = -1;
}
