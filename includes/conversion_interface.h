/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:23:37 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/21 11:05:15 by mgautier         ###   ########.fr       */
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
** Implementation files :
** ft_conversion_private_is_conv_numeric.c
** ft_conversion_private_is_conv.c
*/

t_bool			is_signed_integer_conv(const t_conversion *conversion);
t_bool			is_unsigned_integer_conv(const t_conversion *conversion);
t_bool			is_integer_conv(const t_conversion *conversion);
t_bool			is_numeric(const t_conversion *conv);

t_bool			is_ptr_conv(const t_conversion *conversion);
t_bool			is_string_conv(const t_conversion *conversion);
t_bool			is_no_conv(const t_conversion *conversion);
t_bool			is_char_conv(const t_conversion *conv);

/*
** Set conversion parameters and make various adjustements on them
** Implementation file : ft_conversion_private_set_parameters.c
*/

void			set_conversion_spec_len(t_conversion *conv, int index);
void			settle_incompatibilities(t_conversion *conv);
void			post_parsing_conv(t_conversion *conv);

/*
** Get conversion parameters
** Implementation file : ft_conversion_private_get_parameters.c
*/

size_t			get_modifier(const t_conversion *conversion);
int				ft_get_conv_len(const t_conversion *conv);
int				ft_get_conv_text_len(const t_conversion *conv);
int				ft_no_field_width_length(const t_conversion *conv);

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
** Get args index
** Implementation file : ft_conversion_private_args_index.c
*/

size_t			ft_arg_required(const void *conversion);
size_t			bigger_arg_required(const t_conversion *conv);
size_t			ft_precision_arg(const t_conversion *conv);
size_t			ft_field_width_arg(const t_conversion *conv);

/*
** Validity of arg index
*/

t_bool			ft_conversion_arg_is_valid(const t_conversion *conv);
t_bool			ft_precision_arg_is_valid(const t_conversion *conv);
t_bool			ft_field_width_arg_is_valid(const t_conversion *conv);

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

int				ft_write_conversion(char *to_write, const t_conversion *conv);

/*
** Compute positions for write functions
** Implementation file : ft_conversion_private_positions_write.c
*/

char			*start_of_conv_is(const char *global_start,
		const t_conversion *conv);
char			*start_of_field_width_is(const char *global_start,
		const t_conversion *conv);

/*
** Functions selectors for len and write
** Implementation file : ft_conversion_private_function_selectors.c
*/

int				ft_get_len_conv(const t_conversion *conv);
void			ft_select_writer_conv(char *to_write, const t_conversion *conv);

/*
** Specifics for integer conversion (length)
** Implementation file : ft_conversion_private_integer_length.c
*/

int				set_integer_length(t_conversion *conv);
int				count_signedness(const t_conversion *conv);
int				count_alternate_form(const t_conversion *conv);

/*
** Specifis for integer conversion (write)
** Implementaton file : ft_conversion_private_integer_write.c
*/

int				ft_write_integer_conv(char *to_write, const t_conversion *conv);
t_bool			has_alternate_form_hexa(const t_conversion *conv);

#endif
