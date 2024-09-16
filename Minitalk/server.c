/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:23:22 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/16 20:53:44 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h> //! Careful with this dude.
#include <unistd.h>

void	sigusr1_handler()
{
	printf("Signal received!\n");
}

int	main(void)
{
	signal(SIGUSR1, sigusr1_handler);
	int pid = getpid();
	printf("Server PID: %d\n", pid);
	while (1)
	{
		printf("Waiting...\n");
		sleep(1);
	}
	return (0);
}
