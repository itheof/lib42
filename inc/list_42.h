/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_42.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djean <djean@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:20:34 by djean             #+#    #+#             */
/*   Updated: 2016/11/22 11:11:16 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_42_H
# define LIST_42_H

# include "stdlib.h"
# include "typedefs_42.h"
# include "structs_42.h"
# include "pool_42.h"

# define NODE_SIZE(elem_size)	(sizeof(void*) + (elem_size))

/*
** `list_create` malloc a new `t_list`
**
** `list_destroy` free the `t_list` and all internal nodes
*/
t_list	*list_create(size_t elem_size);
void	list_destroy(t_list *l);

/*
** `list_init` initialize an already existing `t_list`,
** and initialize a new pool
**
** `list_shutdown` free the internal pool, therefore all the nodes
*/
t_list	*list_init(t_list *l, size_t elem_size);
void	list_shutdown(t_list *l);

#endif
