/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:37:49 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/11 20:25:52 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



typedef struct	s_point
{
	int			position_x;
	int			position_y;
	int			number_of_c;
	int			is_an_exit;
	int 		tab_number_of_ligne;
	int 		tab_number_of_column;
	char **		tab;
}				s_game;
#endif 