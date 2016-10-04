/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:14:45 by djean             #+#    #+#             */
/*   Updated: 2016/10/05 01:34:02 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

// char	*ft_strstr(const char *big, const char *little)
// {
// 	size_t	big_len;
// 	size_t	little_len;
// 	size_t	i;

// 	big_len = ft_strlen(big);
// 	little_len = ft_strlen(little);
// 	if (*little == '\0')
// 		return ((char *)(uintptr_t)big);
// 	if (little_len <= big_len)
// 	{
// 		i = 0;
// 		while (i <= big_len - little_len)
// 		{
// 			if (!ft_memcmp(big + i, little, little_len))
// 				return ((char *)(uintptr_t)(big + i));
// 			++i;
// 		}
// 	}
// 	return (NULL);
// }

#define ASCII_TABLE_LEN 256

static void		init_skip_table(const char *little, size_t len, size_t *table)
{
	size_t		i;

	i = 0;
	while (i < ASCII_TABLE_LEN)
	{
		table[i] = len;
		++i;
	}
	i = 0;
	while (i < len)
	{
		table[(size_t)little[i]] = len - i - 1;
		++i;
	}
}

char			*ft_strstr(const char *big, const char *little)
{
	static size_t	skip_table[ASCII_TABLE_LEN]; // 2ko is really big !!!
	size_t			big_len;
	size_t			little_len;
	size_t			skip;
	size_t			i;

	if (*little == '\0')
		return ((char *)(uintptr_t)big);
	big_len = ft_strlen(big);
	little_len = ft_strlen(little);
	init_skip_table(little, little_len, skip_table);
	if (little_len <= big_len)
	{
		skip = 0;
		while (skip <= big_len - little_len)
		{
			i = little_len - 1;
			while (little[i] == big[skip + i])
				if (i-- == 0)
					return ((char *)(uintptr_t)(big + skip));
			skip += skip_table[(size_t)big[skip + little_len - 1]];
		}
	}
	return (NULL);
}
