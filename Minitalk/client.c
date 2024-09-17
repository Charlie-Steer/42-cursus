/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:37:03 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/17 21:04:36 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2 || argc != 3) //! Improve imput validation.
		return (printf("Error: Invalid argument count.\n"), 1); //! Careful with stdio printf.
	int server_pid = atoi(argv[1]); //! CAREFUL! Non-ft atoi.
	// kill(server_pid, SIGUSR1);
	{
		char *message = argv[2]; //! Properly copy the contents to a malloc'd message.
		int message_len = ft_strlen(message);
		char bit_value = 0;
		char mask = 1;
		int char_index = 0;
		while (char_index < message_len)
		{
			int bit_index = 0;
			while (bit_index < 8)
			{
				bit_value = message[bit_index] & mask;
				if (bit_value == 0)
					kill(server_pid, SIGUSR1);
				else
					kill(server_pid, SIGUSR2);
				message[char_index] >>= 1;
				bit_index++;
			}
			bit_index = 0;
			char_index++;
		}
	}

	return (0);
}
