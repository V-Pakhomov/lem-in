/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:53:00 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:38:01 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

int		print_u(t_printf *pf, t_arg **arg)
{
	int no_err;

	no_err = 1;
	no_err &= unsigned_length_handler(pf, arg, 10);
	no_err &= set_precision(pf, arg);
	no_err &= set_field_width(pf, arg);
	(*arg)->out_len = ft_strlen((*arg)->out);
	return (no_err);
}
