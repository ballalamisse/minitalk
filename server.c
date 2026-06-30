/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballalamisse <lamisse.balla@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:16:16 by ballalamisse          #+#    #+#             */
/*   Updated: 2026/07/01 15:33:04 by ballalamisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset(int *a, char *b)
{
	*a = 0;
	*b = 0;
}

void	sig_handler(int sig, siginfo_t *info, void *em)
{
	static char	c;
	static int	bi;
	static int	g_pid = -1;

	(void)em;
	if (g_pid != info->si_pid)
	{
		reset(&bi, &c);
		g_pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		c = c | (c ^ (128 >> bi));
	else if (sig == SIGUSR2)
		c = c | (c & (128 >> bi));
	bi++;
	if (bi == 8)
	{
		write(1, &c, 1);
		c = 0;
		bi = 0;
	}
}

int	main(void)
{
	struct sigaction	sac;

	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sac.sa_flags = SA_SIGINFO;
	sac.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sac, NULL);
	sigaction(SIGUSR2, &sac, NULL);
	while (1)
		usleep(5000);
	return (0);
}
