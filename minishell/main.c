/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/02/05 22:25:59 by imrane           ###   ########.fr       */
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
        t_info_tok info;
        t_token *tok;
		
        input = readline("minishell> ");
		init_src(&src, input);
		init_global_info_token(&info);
        tok = tokenize(&src, &info);
		printf("%s\n", tok -> text);
        // ya rien qui s'affiche mais au moins ya pas de segfault
        free(input);
    }
}