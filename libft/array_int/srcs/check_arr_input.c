/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arr_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:14:29 by Nik               #+#    #+#             */
/*   Updated: 2020/07/03 00:38:26 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array_int.h"

static int	is_number(char *s)
{
	if (*s == '-')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	if (s[0] == '-' && s[1] == 0)
		return (0);
	return (1);
}

int			check_arr_input(char *nbr)
{
	if (!is_number(nbr) || !ft_isinteger(nbr))
		return (1);
	return (0);
}
