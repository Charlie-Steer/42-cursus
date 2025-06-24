/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cargonz2 <cargonz2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:46:31 by cargonz2          #+#    #+#             */
/*   Updated: 2025/06/24 17:47:42 by cargonz2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

bool	are_arguments_valid(int argc, char *argv[]);
bool	check_if_arguments_are_valid(int argc, char *argv[]);
bool	check_if_positive_number(char *str);

#endif
