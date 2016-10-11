/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 02:22:20 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Replace the content of the buffer with the string '*s'
*/

t_string	*string_replace(t_string *b, const char *s)
{
	return (string_nreplace(b, s, ft_strlen(s)));
}

/*
** Replace the content of the buffer with the string '*s', up to 'len' bytes
*/

t_string	*string_nreplace(t_string *b, const char *s, size_t len)
{
	b->len = 0;
	string_ncat(b, s, len);
	b->str[b->len] = '\0';
	return (b);
}
