#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>




void	ft_putnbr_base(unsigned long long nbr)
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
		ft_putnbr_base(nb /16);
		ft_putnbr_base(nb %16);
	}
}
void printpointer(unsigned long long p)
{
	int i = 0;
	// sauve garde ce que contient p 
	// affiche ce que contient p
	// c des chiffres du coup je dois afficher chaque chiffre 
	// c en base hexadecimale du coup je dois afficher des chiffres en hexadecimale
	// du coup je dois le convertir avec un ft_putnbrbased mais avant je vais essaye d4afficher juste le premier element pour voir
	
	while(i < 1)
	{
        write(1, "0x", 2);
		ft_putnbr_base(p);
        i++;
	}
}

void printanything(int args, ...)
{
	int	i = 0;
	char c;
	va_list ap;

	va_start(ap, args);
	while(i < 1)
	{
		// voi avec python tutor  ce que vaut va arg du coup jenregistre dan une variable
		//unsigned long long bob = (unsigned long long)va_arg(ap, int);
		printpointer((unsigned long long int)va_arg(ap, unsigned long long int));
		i++;
	}
	// comparer avec la valeur de retour de printf
	// faut que je comprenne ce que me renvoie en fait va_arg, je pense que c un hexadecimale et je dois l'ajouter, voir avec python tuthor
	va_end(ap);
}



int main(void)
{
	int bob = 3;
    printf("the real one is =>%p\n", &bob);
	printanything(1, &bob);
    
}


// void printanything(int args, ...)
// {
//     int    i = 0;
//     char c;
//     va_list ap;

//     va_start(ap, args);
//     while(i < 1)
//     {
//         // voi avec python tutor  ce que vaut va arg du coup jenregistre dan une variable
//         unsigned long long int *bob = (unsigned long long int)va_arg(ap, int);
//         //printf("%p", (&va_arg(ap, int)));
//         i++;
//     }
//     // comparer avec la valeur de retour de printf
//     // faut que je comprenne ce que me renvoie en fait va_arg, je pense que c un hexadecimale et je dois l'ajouter, voir avec python tuthor
//     va_end(ap);
// }



// int main(void)
// {
//     int bob = 3;
//     printanything(1,&bob);
// }

// void print(unsigned long long int *d)
// {

//     printf("%llu", *d);
//     return ;
// }

// int	main()
// {
// 	unsigned long long int a;

//     a = 42;
//     print(&a);
// }