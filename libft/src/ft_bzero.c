/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 21:35:23 by rciera            #+#    #+#             */
/*   Updated: 2019/09/09 20:59:43 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *arr, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char*)arr;
	i = 0;
	while (i < n)
		tmp[i++] = '\0';
}
