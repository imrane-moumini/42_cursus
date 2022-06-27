/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:03:02 by imoumini          #+#    #+#             */
/*   Updated: 2022/05/26 17:40:48 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
int ft_printf(const char *stringparams, ...);
int	count_int_spe(long long n);
int	count_hex_spe(long long n);
int	ft_putstr_spe_fd(char *s, int fd);
int	ft_putnbr_spe_fd(int n, int fd);
int	ft_putnbr_unsigned_fd(unsigned int n, int fd);
int	ft_putnbr_hex_mini(unsigned long long nbr);
int	ft_putnbr_hex_maj(unsigned long long nbr);
int printpointer(unsigned long long p);
int printstr(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
#endif
