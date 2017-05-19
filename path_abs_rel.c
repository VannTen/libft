/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_abs_rel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 12:34:17 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/19 10:59:36 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_defs.h"
#include "string_interface.h"
#include <stddef.h>

size_t	give_rel_path_from_abs(
		const char *path,
		const char *ref_current_dir)
{
	size_t		end_of_match;
	char		*slash_to_the_end;

	slash_to_the_end = ft_strjoin_ifnot(ref_current_dir, "/");
	end_of_match = is_substring_up_to(slash_to_the_end, path);
	ft_strdel(&slash_to_the_end);
	return (end_of_match);
}
