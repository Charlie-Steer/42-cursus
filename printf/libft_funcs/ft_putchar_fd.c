/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:44:04 by cargonz2          #+#    #+#             */
/*   Updated: 2024/08/07 17:19:21 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	int written_bytes;

	written_bytes = write(fd, &c, 1);
	return (written_bytes);
}
