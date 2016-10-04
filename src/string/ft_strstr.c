/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:14:45 by djean             #+#    #+#             */
/*   Updated: 2016/09/30 11:04:57 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	big_len;
	size_t	little_len;
	size_t	i;

	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)(uintptr_t)big);
	i = 0;
	while (i < big_len - little_len)
	{
		if (!ft_memcmp(big + i, little, little_len))
			return ((char *)(uintptr_t)(big + i));
		++i;
	}
	return (NULL);
}
