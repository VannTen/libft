/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_modifier_defs.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:03:56 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/22 11:06:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LENGTH_MODIFIER_DEFS_H
# define LENGTH_MODIFIER_DEFS_H

typedef enum	e_lenght_modifier
{
	NONE,
	SHORT,
	VERY_SHORT,
	LONG,
	VERY_LONG,
	MAX_INT,
	PTR_DIFF,
	SIZE,
	QUAD,
	LENGTH_MODIFIER_NBR
}			t_length_modifier;

const static char	g_length_modifier[] = "\0hHlLjtzq";
#endif
