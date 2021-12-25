/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:01:38 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/12/25 13:40:46 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	g_re;

void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_re++;
}

void	sendchar(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		signal(SIGUSR1, handler);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		sendchar(av[2][i++], pid);
	}
	ft_putnbr_fd(g_re, 1);
	ft_putstr_fd(" charcters received\n", 1);
}
