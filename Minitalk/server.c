/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:23:22 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/04 14:18:35 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sigusr_handler(int signum)
{
	static unsigned char	c;
	static int				i = 1;

	if (signum == SIGUSR1)
		c |= 0;
	else
		c |= 1;
	if (i == 8)
	{
		write(1, (void *)&c, 1);
		i = 1;
		c = 0;
		return ;
	}
	else
	{
		c <<= 1;
		i++;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_handler = &sigusr_handler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_printf("Awaiting message...\n");
	while (1)
		pause();
	return (0);
}
