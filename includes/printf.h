/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:42:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/07 19:00:30 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>

int	ft_vdprintf(int fd, const char *format_string, va_list *var_arg_list);
int	ft_printf(const char *format_string, ...);
int	ft_vasprintf(char **strp, const char *fmt, va_list *ap);

#endif
