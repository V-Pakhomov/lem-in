/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:24:50 by vinograd          #+#    #+#             */
/*   Updated: 2020/06/21 13:37:58 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swapi(int *c1, int *c2)
{
	int n;

	n = *c1;
	*c1 = *c2;
	*c2 = n;
}
