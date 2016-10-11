/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_toa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 02:23:17 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Append the signed integer 'value' in base 'base' to the buffer
*/

t_string	*string_stoa(t_string *s, long long value, unsigned base)
{
	char	*n;

	n = ft_stoa_base(value, base);
	if (string_cat(s, n) == NULL)
	{
		free(n);
		return (NULL);
	}
	free(n);
	return (s);
}

/*
** Append the unsigned integer 'value' in base 'base' to the buffer
*/

t_string	*string_utoa(t_string *s, unsigned long long value, unsigned base)
{
	char	*n;

	n = ft_utoa_base(value, base);
	if (string_cat(s, n) == NULL)
	{
		free(n);
		return (NULL);
	}
	free(n);
	return (s);
}
