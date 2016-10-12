/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_twin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/12 02:04:58 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Return a strict copy of the buffer '*b'
*/

// TODO rename it 'string_clone'
t_string	*string_twin(t_string *dst, const t_string *src)
{
	// TODO don't need all capacity and why capacity - 1 ?
	if (string_init(dst, src->capacity - 1) == NULL)
		return (NULL);
	dst->len = src->len;
	ft_memcpy(dst->str, src->str, src->len);
    dst->str[dst->len] = '\0';
	return (dst);
}
