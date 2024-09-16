/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:37:03 by cargonz2          #+#    #+#             */
/*   Updated: 2024/09/16 20:55:49 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	//! Seems like we have to handle argv[i] possibly not existing.
	//! Otherwise a segmentation fault happens.
	int server_pid = atoi(argv[1]); //! CAREFUL! Non-ft atoi.
	kill(server_pid, SIGUSR1);

	return (0);
}
