/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 12:21:29 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:02 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

static int	is_conversion(char c)
{
	if (ft_strchr("%cspdiouxXf", c) == NULL)
		return (0);
	return (1);
}

static int	create_arg_out(t_arg **new_arg, char *arg)
{
	int arg_len;

	arg_len = ft_strlen(arg);
	if (arg[0] != '%')
	{
		(*new_arg)->out = ft_strdup(arg);
		(*new_arg)->out_len = arg_len;
		(*new_arg)->is_num = 0;
		return ((*new_arg)->out != NULL);
	}
	(*new_arg)->conversion = arg[arg_len - 1];
	if (!is_conversion((*new_arg)->conversion) || (*new_arg)->conversion == '%')
	{
		(*new_arg)->out = ft_strdup(arg + arg_len - 1);
		if (!(*new_arg)->out)
			return (0);
	}
	else
		(*new_arg)->out = NULL;
	return (1);
}

t_arg		*new_arg(t_printf *pf, char *arg)
{
	t_arg *new_arg;

	if (!(new_arg = (t_arg *)malloc(sizeof(t_arg))))
		return (null_error(pf));
	new_arg->next = NULL;
	new_arg->arg = ft_strdup(arg);
	if (!new_arg->arg)
		return (null_error(pf));
	if (!(create_arg_out(&new_arg, arg)))
		return (null_error(pf));
	if (arg[0] != '%')
		return (new_arg);
	new_arg->is_num = (ft_strchr("diouxXf", new_arg->conversion) ? 1 : 0);
	new_arg->length_modifier = NULL;
	if (!check_length_modifiers(&new_arg))
	{
		free(new_arg);
		return (null_error(pf));
	}
	get_precision(&new_arg);
	get_field_width(&new_arg);
	check_flags(&new_arg);
	return (new_arg);
}

int			push_back_arg(t_arg **args, t_arg *new_arg)
{
	t_arg *tmp;

	if (new_arg == NULL)
		return (0);
	if (*args == NULL)
	{
		*args = new_arg;
		return (1);
	}
	tmp = *args;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_arg;
	return (1);
}
