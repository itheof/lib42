/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:13:03 by tvallee           #+#    #+#             */
/*   Updated: 2016/11/28 17:54:44 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib_42.h"
#ifdef __linux__
# include <sys/types.h>
# define _POSIX_C_SOURCE
#endif
#include <signal.h>

void	ft_abort(void)
{
	kill(0, SIGABRT);
}
