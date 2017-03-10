/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_interface.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:23:37 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 17:46:08 by mgautier         ###   ########.fr       */
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
void			conversion_destroy(t_conversion *conversion);
t_bool			set_one_flag(const char *conv_string, int index,
		t_conversion *conv);
size_t	ft_arg_required(const void *conversion);
size_t	get_modifier(const t_conversion *conversion);
void			set_conversion_spec_len(t_conversion *conv, int index);
void			set_conversion_result_length(t_conversion *conv);

t_bool			is_signed_integer_conv(const t_conversion *conversion);
t_bool			is_unsigned_integer_conv(const t_conversion *conversion);
t_bool			is_ptr_conv(const t_conversion *conversion);
t_bool			is_string_conv(const t_conversion *conversion);
void			ft_conv_attribute_arg(t_conversion *conv, t_var_arg *arg_array);
void			ft_post_process_conv(t_conversion *conv);
void			ft_normalize_args(t_conversion *conv);

/*
** Functions not modifing the object
*/

int			ft_get_conv_len(const t_conversion *conv);
int			ft_write_conversion(char *to_write, const t_conversion *conv);
int			ft_get_conv_text_len(const t_conversion *conv);
size_t		bigger_arg_required(const t_conversion *conv);
char			*start_actual_conv(const char *global_start,
		const t_conversion *conv);
char			*empty_field_width(const char *global_start,
		const t_conversion *conv);
int				to_fill_field_width(const t_conversion *conv);

/*
** Others
*/
void			ft_write_field_width(char *to_write, int fill, char padding);

#endif
