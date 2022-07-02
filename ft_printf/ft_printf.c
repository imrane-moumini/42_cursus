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
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>


int ft_printf(const char *stringparams, ...)
{
    va_list ap;
	int		i;
	unsigned long long 		p;
	int		lenght;

	i = 0;
	lenght = 0;
    va_start(ap, stringparams);
	while (stringparams[i] != '\0')
	{
		while ((stringparams[i] == '%')  && (stringparams[i] != '\0') )
		{
			i++;
			if ( (stringparams[i] == '%' ) && ( (stringparams[i + 1] == '%') || (stringparams[i - 1] == '%') ) && (stringparams[i] != '\0') ) 
			{
				//affiche un signe pourcentage
				write(1, "%", 1);
				lenght++;
				i++;
			}
			if ((stringparams[i] == 'c')  && (stringparams[i] != '\0') )
			{
				//Affiche un seul caractère
				ft_putchar_fd((char)va_arg(ap, int), 1);
				lenght++;
				i++;
			}
			if ((stringparams[i] == 's')  && (stringparams[i] != '\0') )
			{
				//Affiche une chaîne de caractères (telle que définie par la convention C).
				lenght = lenght + printstr(va_arg(ap, char *));
				i++;
			}
			if ((stringparams[i] == 'p')  && (stringparams[i] != '\0') )
			{
				//L’argument de pointeur void * doit être affiché en hexadécimal.
				p = va_arg(ap, unsigned long long);
				if (p == 0)
				{
					lenght = lenght + (write(1, "(nil)", 5));	
				}
				if (p != 0)
				{
					lenght = 2 + lenght + printpointer(p);
				}
				i++;
			}
			if ((stringparams[i] == 'd')  && (stringparams[i] != '\0') )
			{
				//Affiche un nombre décimal (base 10).
				//printf("\nin D before function l = %d\n", lenght);
				lenght = lenght + ft_putnbr_spe_fd(va_arg(ap, int), 1);
				//printf("\nin D l = %d\n", lenght);
				i++;
			}
			if ((stringparams[i] == 'i')  && (stringparams[i] != '\0') )
			{
				//Affiche un entier en base 10.
				lenght = lenght + ft_putnbr_spe_fd(va_arg(ap, int), 1);
				i++;
			}
			if ((stringparams[i] == 'u')  && (stringparams[i] != '\0') )
			{
				//Affiche un nombre décimal non signé (base 10).
				lenght = lenght + ft_putnbr_unsigned_fd(va_arg(ap, unsigned int), 1);
				i++;
			}
			if ((stringparams[i] == 'x')  && (stringparams[i] != '\0') )
			{
				// Affiche un nombre en hexadécimal (base 16) avec des lettres minuscules
				lenght = lenght + ft_putnbr_hex_mini(va_arg(ap, int));
				//printf("\nnumber is %d\n", count_hex_spe(va_arg(ap, int)));
				i++;
			}
			if ((stringparams[i] == 'X')  && (stringparams[i] != '\0') )
			{
				// Affiche un nombre en hexadécimal (base 16) avec des lettres majuscules
				lenght = lenght + ft_putnbr_hex_maj(va_arg(ap, int));
				i++;
			}			
		}
		ft_putchar_fd(stringparams[i], 1);
		if (stringparams[i] != '\0')
		{
			i++;
			lenght++;
		}
	}
    va_end(ap);
	//printf("\nin the end l = %d\n", lenght);
	return (lenght);
}

// int	main(void)
// {
// 	//char * bob = "ueue92";
// 	//int ali = 3;
// 	//int *p = &ali;
// 	//int *p = &bob;
// 	//printf("X\n", bob);
// 	printf("\n%d", ft_printf("%u", -9));	
// }
