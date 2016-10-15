/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/10/15 14:38:34 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Fill a destination buffer, resulting in the merge of '*a' and '*b'
*/

// TODO rename it string_concat
t_string	*string_merge(t_string *dst, const t_string *a, const t_string *b)
{
	size_t		size;

	size = a->len + b->len;
	if (string_init_with_capacity(dst, size) == NULL)
		return (NULL);
	dst->len = a->len + b->len;
	ft_memcpy(dst->str, a->str, a->len);
	ft_memcpy(dst->str + a->len, b->str, b->len);
	dst->str[dst->len] = '\0';
	return (dst);
}
