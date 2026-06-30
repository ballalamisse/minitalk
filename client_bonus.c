/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballalamisse <lamisse.balla@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:07:36 by ballalamisse          #+#    #+#             */
/*   Updated: 2026/07/01 15:32:26 by ballalamisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_str(int pid, char *str)
{
	int	i;
	int	c;
	int	out;
	int	l;

	i = 0;
	l = ft_strlen(str);
	while (i <= l)
	{
		c = 0;
		while (c < 8)
		{
			if ((str[i] & 128 >> c) == 0)
				out = kill(pid, SIGUSR2);
			else
				out = kill(pid, SIGUSR1);
			c++;
			usleep(800);
			if (out == -1)
				exit(0);
		}
		i++;
	}
}

void	print(int sig)
{
	(void)sig;
	ft_putstr_fd("Message Printed succesfully !", 1);
	exit(1);
}

int	main(int c, char *v[])
{
	int		pid;
	char	*ch;

	if (c != 3)
	{
		ft_putstr_fd("Wrong parameters !", 1);
		exit(1);
	}
	signal(SIGUSR1, print);
	pid = ft_atoi(v[1]);
	ch = v[2];
	send_str(pid, ch);
	while (1)
		usleep(10);
	return (0);
}
