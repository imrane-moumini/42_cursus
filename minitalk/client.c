#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ok;
ok = 1;

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

void handlerSIGUSR(int signum)
{
    if (signum == SIGUSR1 || signum == SIGUSR2)
    ok = 1;
    write(1,"well receive",12);
}

void send_data(int pid, char c)
{
    int i;
    i = 0;
    while (i < 8)
    {
        ok = 0;
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
        c = c >> 1;
        i++;
        while (ok == 0) 
        {
            pause();
        }
    }
}

int main(int argc, char*argv[])
{
    int pid;
    int i;

    signal(SIGUSR2, handlerSIGUSR);
    i = 0;
    pid = atoi(argv[1]);

    while (argv[2][i] != '\0')
    {
         send_data(pid,argv[2][i]);
        i++;
    }
}