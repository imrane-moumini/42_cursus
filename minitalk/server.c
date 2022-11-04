/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:50:03 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/04 20:30:30 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_multiplicateur = 1;

void	handlersiguser(int signum, siginfo_t *pid, void *idontknow)
{
	char	letter;
	static int	nbr;
	static int	count;
	static char	*p;
	(void) idontknow;
	if (signum == SIGUSR1)
    {
		if (count > 0)
			g_multiplicateur = g_multiplicateur * 2;
			nbr = 1 * g_multiplicateur + nbr;
			count++;
    }
    if (signum == SIGUSR2)
    {
		if (count > 0)
			g_multiplicateur = g_multiplicateur * 2;
		nbr = 0*g_multiplicateur + nbr;
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
		g_multiplicateur = 1;
	}
	kill(pid->si_pid, SIGUSR2);  
}

int	main(void)
{
	int					pid;
	struct sigaction	action1;
	struct sigaction	action2;
	sigset_t			sigmask;

	sigemptyset(&sigmask);
	action1.sa_flags = SA_SIGINFO;
	action1.sa_mask = sigmask;
	action1.sa_sigaction = handlersigusr;
	action2.sa_flags = SA_SIGINFO;
	action2.sa_mask = sigmask;
	action2.sa_sigaction = handlersigusr;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &action1, NULL);
	sigaction(SIGUSR2, &action2, NULL);
	while (1)
		pause();
}
