/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:33:13 by djean             #+#    #+#             */
/*   Updated: 2016/10/17 16:58:09 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

t_string	*string_dup(t_string *s, const char *str)
{
	return (string_ndup(s, str, ft_strlen(str)));
}

t_string	*string_ndup(t_string *s, const char *str, size_t len)
{
	if ((string_init_with_capacity(s, len)) == NULL)
		return (NULL);
	ft_memcpy(s->str, str, len);
	s->len = len;
	s->str[s->len] = '\0';
	return (s);
}

t_string	*string_clone(t_string *dst, const t_string *src)
{
	return (string_ndup(dst, src->str, src->len));
}

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
