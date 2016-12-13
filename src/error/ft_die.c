/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenault <crenault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 16:35:17 by djean             #+#    #+#             */
/*   Updated: 2016/12/13 10:25:59 by djean            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_42.h"

void	ft_die(const char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(1);
}

void	*fatal_malloc(void *ptr)
{
	if (ptr == NULL)
	{
		write(STDERR_FILENO, FATAL_MALLOC, ft_strlen(FATAL_MALLOC));
		ft_abort();
	}
	return (ptr);
}
