/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/02/04 21:09:46 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	t_info_tok info;
	
	init_global_info_token(&info);
	while (1)
    {
        char *input;
        t_source src;
		
        input = readline("minishell> ");
		init_src(&src, input);
		skip_white_spaces(&src);
		printf("%c\n", src.buffer[src.curpos]);
        free(input);
    }
}