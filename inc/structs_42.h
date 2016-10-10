/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_42.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:49 by djean             #+#    #+#             */
/*   Updated: 2016/10/08 18:12:55 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_42_H
# define STRUCTS_42_H

# include <stdlib.h>

struct	s_chunk
{
	void	*next;
	void	*head;
};

struct	s_pool
{
	struct s_chunk	*chunks_list;
	void			*free_list;
	size_t			chunk_capacity;
	size_t			elem_size;
};

struct	s_buffer
{
	char	*str;
	size_t	len;
	size_t	sizemax;
	size_t	iterator;
};

struct	s_array
{
	void	*data;
	size_t	max;
	size_t	count;
	size_t	elem_size;
	size_t	iterator;
};

struct	s_cbuffer
{
	void		*data;
	size_t		len;
	size_t		capacity;
	size_t		elem_size;
	void		(*delete_func)(void *);
	size_t		start;
	size_t		end;
};

#endif
