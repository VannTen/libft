/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_specifier.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:03:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/31 19:08:08 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSION_SPECIFIER_H
# define FT_CONVERSION_SPECIFIER_H
# define PRECISION_INDICATOR '.'

enum	e_lenght_modifier
{
	SHORT,
	VERY_SHORT,
	LONG,
	VERY_LONG,
	MAX_INT,
	PTR_DIFF,
	SIZE,
	QUAD,
	LENGTH_MODIFIER_NBR
};

const static char	g_length_modifier[] = "hHlLjtzq";
#endif
