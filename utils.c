/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 19:22:45 by mbenkhat          #+#    #+#             */
/*   Updated: 2021/12/24 22:51:25 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putn(long int n, int fd)
{
	long int	ln;

	ln = n;
	if (ln == 0)
		ft_putchar_fd(ln + '0', fd);
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln = -ln;
	}
	if (ln <= 9 && ln)
	{
		ft_putchar_fd(ln + '0', fd);
	}
	if (ln > 9)
	{
		ft_putn(ln / 10, fd);
		ln = ln % 10;
		ft_putchar_fd(ln + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putn(n, fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	out;
	int	a;

	i = 0;
	out = 0;
	a = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			a = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		out = out * 10 + (str[i] - 48);
		i++;
	}
	return (out * a);
}
