/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string_interface.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:10:08 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/01 15:22:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_STRING_INTERFACE_H
# define FORMAT_STRING_INTERFACE_H
# include "conversion_interface.h"
# include "bool.h"

struct s_format_string;
typedef struct s_format_string	t_format_string;

/*
** Functions acting on the internal of the object
*/

t_format_string	*ft_format_string_parser(const char *string);
int				ft_request_arg(t_format_string *format);
t_bool			f_add_conv_to_fmt(t_format_string *fmt, t_conversion *conv,
		size_t index);
t_format_string	*fmt_ctor(void);
void			fmt_dtor(t_format_string *to_destroy);
void			set_fmt_length(t_format_string *fmt, size_t length);

/*
** Functions accessing but not modifing the object
*/

size_t			ft_fmt_plain_text_len(const t_format_string *fmt);
size_t			ft_conversions_length(const t_format_string *fmt);
size_t			ft_get_current_conv_text_len(t_format_string *fmt);

/*
** Others functions
*/

size_t			ft_add_conversion(const char *conv_text, t_format_string *fmt);
size_t			ft_get_resulting_length(const t_format_string *fmt);
void			ft_write_result_string(const char *fmt, char *final_string,
		t_format_string *fmt_tokens);
size_t			ft_write_next_conversion(char *to_write, t_format_string *fmt);
#endif
