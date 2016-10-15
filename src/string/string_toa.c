/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_toa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:58 by djean             #+#    #+#             */
/*   Updated: 2016/10/15 19:23:24 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

t_string	*string_stoa(t_string *s, long long value, unsigned base)
{
	char	*number;

	number = ft_stoa_base(value, base);
	if (number == NULL)
		return (NULL);
	if (string_dup(s, number) == NULL)
	{
		free(number);
		return (NULL);
	}
	free(number);
	return (s);
}

t_string	*string_utoa(t_string *s, unsigned long long value, unsigned base)
{
	char	*number;

	number = ft_utoa_base(value, base);
	if (number == NULL)
		return (NULL);
	if (string_dup(s, number) == NULL)
	{
		free(number);
		return (NULL);
	}
	free(number);
	return (s);
}
