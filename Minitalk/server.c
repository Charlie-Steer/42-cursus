/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:23:22 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/30 13:29:27 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// volatile sig_atomic_t a;
volatile char a;

void	sigusr1_handler(int signum) //! I think only atomic operations should go inside a handler.
{
	// ft_printf("0\n");
	// ft_printf("test:\n");
	if (signum == SIGUSR1)
	{
		// ft_printf("here\n");
		a |= 0;
		ft_printf("a: %d\n", a);
		a >>= 1;
	}
	else if (signum == SIGUSR2)
	{
		// ft_printf("or here?\n");
		a |= 1;
		ft_printf("a: %d\n", a);
		a >>= 1;
	}
}

void	sigusr2_handler(int signum)
{
	ft_printf("1\n");
}

int	main(void)
{
	a = 0;
	// ft_printf("%lu\n", sizeof(sig_atomic_t));
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr1_handler);
	// message = calloc(42, 1);
	int pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_printf("Awaiting message...");
	while (1)
	{
		int i = 0;
		while (i < 8)
		{
			pause();
			ft_printf("a is now: %c\n", a);
			i++;
		}
		ft_printf("char: %c\n", a);
		i = 0;
	}
	return (0);
}
