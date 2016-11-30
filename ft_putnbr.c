/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:24:24 by mgautier          #+#    #+#             */
/*   Updated: 2016/11/16 18:50:17 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The recursion works that way : if n has more than one digit (n <= 10),
** write all digits before the last (with the recursive call);
** then write last digit.(n % 10)
*/

static void	ft_positive(int n)
{
	if (n >= 10 != 0)
		ft_positive(n / 10);
	ft_putchar(n % 10 + '0');
}

static void	ft_negative(int n)
{
	if (n <= -10 != 0)
		ft_negative(n / 10);
	ft_putchar(-(n % 10) + '0');
}

void		ft_putnbr(int n)
{
	if (n >= 0)
		ft_positive(n);
	else
	{
		ft_putchar('-');
		ft_negative(n);
	}
}
