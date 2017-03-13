/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_types_defs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:44:57 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/10 15:16:16 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_TYPES_DEFS_H
# define CONV_TYPES_DEFS_H

typedef enum	e_conv_type
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
	UNSUPPORTED_CONVERSION,
	D_MAJ,
	O_MAJ,
	U_MAJ,
	C_MAJ,
	S_MAJ,
	UNKNOWN_CONVERSION
}				t_conv_type;

#endif
