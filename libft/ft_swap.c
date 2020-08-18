/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:24:50 by vinograd          #+#    #+#             */
/*   Updated: 2020/06/21 13:37:55 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char *c1, char *c2)
{
	char ch;

	ch = *c1;
	*c1 = *c2;
	*c2 = ch;
}
