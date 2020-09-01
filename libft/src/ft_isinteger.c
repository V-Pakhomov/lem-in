/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:48:14 by Nik               #+#    #+#             */
/*   Updated: 2020/09/01 08:50:50 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_isinteger(char *nbr)
{
	long long num;

	if (!nbr || ft_strlen(nbr) > 11)
		return (0);
	num = ft_atoll(nbr);
	return (num <= (long)MAX_INT && num >= (long)MIN_INT);
}
