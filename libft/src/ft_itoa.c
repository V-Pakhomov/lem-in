/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 19:45:02 by rciera            #+#    #+#             */
/*   Updated: 2020/08/01 13:08:13 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	get_str_size(long long num)
{
	size_t		len;
	long long	tmp;

	tmp = num;
	len = 1;
	tmp /= 10;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	len += 1 + (num < 0);
	return (len);
}

char			*ft_itoa(long long n)
{
	char	*num;
	int		sign;
	size_t	i;

	if (!(num = (char*)malloc(sizeof(char) * (get_str_size(n)))))
		return (NULL);
	if (n == 0)
	{
		num[0] = '0';
		num[1] = '\0';
		return (num);
	}
	sign = n < 0 ? -1 : 1;
	i = 0;
	while (n != 0)
	{
		num[i++] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		num[i++] = '-';
	num[i] = '\0';
	num = ft_strrev(num);
	return (num);
}
