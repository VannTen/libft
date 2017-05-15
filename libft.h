/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:51:07 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 14:55:32 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "includes/usual_macros.h"
# include "includes/btree_interface.h"
# include "includes/fifo_interface.h"
# include "includes/lst_interface.h"
# include "includes/ft_integer.h"
# include "includes/bool_interface.h"
# include "includes/list.h"
# include "includes/printf.h"
# include "includes/unix_usage_interface.h"
# include "includes/itoa_tools.h"
# include "includes/get_next_line.h"
# include "includes/unix_files_interface.h"
# include "includes/path_interface.h"
# include "includes/string_interface.h"
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

/*
** String array functions
*/

char				**ft_free_string_array(char ***tab);
char				**ft_string_array_dup(const char **string_array);
char				**ft_str_array_cpy(char * const * src, char **dst);
size_t				ft_string_array_count(const char **string_array);

/*
** Display functions
*/

void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_print_string_array(char const * const *str_array,
		char sep);

/*
** Mem functions
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

/*
** Convert functions
*/

char				*ft_itoa(int n);
int					ft_atoi(const char *str);
int					ft_strict_atoi(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** Is_of functions
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);

/*
** Math functions
*/

unsigned int		ft_int_square_root(unsigned int square);
unsigned int		ft_square_root_round_up(unsigned int square);

/*
** Miscellaneous
*/

void				do_nothing(void *precious_content);
void				no_destroy(void	**precious_content);

#endif
