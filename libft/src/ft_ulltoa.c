/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:06:00 by rciera            #+#    #+#             */
/*   Updated: 2020/08/01 13:07:08 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	get_str_size(unsigned long long num)
{
	size_t				len;
	unsigned long long	tmp;

	tmp = num;
	len = 1;
	tmp /= 10;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	len += 1;
	return (len);
}

char			*ft_ulltoa(unsigned long long n)
{
	char	*num;
	size_t	i;

	if (!(num = (char*)malloc(sizeof(char) * (get_str_size(n)))))
		return (NULL);
	if (n == 0)
	{
		num[0] = '0';
		num[1] = '\0';
		return (num);
	}
	i = 0;
	while (n != 0)
	{
		num[i++] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	num[i] = '\0';
	num = ft_strrev(num);
	return (num);
}
