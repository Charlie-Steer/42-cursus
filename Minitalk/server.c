/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:23:22 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/01 16:16:27 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t c;
// volatile char c;

void	sigusr1_handler(int signum) //! I think only atomic operations should go inside a handler.
{
	c |= 0;
}

void	sigusr2_handler(int signum)
{
	c |= 1;
}

int	main(void)
{
	c = 0;
	// ft_printf("%lu\n", sizeof(sig_atomic_t));
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr2_handler);
	// message = calloc(42, 1);
	int pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_printf("Awaiting message...\n");
	int i = 0;
	while (1)
	{
		while (i < 8)
		{
			pause();
			if (i != 7)
				c <<= 1;
			i++;
		}
		write(1, (void *)&c, 1);
		c = 0;
		i = 0;
	}
	return (0);
}
