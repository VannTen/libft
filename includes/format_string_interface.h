/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string_interface.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:10:08 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/20 13:49:47 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_STRING_INTERFACE_H
# define FORMAT_STRING_INTERFACE_H
# include "conversion_interface.h"
# include "bool.h"

struct s_format_string;
typedef struct s_format_string	t_format_string;

/*
** Get length
** Implementation file : ft_format_string_private_get_length.c
*/

int				ft_fmt_plain_text_len(const t_format_string *fmt);
int				ft_conversions_length(const t_format_string *fmt);
int				ft_get_current_conv_text_len(t_format_string *fmt);

/*
** Request arg from conversion list
** Implementation file : ft_format_string_private_request_args.c
*/

void			ft_attributes_var_args(t_format_string *fmt);
void			ft_get_var_args(t_format_string *fmt, va_list *var_arg_list);

/*
** Counting arg index on parsing
** Implementation file : ft_format_string_private_arg_index.c
*/

size_t			ft_get_next_arg_index(t_format_string *format);
/*
** Functions acting on the internal of the object
*/

t_format_string	*ft_format_string_parser(const char *string);
t_bool			f_add_conv_to_fmt(t_format_string *fmt, t_conversion *conv,
		int index);
t_format_string	*fmt_ctor(void);
void			fmt_destroy(t_format_string *to_destroy);
void			set_fmt_length(t_format_string *fmt, int length);
void			ft_compute_convs_length(t_format_string *fmt);

/*
** Functions accessing but not modifing the object
*/

/*
** Others functions
*/

int				ft_add_conversion(const char *conv_text, t_format_string *fmt);
int				ft_get_resulting_length(const t_format_string *fmt);
void			ft_write_result_string(const char *fmt_src, char *final_string,
		t_format_string *fmt);
t_bool			ft_write_next_conv(const char **fmt_src, char **to_write,
		t_conversion *conv);
t_format_string	*ft_full_fmt(const char *base_text, va_list *var_args);
#endif
