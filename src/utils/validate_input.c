/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/27 23:41:01 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/02 15:28:00 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	is_strdigit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= '0' || str[i] >= '9')
			return (false);
		i++;
	}
	return (true);
}

bool	validate_input(int argc, const char **argv)
{
	size_t	i;

	i = 0;
	if (argc != 6)
		return (false);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < 1 || !is_strdigit(argv[i]))
		{
			ft_putendl_fd("error: ", 2);
			return (false);
		}
		i++;
	}
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 1)
	{
		ft_putendl_fd("error: too many philosophers", 2);
		return (false);
	}
	return (true);
}
