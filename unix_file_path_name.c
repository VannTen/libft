/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_file_path_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 15:29:44 by mgautier          #+#    #+#             */
/*   Updated: 2017/10/09 18:59:47 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unix_files_defs.h"
#include "string_interface.h"

const char	*get_no_dir_part(char const *full_path_file)
{
	size_t	size;

	size = ft_strlen(full_path_file);
	while (full_path_file[size] != '/' && size != 0)
		size--;
	return (full_path_file + size);
}
