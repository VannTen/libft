/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_usage_defs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:42:18 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/03 15:15:59 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIX_USAGE_DEFS_H
# define UNIX_USAGE_DEFS_H
# include "unix_usage_interface.h"
# define OPTION_CHARACTER '-'
# define INVALID_OPTION -1

struct	s_synopsis
{
	const char				*prog_name;
	const char				*options_char;
	const char				*options_param_char;
	const t_apply_opt		*options;
	const t_apply_opt_param	*options_param;
	t_bool					(*is_valid)(int);
	void					(*usage)(const char*);
};

enum	e_opt_return
{
	INVALID,
	NOTHING_CONSUMED,
	CURRENT_CONSUMED,
	NEXT_CONSUMED
};

#endif
