/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:14:45 by djean             #+#    #+#             */
/*   Updated: 2016/10/07 19:31:30 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

static void		init_skip_table(const char *pattern, size_t len, size_t *table)
{
	size_t		i;

	i = 0;
	while (i < ASCII_TABLE_LEN)
	{
		table[i] = len;
		++i;
	}
	i = len;
	while (i > 0)
	{
		table[(size_t)pattern[i]] = i;
		--i;
	}
	table[(size_t)pattern[0]] = 1;
}

char			*ft_strrstr(const char *big, const char *little)
{
	return (ft_strrnstr(big, little, ft_strlen(big)));
}

char			*ft_strrnstr(const char *big, const char *little, size_t len)
{
	size_t		skip_table[ASCII_TABLE_LEN];
	size_t		little_len;
	size_t		skip;
	size_t		i;

	if (*little == '\0')
		return ((char *)(uintptr_t)big);
	little_len = ft_strlen(little);
	init_skip_table(little, little_len, skip_table);
	if (little_len <= len)
	{
		skip = len - little_len + 1;
		while (skip > 0)
		{
			i = 0;
			while (little[i] == big[skip - 1 + i])
			{
				if (i == little_len - 1)
					return ((char *)(uintptr_t)(big + skip - 1));
				++i;
			}
			skip -= skip_table[(size_t)big[skip - 1 + i]];
		}
	}
	return (NULL);
}
