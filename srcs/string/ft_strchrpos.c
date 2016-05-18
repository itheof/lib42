/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrpos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:25:12 by djean             #+#    #+#             */
/*   Updated: 2016/04/28 17:38:06 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strchrpos(const char *s, int c)
{
	char	*p;

	p = ft_strchr(s, c);
	if (p == NULL)
		return (-1);
	return (p - s);
}
