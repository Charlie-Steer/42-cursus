/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:23:22 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/02 19:44:50 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>

// volatile sig_atomic_t c;
//volatile unsigned char c;

//void	sigusr1_handler(int signum) //! I think only atomic operations should go inside a handler.
//{
	//c |= 0;
//}

//void	sigusr2_handler(int signum)
//{
	//c |= 1;
//}

void	alt_handler(int signum)
{
	static unsigned char	c;
	static int				i = 1;
	// DEBUG 1
	// {
	// 	if (i == 1)
	// 		printf("		");
	// }

	if (signum == SIGUSR1)
	{
		// printf("0");
		c |= 0;
	}
	else
	{
		// printf("1");
		c |= 1;
	}

	if (i == 8)
	{
		// DEBUG 2
		// {
		// 	printf("\n");
		// 	printf("%c		", c);
		// 	for (int j = 1; j <= 8; j++)
		// 	{
		// 		if ((c & (1 << (8 - j))) == 0)
		// 			printf("0");
		// 		else
		// 			printf("1");
		// 	}
		// 	printf("\n\n");
		// }
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
	//c = 0;
	// ft_printf("%lu\n", sizeof(sig_atomic_t));
	// signal(SIGUSR1, alt_handler);
	// signal(SIGUSR2, alt_handler);

	struct sigaction sa; //? Can't declare here?
	sa.sa_handler = &alt_handler;
	sa.sa_flags = SA_RESTART;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	int pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	ft_printf("Awaiting message...\n");
	int i = 0;
	// while (1)
	// {
	// 	while (i < 8)
	// 	{
	// 		pause();
	// 		if (i != 7)
	// 			c <<= 1;
	// 		i++;
	// 	}
	// 	write(1, (void *)&c, 1);
	// 	c = 0;
	// 	i = 0;
	// }
	while (1)
		pause();
	return (0);
}
