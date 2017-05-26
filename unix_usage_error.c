/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_usage_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 12:27:13 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/26 12:34:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unix_usage_defs.h"
#include "printf.h"
#include <unistd.h>

void	print_option_error(const char *prog_name, const char option,
		enum e_error_code error)
{
	const char	*error_strings[] = {
		"%s: illegal option -- %c\n",
		"%s: option requires an argument -- %c\n"
	};

	ft_dprintf(STDERR_FILENO, error_strings[error], prog_name, option);
}
