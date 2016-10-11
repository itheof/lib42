/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 22:06:05 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Append the char 'c', 'n' times, to the buffer
*/

// TODO rethink this function (need to give ranges)
t_string	*string_set(t_string *s, int c, size_t n)
{
	if (BUF_NEED_RESIZE(s, n) && string_resize(s, n) == NULL)
		return (NULL);
	ft_memset(s->str + s->len, c, n);
	s->len += n;
	s->str[s->len] = 0;
	return (s);
}
