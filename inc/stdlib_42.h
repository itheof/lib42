/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdlib_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:49 by djean             #+#    #+#             */
/*   Updated: 2016/10/01 15:57:40 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDLIB_42_H
# define STDLIB_42_H

# include <stdlib.h>
# include "macros_42.h"
# include "memory_42.h"
# include "string_42.h"

void	*ft_realloc(void *ptr, size_t size, size_t oldsize);
char	*ft_utoa_base_r(char *buf, unsigned long long n, unsigned base);
char	*ft_utoa_base(unsigned long long n, unsigned base);
char	*ft_stoa_base_r(char *buf, long long n, unsigned base);
char	*ft_stoa_base(long long n, unsigned base);
size_t	next_power_of_2(size_t n);

#endif
