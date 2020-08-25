/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:23:16 by rciera            #+#    #+#             */
/*   Updated: 2020/08/25 18:46:25 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/libft.h"
# include "ft_queue.h"

typedef struct	s_lemin
{
	int		ants_num;
	int		vertices;
	char	**rooms;
	int		**adj_matrix;
	int		*used;
	int		*parent;
}				t_lemin;

#endif