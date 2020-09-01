/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 11:24:02 by rciera            #+#    #+#             */
/*   Updated: 2020/03/06 17:58:33 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	get_str_size(size_t num, size_t base)
{
	size_t len;

	len = 1;
	num /= base;
	while (num)
	{
		len++;
		num /= base;
	}
	return (len + 1);
}

char			*ft_itoa_base(size_t num, size_t base)
{
	char	*res;
	int		i;
	int		mod;

	if (!num)
	{
		res = ft_strdup("0");
		return (res);
	}
	if (!(res = (char *)malloc(get_str_size(num, base) * sizeof(char))))
		return (NULL);
	i = 0;
	while (num)
	{
		mod = num % base;
		if (mod >= 10)
			res[i++] = 'a' + mod - 10;
		else
			res[i++] = '0' + mod;
		num /= base;
	}
	res[i] = '\0';
	ft_strrev(res);
	return (res);
}
