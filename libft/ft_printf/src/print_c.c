/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:53:57 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:37 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

static int	eol_handler(t_printf *pf, t_arg **arg)
{
	(*arg)->out_len = ft_max(1, (*arg)->field_width);
	if ((*arg)->field_width)
	{
		if (!(set_field_width(pf, arg)))
			return (error(pf));
		if ((*arg)->flags.minus)
			(*arg)->out[0] = '\0';
		else
			(*arg)->out[(*arg)->field_width - 1] = 0;
	}
	return (1);
}

int			print_c(t_printf *pf, t_arg **arg)
{
	if ((*arg)->out == NULL)
	{
		if (!((*arg)->out = (char *)malloc(2 * sizeof(char))))
			return (error(pf));
		(*arg)->out[1] = '\0';
		(*arg)->out[0] = (unsigned char)va_arg(pf->ap, int);
	}
	if (!(*arg)->out[0])
		return (eol_handler(pf, arg));
	if (!set_field_width(pf, arg))
		return (error(pf));
	(*arg)->out_len = ft_strlen((*arg)->out);
	return (1);
}
