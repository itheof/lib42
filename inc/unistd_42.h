/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unistd_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:38:45 by tvallee           #+#    #+#             */
/*   Updated: 2016/10/04 14:52:55 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNISTD_42_H
# define UNISTD_42_H

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
