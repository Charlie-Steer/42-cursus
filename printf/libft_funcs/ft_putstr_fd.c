/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:03:30 by cargonz2          #+#    #+#             */
/*   Updated: 2024/08/07 17:08:18 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int written_bytes;

	written_bytes = write(fd, s, ft_strlen(s));
	return (written_bytes);
}
