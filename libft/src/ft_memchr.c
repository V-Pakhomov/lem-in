/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:00:25 by rciera            #+#    #+#             */
/*   Updated: 2019/09/12 18:07:52 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char*)str;
	i = 0;
	while (i < n && tmp[i] != (unsigned char)c)
		i++;
	if (i < n)
		return (&tmp[i]);
	return (NULL);
}
