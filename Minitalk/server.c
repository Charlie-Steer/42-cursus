/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:23:22 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/17 21:21:21 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h> //! Careful with this dude.
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t a;

void	sigusr1_handler(int signum) //! I think only atomic operations should go inside a handler.
{
	if (signum == SIGUSR1)
	{
		a |= 0;
		a <<= 1;
	}
	else if (signum == SIGUSR2)
	{
		a |= 1;
		a <<= 1;
	}
}

void	sigusr2_handler()
{
	printf("Signal received!\n");
}

int	main(void)
{
	a = 0;
	printf("%lu\n", sizeof(sig_atomic_t));
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr1_handler);
	// message = calloc(42, 1);
	int pid = getpid();
	printf("Server PID: %d\n", pid);
	printf("Awaiting message...");
	while (1)
	{
		int i = 0;
		while (i < 8)
		{
			pause();
			i++;
		}
		i = 0;
	}
	return (0);
}
