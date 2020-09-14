/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 17:08:58 by rciera            #+#    #+#             */
/*   Updated: 2020/09/14 17:40:36 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arrsize(char **arr)
{
	int size;

	if (arr == NULL)
		return (0);
	size = 0;
	while (arr[size] != 0)
		size++;
	return (size);
}
