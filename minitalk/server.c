#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// si c sigusr1 c 0
// si c sigusr2 c 1
// transformer les 0 et 1 en byte
// traduire le byte en char 

int nbr;
int count;

count = 0;
nbr = 0;
int multiplicateur = 1;
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
void handlerSIGUSR1(int signum, siginfo_t *pid, void *idontknow)
{
    char letter;
    //void(idontknow);
    if (count > 0)
        multiplicateur = multiplicateur * 2;
    nbr = 1*multiplicateur + nbr;
    count++;
    if (count == 8)
    {
        letter = nbr;
        write(1,&letter,1);
        count = 0;
        nbr = 0;
        multiplicateur = 1;
    }
    kill(pid->si_pid, SIGUSR2);
        // write(1, "c2\n", 3);    
}

void handlerSIGUSR2(int signum, siginfo_t *pid, void *idontknow)
{

    char letter;

    //void(idontknow);
    if (count > 0)
        multiplicateur = multiplicateur * 2;
    nbr = 0*multiplicateur + nbr;
    count++;
    if (count == 8)
    {
        letter = nbr;
        write(1,&letter,1);
        count = 0;
        nbr = 0;
        multiplicateur = 1;

    }
    kill(pid->si_pid, SIGUSR2);
    // write(1, "c1\n", 3);
}
int main(int argc, char*argv[])
{
    int pid;
    struct sigaction action1;
    struct sigaction action2;
    sigset_t sigmask;

    // sigemptyset(&action1.sa_mask);
    // sigemptyset(&action2.sa_mask);
	// sigaddset(&sigmask, SIGUSR1);
	// sigaddset(&sigmask, SIGUSR2);
    sigemptyset(&sigmask);
    action1.sa_handler = handlerSIGUSR1;
    action1.sa_flags = SA_SIGINFO;
    action1.sa_mask = sigmask;
    action1.sa_sigaction = handlerSIGUSR1;
    
    action2.sa_handler = handlerSIGUSR2;
    action2.sa_flags = SA_SIGINFO;
    action2.sa_mask = sigmask;
    action2.sa_sigaction = handlerSIGUSR2;
	// sigaddset(&simask, SIGUSR1);
	// sigaddset(&sigmask, SIGUSR2);
    pid = getpid();
    ft_putnbr_fd(pid,1);
    sigaction(SIGUSR1, &action1,NULL);
    sigaction(SIGUSR2, &action2,NULL);
    while (1)
    {
        pause();
    }
}