/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:28:24 by imoumini          #+#    #+#             */
/*   Updated: 2022/07/10 16:28:27 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>

char	*get_next_line(int fd);
int		is_end_of_line(char *str);
void	put_extra_in_buff(char *savetext, char *buff);
void	line_to_return(char *buff);
int		is_empty(char *buff);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	erase_buff(char *buff);
#endif
