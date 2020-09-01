/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:23:41 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:35 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

static int	function_num(t_printf *pf, t_arg *arg)
{
	int res;

	if (ft_strchr(pf->all_conversions, arg->conversion) == NULL)
		return (0);
	res = ft_strchr(pf->all_conversions, arg->conversion) - pf->all_conversions;
	return (res);
}

int			print_all(t_printf *pf)
{
	t_arg	*arg;
	int		num;

	arg = pf->args;
	while (arg != NULL)
	{
		if (arg->arg[0] != '%')
		{
			arg = arg->next;
			continue ;
		}
		num = function_num(pf, arg);
		if (!pf->function[num](pf, &arg))
			return (0);
		arg = arg->next;
	}
	pf->return_value = 0;
	arg = pf->args;
	while (arg != NULL)
	{
		write(1, arg->out, arg->out_len);
		pf->return_value += arg->out_len;
		arg = arg->next;
	}
	return (1);
}
