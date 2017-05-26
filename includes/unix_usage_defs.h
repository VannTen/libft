/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_usage_defs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:42:18 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/26 12:30:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIX_USAGE_DEFS_H
# define UNIX_USAGE_DEFS_H
# include "unix_usage_interface.h"
# include <stddef.h>
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

enum	e_error_code
{
	ILLEGAL_OPTION,
	REQ_ARG,
};

/*
** Internal functions
** Implementation file : ft_unix_usage_param_opt.c
*/

int		apply_arg_opt(
		const size_t opt_char_index,
		const char **argv,
		const t_synopsis *syn,
		void *params);
int		apply_no_arg_opt(
		const char opt_char,
		const t_synopsis *syn,
		void *params);

/*
** Internal error function
** Implementation file : unix_usage_error.c
*/

void	print_option_error(const char *prog_name, const char option,
		enum e_error_code error);

#endif
