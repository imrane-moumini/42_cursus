/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:04:14 by imoumini          #+#    #+#             */
/*   Updated: 2022/06/22 21:04:17 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
// void	ft_putnbr_dec_fd(double n, int fd)
// {
// 	long long	nbr;
// 	char		c;

// 	nbr = n;
// 	if (n < 0)
// 	{
// 		nbr = nbr * -1;
// 		write(fd, "-", 1);
// 	}
// 	if (nbr < 10)
// 	{
// 		c = nbr + '0';
// 		write(fd, &c, 1);
// 	}
// 	else
// 	{
// 		ft_putnbr_fd(nbr / 10, fd);
// 		ft_putnbr_fd(nbr % 10, fd);
// 	}
// }

void	ft_putnbr_hex_mini(unsigned long long nbr)
{
	
	unsigned long long	nb;
	char *base;

	nb = nbr;
    base = "0123456789abcdef";
	if ((nb < 16))
	{
		write(1, &base[nb], 1);
	}
	else if ((nb >= 16))
	{
		ft_putnbr_hex_mini(nb /16);
		ft_putnbr_hex_mini(nb %16);
	}
}
void	ft_putnbr_hex_maj(unsigned long long nbr)
{
	
	unsigned long long	nb;
	char *base;

	nb = nbr;
    base = "0123456789ABCDEF";
	if ((nb < 16))
	{
		write(1, &base[nb], 1);
	}
	else if ((nb >= 16))
	{
		ft_putnbr_hex_maj(nb /16);
		ft_putnbr_hex_maj(nb %16);
	}
}
void printpointer(unsigned long long p)
{
	write(1, "0x", 2);
	ft_putnbr_hex_mini(p);
}

void printstr(char *str)
{
	ft_putstr_fd(str, 1);
}

int ft_printf(const char *stringparams, ...)
{
    va_list ap;
	int		i;

	i = 0;
    va_start(ap, stringparams);
	while (stringparams[i] != '\0')
	{
		while (stringparams[i] == '%')
		{
			i++;
			if ( (stringparams[i] == '%' ) && ( (stringparams[i + 1] == '%') || (stringparams[i - 1] == '%') ) ) 
			{
				//affiche un signe pourcentage
				write(1, "%", 1);
				i++;
			}
			if (stringparams[i] == 'c')
			{
				//Affiche un seul caractère
				ft_putchar_fd((char)va_arg(ap, int), 1);
				i++;
			}
			if (stringparams[i] == 's')
			{
				//Affiche une chaîne de caractères (telle que définie par la convention C).
				printstr(va_arg(ap, char *));
				i++;
			}
			if (stringparams[i] == 'p')
			{
				//L’argument de pointeur void * doit être affiché en hexadécimal.
				printpointer((unsigned long long)va_arg(ap, unsigned long long));
				i++;
			}
			if (stringparams[i] == 'd')
			{
				//Affiche un nombre décimal (base 10).
				// ft_putnbr_dec_fd(va_arg(ap, double));
				i++;
			}
			if (stringparams[i] == 'i')
			{
				//Affiche un entier en base 10.
				ft_putnbr_fd(va_arg(ap, int), 1);
				i++;
			}
			if (stringparams[i] == 'u')
			{
				//Affiche un nombre décimal non signé (base 10).
				i++;
			}
			if (stringparams[i] == 'x')
			{
				// Affiche un nombre en hexadécimal (base 16) avec des lettres minuscules
				ft_putnbr_hex_mini(va_arg(ap, int));
				i++;
			}
			if (stringparams[i] == 'X')
			{
				// Affiche un nombre en hexadécimal (base 16) avec des lettres majuscules
				ft_putnbr_hex_maj(va_arg(ap, int));
				i++;
			}	
		}
		ft_putchar_fd(stringparams[i], 1);
		i++;
	}
	printf("\n\n%d", i);
    va_end(ap);
}

int	main(void)
{
	int bob = 3568;
	int *p = &bob;
	//printf("X\n", bob);
	ft_printf("bob%%%%%%%%X%\n%",bob);	
}