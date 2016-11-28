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

#ifdef __linux__
# define _POSIX_C_SOURCE 1
# include <sys/types.h>
#endif
#include <signal.h>
#include "stdlib_42.h"

void	ft_abort(void)
{
	kill(0, SIGABRT);
}
