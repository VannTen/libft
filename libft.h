/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:51:07 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 15:28:12 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "includes/usual_macros.h"
# include "includes/btree_interface.h"
# include "includes/fifo_interface.h"
# include "includes/lst_interface.h"
# include "includes/bool_interface.h"
# include "includes/list.h"
# include "includes/printf.h"
# include "includes/unix_usage_interface.h"
# include "includes/itoa_tools.h"
# include "includes/get_next_line.h"
# include "includes/unix_files_interface.h"
# include "includes/path_interface.h"
# include "includes/string_interface.h"
# include "includes/string_array_interface.h"
# include "includes/stdout_interface.h"
# include "includes/convert_interface.h"
# include "includes/mem_interface.h"
# include "includes/issomething_interface.h"
# include "includes/misc_interface.h"
# include "includes/math_interface.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_add_end_list(t_list *last_link, const void *content,
									size_t content_size);
unsigned int		ft_lstcheck(t_list *list, t_bool (*f)(t_list *elem));
#endif
