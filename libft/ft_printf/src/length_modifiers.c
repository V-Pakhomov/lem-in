/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:05:00 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:28 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

int			unsigned_length_handler(t_printf *pf, t_arg **arg, int base)
{
	unsigned long long num;

	if (ft_strcmp((*arg)->length_modifier, "hh") == 0)
		num = (unsigned char)va_arg(pf->ap, unsigned int);
	else if (ft_strcmp((*arg)->length_modifier, "h") == 0)
		num = (unsigned short)va_arg(pf->ap, unsigned int);
	else if (ft_strcmp((*arg)->length_modifier, "ll") == 0)
		num = (unsigned long long)va_arg(pf->ap, unsigned long long);
	else if (ft_strcmp((*arg)->length_modifier, "l") == 0)
		num = (unsigned long)va_arg(pf->ap, unsigned long);
	else
		num = (unsigned int)va_arg(pf->ap, unsigned int);
	if (num == 0 && (*arg)->precision == 0)
		(*arg)->out = ft_strdup("");
	else
		(*arg)->out = ft_itoa_base(num, base);
	if (!(*arg)->out)
		return (error(pf));
	return (1);
}

static int	int_length_modifiers(t_arg **arg)
{
	int i;

	i = ft_strlen((*arg)->arg) - 2;
	while (i > 0)
	{
		if ((*arg)->arg[i] == 'h' && (*arg)->arg[i - 1] == 'h')
			(*arg)->length_modifier = ft_strdup("hh");
		else if ((*arg)->arg[i] == 'h')
			(*arg)->length_modifier = ft_strdup("h");
		else if ((*arg)->arg[i] == 'l' && (*arg)->arg[i - 1] == 'l')
			(*arg)->length_modifier = ft_strdup("ll");
		else if ((*arg)->arg[i] == 'l')
			(*arg)->length_modifier = ft_strdup("l");
		else
		{
			i--;
			continue;
		}
		if (!(*arg)->length_modifier)
			return (0);
		return (1);
	}
	if (!((*arg)->length_modifier = ft_strdup("")))
		return (0);
	return (1);
}

static int	float_length_modifiers(t_arg **arg)
{
	int i;

	i = ft_strlen((*arg)->arg) - 2;
	while (i > 0)
	{
		if ((*arg)->arg[i] == 'l')
			(*arg)->length_modifier = ft_strdup("l");
		else if ((*arg)->conversion == 'f' && (*arg)->arg[i] == 'L')
			(*arg)->length_modifier = ft_strdup("L");
		else
		{
			i--;
			continue;
		}
		if (!(*arg)->length_modifier)
			return (0);
		return (1);
	}
	if (!((*arg)->length_modifier = ft_strdup("")))
		return (0);
	return (1);
}

int			check_length_modifiers(t_arg **arg)
{
	if (ft_strchr("diouxX", (*arg)->conversion))
		return (int_length_modifiers(arg));
	else if ((*arg)->conversion == 'f')
		return (float_length_modifiers(arg));
	return (1);
}
