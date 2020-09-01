/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:44:46 by rciera            #+#    #+#             */
/*   Updated: 2019/09/10 21:29:29 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*tmpdest;
	unsigned char	*tmpsrc;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	tmpdest = (unsigned char*)dst;
	tmpsrc = (unsigned char*)src;
	if (tmpdest > tmpsrc)
	{
		i = len;
		while (i-- != 0)
			tmpdest[i] = tmpsrc[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			tmpdest[i] = tmpsrc[i];
			i++;
		}
	}
	return (dst);
}
