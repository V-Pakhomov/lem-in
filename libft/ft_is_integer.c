/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:48:14 by Nik               #+#    #+#             */
/*   Updated: 2020/06/21 13:33:48 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int		ft_isinteger(char *nbr)
{
	long num;

	if (!nbr || ft_strlen(nbr) > 11)
		return (0);
	num = ft_atoi_long(nbr);
	return (num <= (long)INT_MAX && num >= (long)INT_MIN);
}
