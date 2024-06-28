/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charlie.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:38:20 by cargonz2          #+#    #+#             */
/*   Updated: 2024/06/28 16:38:22 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int		ft_numlen_base(long num, char *base, int account_sign);
char	*ft_itoa_base(unsigned long n, char *base);
int		ft_numlen(long num, int account_sign);
long	ft_pow(long base, long exp);
