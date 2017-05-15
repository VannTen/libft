/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_interface.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 15:22:23 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/15 15:22:57 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_INTERFACE_H
# define CONVERT_INTERFACE_H

/*
** Conversion functions
** Implementation files : name of the function
*/

char				*ft_itoa(int n);
int					ft_atoi(const char *str);
int					ft_strict_atoi(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);

#endif
