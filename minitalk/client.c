#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	g_ok;

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
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

void	handlersigusr1(int signum)
{
	(void)signum;
	ft_putstr_fd("the server just told me that he received the entire message\n", 1);
}

void	handlersigusr2(int signum)
{
	(void)signum;
	g_ok = 1;
}

void	send_data(int pid, char c)
{
    int i;
    i = 0;
    while (i < 8)
    {
		g_ok = 0;
        if (((c) & (1)) == 1)
			kill(pid,SIGUSR1);
        else
			kill(pid,SIGUSR2);
		c = c >> 1;
		i++;
        while (ok == 0) 
		pause();
    }
}

int main(int argc, char*argv[])
{
    int	pid;
    int	length;
    int	i;

    (void) argc;
	signal(SIGUSR1, handlersigusr1);
	signal(SIGUSR2, handlersigusr2);
	i = 0;
	pid = atoi(argv[1]);
	length= ft_strlen(argv[2]);
    while (i <= length)
    {
		send_data(pid,argv[2][i]);
		i++;
    }
}
