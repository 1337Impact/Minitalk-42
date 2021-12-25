/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 21:01:08 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/12/25 13:25:33 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	byte;
	static int	i;

	(void)context;
	if (sig == SIGUSR1)
		byte++;
	if (++i == 8)
	{
		ft_putchar_fd(byte, 1);
		kill(info->si_pid, SIGUSR1);
		byte = 0;
		i = 0;
	}
	else
		byte <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
