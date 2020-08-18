/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:11:09 by vinograd          #+#    #+#             */
/*   Updated: 2020/06/21 13:35:20 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *p_dst;
	unsigned char *p_src;

	p_dst = (unsigned char*)dst;
	p_src = (unsigned char*)src;
	if (dst >= src)
		while (len--)
			p_dst[len] = p_src[len];
	else
		while (len--)
		{
			*p_dst = *p_src;
			p_src++;
			p_dst++;
		}
	return (dst);
}
