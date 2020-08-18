/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:28:12 by vinograd          #+#    #+#             */
/*   Updated: 2020/06/21 13:34:22 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_unsigned(size_t nbr)
{
	char ch;
	char *str;

	str = NULL;
	if (nbr >= 10)
		str = ft_itoa_unsigned(nbr / 10);
	ch = nbr % 10 + '0';
	return (ft_stradd(str, ch));
}

char		*ft_itoa_long(long nbr)
{
	if (nbr < 0)
		return (ft_strjoin_free("-", ft_itoa_unsigned(-nbr), 2));
	else
		return (ft_itoa_unsigned(nbr));
}
