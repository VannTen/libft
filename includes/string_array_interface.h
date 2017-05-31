/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_array_interface.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 14:59:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/05/31 14:30:25 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_ARRAY_INTERFACE_H
# define STRING_ARRAY_INTERFACE_H
# include <stddef.h>

/*
** String array functions
** Implemenation files : name of the function
*/

char	**ft_free_string_array(char ***tab);
char	**ft_string_array_dup(char const *const *string_array);
char	**ft_str_array_cpy(char *const *src, char **dst);
size_t	ft_string_array_count(char const *const *string_array);

/*
** Display functions
** Implentation file : ft_print_string_array.c
*/

void	ft_print_string_array(char const *const *str_array, char sep);

#endif
