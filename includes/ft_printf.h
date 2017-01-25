/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 15:58:40 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/25 18:31:33 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "bool.h"

struct			s_flags
{
	t_bool	alternate_form;
	t_bool	zero_padding;
	t_bool	inverse_padding;
	t_bool	blank_before_signed;
	t_bool	explicit_signed;
	t_bool	thousands_grouping;
};

typedef struct	s_conversion
{
	struct s_flags		flags;
	unsigned int		arg_index;
	int					field_width;
	int					precision;
	short				length_modifier;
	int					(*convert_count)(struct conversion *self);
	char				*(*convert)(struct conversion *self);
}				t_conversion;

#endif
