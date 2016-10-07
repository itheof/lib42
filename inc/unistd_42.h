/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unistd_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:38:45 by tvallee           #+#    #+#             */
/*   Updated: 2016/10/07 14:55:29 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNISTD_42_H
# define UNISTD_42_H

# if !defined(__APPLE__)
#  include <sys/types.h>
#  include <sys/wait.h>
# endif

# include "string_42.h"

typedef struct	s_opt
{
	char	*optarg;
	int		opterr;
	int		optind;
	int		optopt;
	int		optoff;
}				t_opt;

int				ft_getopt(int ac, char *const av[], const char *optstring,
		t_opt *state);

#endif
