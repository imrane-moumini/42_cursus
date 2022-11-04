/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:49:28 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/04 19:58:53 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_ok;

void	handlersigusr1(int signum)
{
	(void)signum;
	ft_putstr_fd("the server told me that he received the message\n", 1);
}

void	handlersigusr2(int signum)
{
	(void)signum;
	g_ok = 1;
}

void	send_data(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ok = 0;
		if (((c) & (1)) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		i++;
		while (g_ok == 0)
			pause();
	}
}

int	main(int argc, char*argv[])
{
	int	pid;
	int	length;
	int	i;

	i = 0;
	pid = atoi(argv[1]);
	length = ft_strlen(argv[2]);
	if (argc != 3)
		return (0);
	signal(SIGUSR1, handlersigusr1);
	signal(SIGUSR2, handlersigusr2);
	while (i <= length)
	{
		send_data(pid, argv[2][i]);
		i++;
	}
}
