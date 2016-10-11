/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 13:49:50 by tvallee           #+#    #+#             */
/*   Updated: 2016/10/11 14:20:44 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd_42.h"

static int	opt_get_type(char *const av[], const char *optstring, t_opt *state)
{
	char	*addr;
	char	temp;

	temp = av[state->optind][state->optoff];
	state->optopt = temp;
	if (!(addr = ft_strchr(optstring, temp)))
	{
		if (av[state->optind][state->optoff + 1])
			state->optoff += 1;
		else
		{
			state->optoff = 0;
			state->optind += 1;
		}
		if (state->opterr)
			dprintf(2, GETOPT_INVALID_ERR_FORMAT, av[0], temp);
		return (-1);
	}
	else
		return ((addr[1]) == ':' ? 1 : 0);
}

static int	parse_operand_opt(int ac, char *const av[], const char *optstring,
		t_opt *state)
{
	int c;

	c = av[state->optind][state->optoff];
	if (!av[state->optind][state->optoff + 1])
	{
		state->optarg = av[state->optind + 1];
		state->optind += 2;
		state->optoff = 0;
		if (state->optind > ac) {
			if (state->opterr && *optstring != ':')
			{
				dprintf(2, GETOPT_MULT_ERR_FORMAT, av[0], c);
			}
			return ((*optstring == ':') ? ':' : '?');
		}
	}
	else
	{
		state->optarg = av[state->optind] + state->optoff + 1;
		state->optind += 1;
		state->optoff = 0;
	}
	return (c);
}

static int	parse_simple_opt(char *const av[], t_opt *state)
{
	int c;

	c = av[state->optind][state->optoff];
	if (av[state->optind][state->optoff + 1])
		state->optoff += 1;
	else
	{
		state->optoff = 0;
		state->optind += 1;
	}
	return (c);
}

static int	is_opt_format(char *str)
{
	return (str && str[0] == '-' && str[1]);
}

int			ft_getopt(int ac, char *const av[], const char *optstring,
		t_opt *state)
{
	int opt_type;

	if (state->optind == 0)
		state->optind = 1;
	if (!state->optoff)
	{
		if (state->optind < ac && is_opt_format(av[state->optind]))
		{
			if (*(av[state->optind] + 1) == '-' && !*(av[state->optind] + 2))
				state->optind += 1;
			else
			{
				state->optoff = 1;
				return (ft_getopt(ac, av, optstring, state));
			}
		}
		return (-1);
	}
	// FUCKTON OF SIDE EFFECTS
	opt_type = opt_get_type(av, optstring, state);
	if (opt_type > 0)
		return (parse_operand_opt(ac, av, optstring, state));
	else if (opt_type == 0)
		return (parse_simple_opt(av, state));
	else
		return ('?');
}
