/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs_42.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:28:49 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 12:40:56 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_42_H
# define TYPEDEFS_42_H

# include <stdarg.h>

typedef struct s_chunk		t_chunk;
typedef struct s_pool		t_pool;
typedef struct s_buffer		t_buffer;
typedef struct s_array		t_array;
typedef struct s_cbuffer	t_cbuffer;
typedef struct s_errors		t_errors;
typedef struct s_gnl		t_gnl;
typedef struct s_format		t_format;
typedef	int					(*t_fc)(t_buffer*, t_format*, va_list);

#endif
