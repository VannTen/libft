/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:15:30 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/02 16:22:28 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITOA_TOOLS_H
# define ITOA_TOOLS_H
# include "bool.h"
# include "ft_integer.h"
# include <stddef.h>
# include <stdint.h>

size_t	itoa_len_signed(intmax_t number, int base);
size_t	itoa_len_unsigned(uintmax_t number, int base);
size_t	itoa_length(t_integer number, int base, t_bool is_signed);
void	negative(char *str, intmax_t number, int base, char after_digits);
void	positive(char *str, uintmax_t number, int base, char after_digits);

#endif
