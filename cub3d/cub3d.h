/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:59:46 by imoumini          #+#    #+#             */
/*   Updated: 2023/05/18 17:57:56 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
#define CUB3D_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
typedef struct s_game
{

	void	*mlx_ptr;
	void	*win_ptr;
	
}				t_game;

/* game gestion*/
int	handle_click(t_game *game);
int	handle_input(int key, t_game *game);

#endif