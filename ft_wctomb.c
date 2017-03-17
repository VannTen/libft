/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:04:41 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/17 19:10:02 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int	ft_wctomb_len(wchar_t wchar)
{
	int	size_of_mb_seq;

	if (wchar <= 0x7F)
		size_of_mb_seq = 1;
	else if (wchar <= 0x7FF)
		size_of_mb_seq = 2;
	else if (wchar <= 0xFFFF)
		size_of_mb_seq = 3;
	else if (wchar <= 0x10FFFF)
		size_of_mb_seq = 4;
	else
		size_of_mb_seq = 0;
	return (size_of_mb_seq);
}

#define CONTINUATION_BYTE (unsigned int)0200
int	fta_wctomb(char *dst, wchar_t wchar, int size_mb_seq)
{
	int			index;
	int			shift;
	const unsigned int	mask[] = {07, 017, 037, 0};
	const unsigned int	utf_8_len_indic[] = {0360, 0340, 0300, 0};

	index = 4 - size_mb_seq;
	shift = 18 - 6 * index;
	dst = dst - index;
	dst[index] = (unsigned char)((wchar >>shift) & mask[index]);
	dst[index] += utf_8_len_indic[index];
	index++;
	shift -= 6;
	while (index < 4)
	{
		dst[index] = (unsigned char)((wchar >>shift) & (unsigned int)077);
		dst[index] += CONTINUATION_BYTE;
		index++;
		shift -= 6;
	}
	return (size_mb_seq);
}

int ft_wctomb(char *dst, wchar_t wchar)
{
	int size;

	size = ft_wctomb_len(wchar);
	return (fta_wctomb(dst, wchar, size));
}
