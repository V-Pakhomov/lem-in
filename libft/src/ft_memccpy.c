/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:05:21 by rciera            #+#    #+#             */
/*   Updated: 2019/09/13 20:03:34 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmpdst;
	unsigned char	*tmpsrc;

	tmpdst = (unsigned char*)dst;
	tmpsrc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		tmpdst[i] = tmpsrc[i];
		if (tmpdst[i] == (unsigned char)c)
			return (&tmpdst[i + 1]);
		i++;
	}
	return (NULL);
}
