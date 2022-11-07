/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:41:37 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/07 20:57:59 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
    int fd;
    char *p;
    char c = 'c';
    (void) argc;
    fd = open(argv[1],O_RDONLY);
    p = &c;
	while (p != NULL)
    {
		p = get_next_line(fd);
		if (p != NULL)
		{
			printf("%s", p);
		}
		free(p);
	}
	close(fd);
}