/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 12:04:13 by djean             #+#    #+#             */
/*   Updated: 2016/10/11 02:19:38 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** Append to 'dst' the content of 'src'
** Return the new size of 'dst' or -1 on error
*/

t_string	*string_append(t_string *dst, const t_string *src)
{
	return (string_ncat(dst, src->str, src->len));
}
