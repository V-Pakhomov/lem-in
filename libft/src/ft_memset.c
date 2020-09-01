/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:07:39 by rciera            #+#    #+#             */
/*   Updated: 2019/09/09 20:59:23 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	arr = (unsigned char*)dest;
	i = 0;
	while (i < n)
	{
		arr[i] = (unsigned char)c;
		i++;
	}
	return (arr);
}
