/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 12:50:58 by mgautier          #+#    #+#             */
/*   Updated: 2017/01/31 17:59:27 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

enum	e_conv_type
{
	D,
	I,
	O,
	U,
	X,
	X_MAJ,
	E,
	E_MAJ,
	F,
	F_MAJ,
	G,
	G_MAJ,
	A,
	A_MAJ,
	C,
	S,
	P,
	N,
	NO_CONVERSION,
	D_MAJ,
	O_MAJ,
	U_MAJ,
	C_MAJ,
	S_MAJ,
	UNKNOWN_CONVERSION
};

static const char g_types[] = "diouxXeEfFgGaAcspn%DOUCS";
#endif
