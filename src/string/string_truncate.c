/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_truncate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/12 02:04:45 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Truncate the string
** Return the new size of the string or -1 if the truncate is to large
*/

ssize_t		string_truncate(t_string *s, size_t n)
{
	if (n > s->len)
		return (-1);
	s->len = n;
	s->str[s->len] = '\0';
	return ((ssize_t)s->len);
}
