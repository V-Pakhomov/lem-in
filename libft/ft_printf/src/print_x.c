/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:44:23 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:55 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

static int	x_precision(t_printf *pf, t_arg **arg)
{
	char *tmp_out;

	tmp_out = ft_strjoin("0x", (*arg)->out);
	if (!tmp_out)
		return (error(pf));
	free((*arg)->out);
	(*arg)->out = tmp_out;
	return (1);
}

static void	to_x_upper(t_arg **arg)
{
	int len;
	int i;

	len = ft_strlen((*arg)->out);
	i = 0;
	while (i < len)
	{
		(*arg)->out[i] = ft_toupper((*arg)->out[i]);
		i++;
	}
}

static int	number_sign_handler(t_printf *pf, t_arg **arg)
{
	int no_err;

	no_err = 1;
	if ((*arg)->flags.zero)
	{
		(*arg)->field_width -= 2;
		no_err &= set_field_width(pf, arg);
		no_err &= x_precision(pf, arg);
	}
	else
	{
		no_err &= x_precision(pf, arg);
		no_err &= set_field_width(pf, arg);
	}
	return (no_err);
}

int			print_x(t_printf *pf, t_arg **arg)
{
	int no_err;
	int double_zero;

	no_err = 1;
	no_err &= unsigned_length_handler(pf, arg, 16);
	double_zero = !ft_strlen((*arg)->out) | ((*arg)->out[0] == '0');
	no_err &= set_precision(pf, arg);
	if (!double_zero && (*arg)->flags.number_sign)
		no_err &= number_sign_handler(pf, arg);
	else
		no_err &= set_field_width(pf, arg);
	if ((*arg)->conversion == 'X')
		to_x_upper(arg);
	(*arg)->out_len = ft_strlen((*arg)->out);
	return (no_err);
}
