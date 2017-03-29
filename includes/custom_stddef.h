/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_stddef.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:31:49 by mgautier          #+#    #+#             */
/*   Updated: 2017/03/29 10:40:51 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_STDDEF_H
# define CUSTOM_STDDEF_H

typedef int		(*t_compare)(void *ref, void *to_comp);
typedef	void	(*t_destroy)(void **where_is_content);
#endif
