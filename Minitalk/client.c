/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:37:03 by cargonz2          #+#    #+#             */
/*   Updated: 2024/10/04 14:18:43 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_message(int server_pid, char *message, int message_len)
{
	unsigned char	bit_value;
	unsigned char	mask;
	int				char_index;
	int				bit_index;

	bit_value = 0;
	mask = 128;
	char_index = 0;
	bit_index = 0;
	while (char_index < message_len)
	{
		while (bit_index < 8)
		{
			bit_value = (unsigned char)(message[char_index]) & mask;
			if (bit_value == 0)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			message[char_index] <<= 1;
			bit_index++;
			usleep(500);
		}
		bit_index = 0;
		char_index++;
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		message_len;
	int		server_pid;

	if (argc != 3)
		return (ft_printf("Error: Invalid argument count.\n"), 1);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	message_len = ft_strlen(message);
	send_message(server_pid, message, message_len);
	return (0);
}
