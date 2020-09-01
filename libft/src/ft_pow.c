/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:11:26 by rciera            #+#    #+#             */
/*   Updated: 2019/10/24 15:59:50 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long	ft_pow(int n, int p)
{
	long long res;

	if (p == 0)
		return (1);
	res = ft_pow(n, p / 2);
	if (p % 2 == 0)
		return (res * res);
	else
		return (res * res * n);
}
