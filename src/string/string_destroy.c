/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:30:57 by djean             #+#    #+#             */
/*   Updated: 2016/10/14 22:50:58 by crenault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_42.h"

/*
** free the entire struct
*/

// TODO delete this
void	string_destroy(t_string *b)
{
	free(b->str);
}
