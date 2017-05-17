/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_abs_rel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 12:34:17 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/17 12:40:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_defs.h"
#include "string_interface.h"
#include <stddef.h>

const char	*give_rel_path_from_abs(
		const char *path,
		const char *ref_current_dir)
{
	size_t		end_of_match;
	char		*slash_to_the_end;
	const char	*rel_path;

	slash_to_the_end = ft_strjoin_ifnot(ref_current_dir, "/");
	end_of_match = is_substring_up_to(slash_to_the_end, path);
	if (end_of_match != 0)
		rel_path = path + end_of_match;
	else
		rel_path = NULL;
	ft_strdel(&slash_to_the_end);
	return (rel_path);
}
