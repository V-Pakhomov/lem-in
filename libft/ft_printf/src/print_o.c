/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:44:05 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:46 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

int		print_o(t_printf *pf, t_arg **arg)
{
	int no_err;

	no_err = 1;
	no_err &= unsigned_length_handler(pf, arg, 8);
	if ((*arg)->out[0] != '0' && (*arg)->flags.number_sign)
		(*arg)->precision = ft_max(ft_strlen((*arg)->out) + 1,
											(*arg)->precision);
	no_err &= set_precision(pf, arg);
	no_err &= set_field_width(pf, arg);
	(*arg)->out_len = ft_strlen((*arg)->out);
	return (no_err);
}
