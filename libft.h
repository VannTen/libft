/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:51:07 by mgautier          #+#    #+#             */
/*   Updated: 2017/04/17 16:01:12 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "includes/usual_macros.h"
# include "includes/btree_interface.h"
# include "includes/fifo_interface.h"
# include "includes/lst_interface.h"
# include "includes/ft_integer.h"
# include "includes/bool.h"
# include "includes/list.h"
# include "includes/printf.h"
# include "includes/unix_usage_interface.h"
# include "includes/itoa_tools.h"
# include "includes/get_next_line.h"
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
** Str functions
*/

size_t				ft_strlen(const char *str);
size_t				ft_strnlen(const char *str, size_t size);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little,
								size_t len);
t_lst				*f_strsplit_lst(char const *str, char c);
char				*f_strljoin(char const *str_1, char const *str_2,
									size_t size_1, size_t size_2);
char				*ft_strnew_char(size_t size, char c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_gen_strdel(void **str);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char*));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				**ft_free_string_array(char ***tab);

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
