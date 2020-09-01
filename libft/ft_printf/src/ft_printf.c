/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:43:53 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:21 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

static int	default_printf(t_printf *pf)
{
	create_array_of_functions_pts(pf);
	pf->all_conversions = ft_strdup("%cspdiouxXf");
	if (!pf->all_conversions)
	{
		free(pf->args);
		return (error(pf));
	}
	return (1);
}

int			ft_printf(char *format, ...)
{
	t_printf pf;

	pf.err = 0;
	if (!default_printf(&pf))
		return (-1);
	pf.args = NULL;
	parse_format(&pf, format);
	if (pf.err)
		return (-1);
	va_start(pf.ap, format);
	print_all(&pf);
	va_end(pf.ap);
	if (pf.err)
		return (-1);
	free_all(&pf);
	return (pf.return_value);
}
