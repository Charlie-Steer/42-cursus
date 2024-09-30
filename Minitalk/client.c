/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:37:03 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/30 13:15:36 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <assert.h>

int main(int argc, char **argv)
{
	if (argc != 2 && argc != 3) //? How should it act on argc == 2?
		return (ft_printf("Error: Invalid argument count.\n"), 1);
	int server_pid = ft_atoi(argv[1]);
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
				// printf("message: %s\n", message);
				bit_value = message[char_index] & mask;
				// printf("bit_value: %d\n", bit_value);
				if (bit_value == 0)
				{
					printf("0!\n");
					kill(server_pid, SIGUSR1);
				}
				else
				{
					printf("1!\n");
					assert(bit_value == 1); //! remove
					kill(server_pid, SIGUSR2);
				}
				message[char_index] >>= 1;
				bit_index++;
				usleep(1000);
			}
			bit_index = 0;
			char_index++;
		}
	}

	return (0);
}
