/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:20:09 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/11 15:28:49 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include <sys/stat.h>

t_bool	is_dir(const char *path)
{
	struct stat	file_infos;

	stat(path, &file_infos);
	return (S_ISDIR(file_infos.st_mode) != 0);
}
