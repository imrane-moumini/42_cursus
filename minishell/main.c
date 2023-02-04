/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imrane <imrane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:57:56 by imrane            #+#    #+#             */
/*   Updated: 2023/02/04 20:07:20 by imrane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	while (1)
    {
        char *input;
        t_source src;
		
        input = readline("minishell> ");
		init_src(&src, input);
        printf("%c\n", next_char(&src));
        free(input);
    }
}