/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:23:37 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/14 17:07:26 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_INTERFACE_H
# define CONVERSION_INTERFACE_H
# include "bool.h"
# include "variadic_args_interface.h"
# include <stdlib.h>

struct s_conversion;
typedef struct s_conversion	t_conversion;

/*
** Functions accessing the struc
*/

/*
** Ressource handling
** Implementation file : ft_conversion_private_ressources.c
*/

t_conversion	*conversion_ctor(void);
void			conversion_destroy(t_conversion *conversion);

/*
** Determine conversion type
** Implementation file : ft_conversion_private_is_conv.c
*/


t_bool			is_signed_integer_conv(const t_conversion *conversion);
t_bool			is_unsigned_integer_conv(const t_conversion *conversion);
t_bool			is_ptr_conv(const t_conversion *conversion);
t_bool			is_string_conv(const t_conversion *conversion);

/*
** Set conversion parameters
** Implementation file : ft_conversion_private_set_parameters.c
*/

void			set_conversion_spec_len(t_conversion *conv, int index);

/*
** Flags handlings
** Implementation file : ft_flags.c
*/

int				ft_write_flags(char *to_write, const t_conversion *conv);
int				ft_flags_len(const t_conversion *conv);
int				set_flags(const char *conversion_specifier,
		t_conversion *convers_specs);

/*
** Set conversion's final length
** Implementation file : ft_conversion_private_set_final_length.c
*/

void			set_final_conversion_length(t_conversion *conv);

/*
** Get conversion parmeters
** Implementation file : ft_conversion_private_get_parameters.c
*/

size_t			get_modifier(const t_conversion *conversion);
int				ft_get_conv_len(const t_conversion *conv);
int				ft_get_conv_text_len(const t_conversion *conv);

/*
** Get args index
** Implementation file : ft_conversion_private_args_index.c
*/

size_t			ft_arg_required(const void *conversion);
size_t			bigger_arg_required(const t_conversion *conv);
size_t			ft_precision_arg(const t_conversion *conv);
size_t			ft_field_width_arg(const t_conversion *conv);

/*
** Set conversion variadic arguments
** Implementation file : ft_conversion_private_set_var_args.c
*/

void			ft_conv_attribute_arg(t_conversion *conv, t_var_arg *arg_array);
void			ft_normalize_args(t_conversion *conv);

/*
** Write conversion
** Implementation file : ft_conversion_private_write.c
*/

int			ft_write_conversion(char *to_write, const t_conversion *conv);

/* Static functions for now
void		ft_write_field_width(char *to_write, int fill, char padding);
char			*start_actual_conv(const char *global_start,
		const t_conversion *conv);
char			*empty_field_width(const char *global_start,
		const t_conversion *conv);
int				to_fill_field_width(const t_conversion *conv);
*/

/*
** Others
*/

#endif
