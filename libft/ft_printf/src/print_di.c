/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:43:52 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:39 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

static int	length_handler(t_printf *pf, t_arg **arg)
{
	long long num;

	if (ft_strcmp((*arg)->length_modifier, "hh") == 0)
		num = (signed char)va_arg(pf->ap, int);
	else if (ft_strcmp((*arg)->length_modifier, "h") == 0)
		num = (short)va_arg(pf->ap, int);
	else if (ft_strcmp((*arg)->length_modifier, "ll") == 0)
		num = (long long)va_arg(pf->ap, long long);
	else if (ft_strcmp((*arg)->length_modifier, "l") == 0)
		num = (long)va_arg(pf->ap, long);
	else
		num = (int)va_arg(pf->ap, int);
	if (num < 0)
		(*arg)->flags.space = 0;
	if (num == 0 && (*arg)->precision == 0)
		(*arg)->out = ft_strdup("");
	else
		(*arg)->out = ft_itoa(num);
	if (!(*arg)->out)
		return (error(pf));
	return (1);
}

int			print_di(t_printf *pf, t_arg **arg)
{
	int no_err;

	no_err = 1;
	no_err &= length_handler(pf, arg);
	if ((*arg)->flags.plus)
		no_err &= add_plus_flag(pf, arg);
	no_err &= set_precision(pf, arg);
	if ((*arg)->flags.space)
	{
		if ((*arg)->flags.minus)
		{
			no_err &= add_space_flag(pf, arg);
			no_err &= set_field_width(pf, arg);
		}
		else
		{
			no_err &= set_field_width(pf, arg);
			no_err &= add_space_flag(pf, arg);
		}
	}
	else
		no_err &= set_field_width(pf, arg);
	(*arg)->out_len = ft_strlen((*arg)->out);
	return (no_err);
}
