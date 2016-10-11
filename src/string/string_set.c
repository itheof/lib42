/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 02:23:06 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Append the char 'c', 'n' times, to the buffer
*/

t_string	*string_set(t_string *b, int c, size_t n)
{
	if (BUF_NEED_RESIZE(b, n))
		if (string_resize(b, n) == NULL)
			return (NULL);
	ft_memset(b->str + b->len, c, n);
	b->len += n;
	b->str[b->len] = 0;
	return (b);
}
