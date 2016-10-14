/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unistd_42.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 14:38:45 by tvallee           #+#    #+#             */
/*   Updated: 2016/10/14 10:24:14 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNISTD_42_H
# define UNISTD_42_H

# if !defined(__APPLE__)
#  include <sys/types.h>
#  include <sys/wait.h>
#  define GETOPT_INVALID_ERR_FORMAT "%s: invalid option -- '%c'\n"
#  define GETOPT_MULT_ERR_FORMAT "%s: option requires an argument -- '%c'\n"
# else
#  define GETOPT_INVALID_ERR_FORMAT "%s: illegal option -- %c\n"
#  define GETOPT_MULT_ERR_FORMAT "%s: option requires an argument -- %c\n"
# endif

# include "string_42.h"
# include "ft_printf.h"

typedef struct	s_opt
{
	char	*optarg;
	int		opterr;
	int		optind;
	int		optopt;
	int		optoff;
}				t_opt;

enum e_opt_type
{
	E_OPT_TYPE_ERR,
	E_OPT_TYPE_SIMPLE,
	E_OPT_TYPE_OPERAND
};

int				ft_getopt(int ac, char *const av[], const char *optstring,
		t_opt *state);

#endif
