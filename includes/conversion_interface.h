/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:23:37 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/03 15:24:19 by mgautier         ###   ########.fr       */
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

t_conversion	*conversion_ctor(void);
void			*conversion_dtor(t_conversion *conversion);
size_t			set_positional_arg(const char *conversion_specifier,
		size_t index, t_conversion *convers_specs);
t_bool			set_one_flag(const char *conv_string, size_t index,
		t_conversion *conv);
unsigned int	ft_arg_required(const void *conversion);
unsigned int	get_modifier(const t_conversion *conversion);
void			set_conversion_spec_len(t_conversion *conv, size_t index);
void			set_conversion_result_length(t_conversion *conv);

t_bool			is_signed_integer_conv(const t_conversion *conversion);
t_bool			is_unsigned_integer_conv(const t_conversion *conversion);
t_bool			is_ptr_conv(const t_conversion *conversion);
t_bool			is_string_conv(const t_conversion *conversion);
void			ft_conv_attribute_arg(t_conversion *conv, t_var_arg *arg_array);

/*
** Functions not modifing the object
*/

size_t			ft_get_conv_len(const t_conversion *conv);
size_t			ft_write_conversion(char *to_write, const t_conversion *conv);
size_t			ft_get_conv_text_len(const t_conversion *conv);
int				bigger_arg_required(const t_conversion *conv);

/*
** Others
*/

#endif
