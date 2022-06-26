#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// int	ft_check_same(char *str)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (str[i] != '\0')
// 	{
// 		j = i;
// 		while ((str[i] != str[j + 1]) && (str[j] != '\0'))
// 		{
// 			j++;
// 		}
// 		if (str[i] == str[j + 1])
// 		{
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int	ft_check_base(char *base, int lenght)
// {
// 	int	i;

// 	i = 0;
// 	if (lenght == 0 || lenght == 1)
// 	{
// 		return (0);
// 	}
// 	if (ft_check_same(base) == 0)
// 	{
// 		return (0);
// 	}
// 	while (base[i] != '\0')
// 	{
// 		if (base[i] == '+' || base[i] == '-')
// 		{
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// void	ft_putnbr_base(unsigned long long nbr, char *base)
// {
// 	int		lenght_base;
// 	unsigned long long	nb;
// 	int		check_base;

// 	nb = nbr;
// 	lenght_base = ft_strlen(base);
// 	check_base = ft_check_base(base, lenght_base);
// 	if (check_base == 0)
// 		write(1, "", 1);
// 	if ((nb < 0) && (check_base != 0))
// 	{
// 		write(1, "-", 1);
// 		nb = nb * -1;
// 	}
// 	if ((nb < lenght_base) && (check_base != 0))
// 	{
// 		write(1, &base[nb], 1);
// 	}
// 	else if ((nb > lenght_base) && (check_base != 0))
// 	{
// 		ft_putnbr_base(nb / lenght_base, base);
// 		ft_putnbr_base(nb % lenght_base, base);
// 	}
// }
// void printpointer(unsigned long long p)
// {
// 	int i = 0;
// 	// sauve garde ce que contient p 
// 	// affiche ce que contient p
// 	// c des chiffres du coup je dois afficher chaque chiffre 
// 	// c en base hexadecimale du coup je dois afficher des chiffres en hexadecimale
// 	// du coup je dois le convertir avec un ft_putnbrbased mais avant je vais essaye d4afficher juste le premier element pour voir
	
// 	while(i < 1)
// 	{
// 		ft_putnbr_base(p, "0123456789ABCDEF");
// 	}
// }

// void printanything(int args, ...)
// {
// 	int	i = 0;
// 	char c;
// 	va_list ap;

// 	va_start(ap, args);
// 	while(i < 1)
// 	{
// 		// voi avec python tutor  ce que vaut va arg du coup jenregistre dan une variable
// 		unsigned long long bob = (unsigned long long)va_arg(ap, int);
// 		printpointer(bob);
// 		i++;
// 	}
// 	// comparer avec la valeur de retour de printf
// 	// faut que je comprenne ce que me renvoie en fait va_arg, je pense que c un hexadecimale et je dois l'ajouter, voir avec python tuthor
// 	va_end(ap);
// }



// int main(void)
// {
// 	int bob = 3;
// 	printanything(1,&bob);
// }


void printanything(int args, ...)
{
    int    i = 0;
    char c;
    va_list ap;

    // unsigned long long int *bob;

    va_start(ap, args);
    while(i < 1)
    {
        // voi avec python tutor  ce que vaut va arg du coup jenregistre dan une variable
        unsigned long long int *bob = va_arg(ap, unsigned long long int *);
        printf("%llu\n", *bob);
        printf("%p", bob);

        //printf("%p", (&va_arg(ap, int)));
        i++;
    }
    // comparer avec la valeur de retour de printf
    // faut que je comprenne ce que me renvoie en fait va_arg, je pense que c un hexadecimale et je dois l'ajouter, voir avec python tuthor
    va_end(ap);
}

int main(void)
{
    unsigned long long int bob = 3;
    //int a = &bob;
    //printf("%p", a);
    printanything(1, &bob);
}

/* Pourquoi arrive-t-on a afficher une adresse memoire sans qu ce soit une variable pointeur (cf. ligne 146 et 147)
    alors que, normalement, c'est pas possible (cf. ligne 162)
pourquoi arrive t'on a enreigster dans une variable qui n'est pas de type pointer une adresse memoire cf 146 et pourquoi on arrive pas a le dereferencer alors
*/ 

