/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_src_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:00:16 by imrane            #+#    #+#             */
/*   Updated: 2023/02/05 21:08:25 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	init_src(t_source *src, char *input)
{
	src -> buffer = input;
	src -> bufsize = ft_strlen(input);
	src -> curpos = 0;
}

void init_global_info_token(t_info_tok *info)
{
	info -> tok_buf = NULL;
	info -> tok_bufsize = 0;
	info -> tok_bufindex = -1;
}
