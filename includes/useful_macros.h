/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_macros.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 18:01:54 by mgautier          #+#    #+#             */
/*   Updated: 2017/09/26 19:26:24 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USEFUL_MACROS_H
# define USEFUL_MACROS_H

/*
** Macros for compile-time checking
*/

#define ARRAY_LENGTH(ARRAY) (sizeof(ARRAY)/sizeof(ARRAY[0]))

/*
** Static assertions
** That is meant to check condition on elements known at compile time (such as
** static variables and such)
** It is inspired from the Linux Kernel, and precisely, I found out the concept
** here :
** http://www.pixelbeat.org/programming/gcc/static_assert.html
*/

#define ASSERT(predicate) ((void)sizeof(char[1 - 2*!(predicate)]))


#endif
