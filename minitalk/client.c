#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// transformer ce que jecris en binaire 0 et 1 
// si le caractere c 0 envoyer sigusr1
// si le caractere c 1 envoyer sigusr1
int count;
void print_bits(unsigned char octet)
{
	int	i = 8;
	unsigned char 	bit;

	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
void	ft_putnbr_fd(int n, int fd)
{
	long long	nbr;
	char		c;

	nbr = n;
	if (n < 0)
	{
		nbr = nbr * -1;
		write(fd, "-", 1);
	}
	if (nbr < 10)
	{
		c = nbr + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
}


void send_data(int pid, char c)
{
    int i;
    i = 0;
    write(1,"c is ",5);
    write(1,&c,1);
    write(1,"\n",1);
    while (i < 8)
    {
        print_bits(c);
        write(1,"\n",1);
        if (c & 1 == 1)
        {
            write(1,"SUGUSR1\n",8);
            kill(pid,SIGUSR1);
            
        }
        else
        {
            write(1,"SUGUSR2\n",8);
            kill(pid,SIGUSR2); 
        }
        usleep(1000);
        c = c >> 1;
        count++;
        i++;
    }
    ft_putstr_fd("count is ",1);
    ft_putnbr_fd(i,1);
    write(1,"\n",1);
}

int main(int argc, char*argv[])
{
    int pid;
    int i;

    i = 0;
    pid = atoi(argv[1]);
    while (argv[2][i] != '\0')
    {
        send_data(pid,argv[2][i]);
        i++;
    }
}