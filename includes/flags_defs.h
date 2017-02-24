/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_defs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:16:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/02/24 12:23:41 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_DEFS_H
# define FLAGS_DEFS_H

enum	e_flags
{
	ALTERNATE_FORM,
	ZERO_PADDING,
	NEGATIVE_FIELD_WIDTH,
	BLANK,
	ALWAYS_SIGN,
	THOUSANDS_SEP,
	FLAGS_NBR
};

static const char g_flags[] = "#0- +'";
#endif
