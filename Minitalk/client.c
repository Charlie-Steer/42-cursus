/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:37:03 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/01 16:27:31 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <assert.h>

void	send_bit()
{

}

void	send_message(int server_pid, char *message)
{
	int				message_len = ft_strlen(message);
	unsigned char	bit_value = 0;
	unsigned char	mask = 128;
	int				char_index = 0;
	int				bit_index = 0;

	while (char_index < message_len)
	{
		while (bit_index < 8)
		{
			bit_value = message[char_index] & mask;
			bit_value >>= 7;
			if (bit_value == 0)
			{
				ft_printf("0");
				kill(server_pid, SIGUSR1);
			}
			else
			{
				assert(bit_value == 1); //! remove
				printf("1");
				kill(server_pid, SIGUSR2);
			}
			message[char_index] <<= 1;
			bit_index++;
			ft_printf("\n");
			usleep(200);
		}
		bit_index = 0;
		char_index++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2 && argc != 3) //? How should it act on argc == 2?
		return (ft_printf("Error: Invalid argument count.\n"), 1);
	int server_pid = ft_atoi(argv[1]);

	//? Properly copy the contents to a malloc'd message?
	send_message(server_pid, argv[2]);

	return (0);
}
