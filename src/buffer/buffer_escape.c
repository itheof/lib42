/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_escape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/10 02:24:37 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer_42.h"

t_buffer		*buffer_escape(t_buffer *b, int c)
{
	char		*nl;
	size_t		nl_offset;

	nl_offset = 0;
	while ((nl = ft_strchr(b->str + nl_offset, c)) != NULL)
	{
		nl_offset = (size_t)(nl - b->str);
		if (buffer_insert(b, nl_offset, "\\", 1) == NULL)
			return (NULL);
		nl_offset += 2;
	}
	return (b);
}

t_buffer		*buffer_unescape(t_buffer *b, int c)
{
	char		pattern[3];
	char		*escaped_nl;
	size_t		offset;

	offset = 0;
	pattern[0] = '\\';
	pattern[1] = (char)c;
	pattern[2] = '\0';
	while ((escaped_nl = ft_strstr(b->str + offset, pattern)) != NULL)
	{
		offset = (size_t)(escaped_nl - b->str);
		if (buffer_remove(b, offset, 1) == 0)
			return (NULL);
	}
	return (b);
}
