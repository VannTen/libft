/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:04:22 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/16 17:05:21 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static void	ft_write_conv(char *to_write, const t_conversion *conv)
{
	static const t_print_to	print_to[] = {CONST_PRINT_TO_INITIALIZER};

	print_to[conv->type](to_write, conv);
}
