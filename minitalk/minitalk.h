/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoumini <imoumini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:31:20 by imoumini          #+#    #+#             */
/*   Updated: 2022/11/04 21:34:11 by imoumini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

void	handlerSIGUSR(int signum, siginfo_t *pid, void *idontknow);
void	handlersigusr1(int signum);
void	handlersigusr2(int signum);
#endif