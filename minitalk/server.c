#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
char	*ft_strjoin(char *s1, char *s2)
{
	int		lenght_of_s1;
	int		lenght_of_s2;
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	
	lenght_of_s1 = ft_strlen(s1);
	lenght_of_s2 = ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * lenght_of_s1 + lenght_of_s2 + 1);
	if (p == NULL)
		return (NULL);
	while (i < lenght_of_s1)
	{
		p[i] = s1[i];
		i++;
	}
	while (j < lenght_of_s2)
	{
		p[i++] = s2[j++];
	}
	p[i] = '\0';
	free(s1);
	return (p);
}
void handlerSIGUSR(int signum, siginfo_t *pid, void *idontknow)
{
    char letter;
    static int nbr;
    static int count;
	static char *p;
    (void) idontknow;
    if (signum == SIGUSR1)
    {
        if (count > 0)
            multiplicateur = multiplicateur * 2;
        nbr = 1*multiplicateur + nbr;
        count++;
    }
    if (signum == SIGUSR2)
    {
        if (count > 0)
            multiplicateur = multiplicateur * 2;
        nbr = 0*multiplicateur + nbr;
        count++;
    }
    if (count == 8)
    {
        letter = nbr;
        p = ft_strjoin(p,&letter);
		if (letter == '\0')
		{	
			kill(pid->si_pid, SIGUSR1);
			ft_putstr_fd(p,1);
			write(1,"\n",1);
			free(p);
			p = NULL;
		}
        count = 0;
        nbr = 0;
        multiplicateur = 1;
    }
    kill(pid->si_pid, SIGUSR2);  
}

int main(void)
{
    int pid;
    struct sigaction action1;
    struct sigaction action2;
    sigset_t sigmask;

    sigemptyset(&sigmask);

    action1.sa_flags = SA_SIGINFO;
    action1.sa_mask = sigmask;
    action1.sa_sigaction = handlerSIGUSR;
    

    action2.sa_flags = SA_SIGINFO;
    action2.sa_mask = sigmask;
    action2.sa_sigaction = handlerSIGUSR;
    pid = getpid();
    ft_putnbr_fd(pid,1);
	write(1,"\n",1);
    sigaction(SIGUSR1, &action1,NULL);
    sigaction(SIGUSR2, &action2,NULL);
    while (1)
    {
        pause();
    }
}