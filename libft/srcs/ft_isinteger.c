/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:48:14 by Nik               #+#    #+#             */
/*   Updated: 2020/09/06 16:16:00 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isinteger(char *nbr)
{
	long long num;

	if (!nbr || ft_strlen(nbr) > 11 || !ft_isnum(nbr))
		return (0);
	num = ft_atoll(nbr);
	return (num <= (long)MAX_INT && num >= (long)MIN_INT);
}
