/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidden.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rciera <rciera@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:31:53 by rciera            #+#    #+#             */
/*   Updated: 2020/08/06 19:19:45 by rciera           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIDDEN_H
# define HIDDEN_H

# include "ft_printf.h"

typedef struct	s_flags
{
	int space;
	int zero;
	int plus;
	int minus;
	int number_sign;
}				t_flags;

typedef struct	s_arg
{
	char			*out;
	char			*arg;
	int				out_len;
	int				field_width;
	int				precision;
	t_flags			flags;
	char			*length_modifier;
	int				is_num;
	char			conversion;
	struct s_arg	*next;
}				t_arg;

typedef struct	s_printf
{
	t_arg	*args;
	va_list	ap;
	int		return_value;
	int		err;
	int		(*function[11])(struct s_printf *pf, t_arg **arg);
	char	*all_conversions;
}				t_printf;

/*
** format_parser.c
*/
int				parse_format(t_printf *printf, char *format);

/*
** arg_functions.c
*/
t_arg			*new_arg(t_printf *pf, char *arg);
int				push_back_arg(t_arg **args, t_arg *new_arg);

/*
** lengt_modifiers.c
*/
int				check_length_modifiers(t_arg **arg);
int				unsigned_length_handler(t_printf *pf, t_arg **arg, int base);

/*
** flag_managment.c
*/
int				add_plus_flag(t_printf *pf, t_arg **arg);
int				add_space_flag(t_printf *pf, t_arg **arg);
void			check_flags(t_arg **arg);

/*
** field_width.c
*/
int				set_field_width(t_printf *pf, t_arg **arg);
void			get_field_width(t_arg **arg);

/*
** precision.c
*/
int				set_precision(t_printf *pf, t_arg **arg);
void			get_precision(t_arg **arg);

/*
** skips.c
*/
void			skip_digits(char *str, int *i);
void			skip_precicison_part(int *i, char *arg);

/*
** error.c
*/
int				error(t_printf *pf);
void			*null_error(t_printf *pf);

/*
** print_all.c
*/
int				print_all(t_printf *pf);

/*
** print_di.c
*/
int				print_di(t_printf *pf, t_arg **arg);

/*
** print_o.c
*/
int				print_o(t_printf *pf, t_arg **arg);

/*
** print_u.c
*/
int				print_u(t_printf *pf, t_arg **arg);

/*
** print_x.c
*/
int				print_x(t_printf *pf, t_arg **arg);

/*
** print_f.c
*/
int				print_f(t_printf *pf, t_arg **arg);

/*
** ft_dtoa.c
*/
char			*ft_dtoa(t_printf *pf, t_arg **arg, long double db);

/*
** nan_inf.c
*/
int				nan_inf(t_printf *pf, t_arg **arg, long double db);

/*
** print_c.c
*/
int				print_c(t_printf *pf, t_arg **arg);

/*
** print_s.c
*/
int				print_s(t_printf *pf, t_arg **arg);

/*
** print_p.c
*/
int				print_p(t_printf *pf, t_arg **arg);

/*
** functions_pts.c
*/
void			create_array_of_functions_pts(t_printf *pf);

/*
** free_all.c
*/
void			free_all(t_printf *pf);

#endif
