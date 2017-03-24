/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_char_interface.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 10:29:40 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/24 11:23:24 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDE_CHAR_INTERFACE_H
# define WIDE_CHAR_INTERFACE_H
# include <wchar.h>
# define INVALID_SIZE -1

int				ft_wctomb_len(wchar_t wchar);
int				ft_wctomb_write(char *dst, wchar_t wchar, int size_mb_seq);
int				ft_wctomb(char *dst, wchar_t wchar);
int				ft_wcstrntomb_len(wchar_t *wstring, int max_size);
int				ft_wcstrntomb_write(char *dst, wchar_t *wstring, int max_size);

/*
** Tools for mask and utf_8 indic generation
** Implementation file : ft_wcconv_tools.c
*/

unsigned int	generate_utf_8_indic(unsigned int size);
unsigned int	generate_first_mask(unsigned int size);
#endif
