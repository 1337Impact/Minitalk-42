/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:21:39 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/12/25 13:41:30 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
}
