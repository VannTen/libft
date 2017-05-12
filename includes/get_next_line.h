/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:23:03 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/17 16:04:19 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "bool_interface.h"
# include "lst_interface.h"

/*
** Constants definitions
*/

# define ONE_LINE_READ 1
# define READ_ERROR -1
# define FILE_IS_OVER 0
# define LINE_DELIMITER '\n'
# define BUFF_SIZE 100

/*
** Types definitions
*/

typedef struct	s_file_cache
{
	t_lst	*lines;
	t_bool	is_over;
	int		fd;
}				t_file_cache;

int				get_next_line(const int fd, char **line);
#endif
