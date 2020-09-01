/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:50:46 by rciera            #+#    #+#             */
/*   Updated: 2019/09/10 21:16:21 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *destptr;
	unsigned char *srcptr;

	if (!dest && !src)
		return (NULL);
	destptr = (unsigned char*)dest;
	srcptr = (unsigned char*)src;
	while (n > 0)
	{
		*destptr = *srcptr;
		destptr++;
		srcptr++;
		n--;
	}
	return (dest);
}
