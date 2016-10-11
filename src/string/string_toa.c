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

t_string	*string_stoa(t_string *b, long long value, unsigned base)
{
	char	*n;

	n = ft_stoa_base(value, base);
	string_cat(b, n);
	free(n);
	return (b);
}

/*
** Append the unsigned integer 'value' in base 'base' to the buffer
*/

t_string	*string_utoa(t_string *b, unsigned long long value, unsigned base)
{
	char	*n;

	n = ft_utoa_base(value, base);
	string_cat(b, n);
	free(n);
	return (b);
}
