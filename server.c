/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:21:25 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/12/25 13:12:33 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	handler(int sig)
{
	static int	byte;
	static int	i;

	if (sig == SIGUSR1)
		byte++;
	if (++i == 8)
	{
		ft_putchar_fd(byte, 1);
		byte = 0;
		i = 0;
	}
	else
		byte <<= 1;
}

int	main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
