/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_pts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:36:49 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 18:37:25 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hidden.h"

/*
** % c s p d i o u x X f
** 0 1 2 3 4 5 6 7 8 9 10
*/

void	create_array_of_functions_pts(t_printf *pf)
{
	pf->function[0] = print_c;
	pf->function[1] = print_c;
	pf->function[2] = print_s;
	pf->function[3] = print_p;
	pf->function[4] = print_di;
	pf->function[5] = print_di;
	pf->function[6] = print_o;
	pf->function[7] = print_u;
	pf->function[8] = print_x;
	pf->function[9] = print_x;
	pf->function[10] = print_f;
}
