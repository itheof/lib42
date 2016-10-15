/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_clone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/15 14:39:05 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Return a copy of the buffer '*b'
*/

t_string	*string_clone(t_string *dst, const t_string *src)
{
	if (string_init_with_capacity(dst, src->len - 1) == NULL)
		return (NULL);
	dst->len = src->len;
	ft_memcpy(dst->str, src->str, src->len);
	dst->str[dst->len] = '\0';
	return (dst);
}
