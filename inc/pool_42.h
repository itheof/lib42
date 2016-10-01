/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_42.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 18:43:08 by djean             #+#    #+#             */
/*   Updated: 2016/10/04 11:37:13 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POOL_42_H
# define POOL_42_H

# include <stdlib.h>
# include "typedefs_42.h"
# include "structs_42.h"
# include "pool_42.h"

# define ROUND_UP_8(n)		(!(n) || (n) % 8 ? ((n) + 8U) & (~0U - 7U) : (n))
# define CHUNK_SIZE(e, s)	((e) * (s) + sizeof(void*))
# define CHUNK_HEAD(c)		(&(c)->head)

t_pool	*pool_new(size_t elem_size, size_t chunk_capacity);
t_pool	*pool_init(t_pool *p, size_t elem_size, size_t chunk_capacity);
t_chunk	*pool_new_chunk(t_pool *p);
void	*pool_obtain(t_pool *p);
void	pool_return(t_pool *p, void *node);
void	pool_reset(t_pool *p);
void	pool_destroy(t_pool **p);

#endif
