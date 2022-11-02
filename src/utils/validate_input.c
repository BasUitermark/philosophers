/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/27 23:41:01 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/02 21:50:50 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	validate_num(char *str)
{
	size_t	i;

	while (str[i])
	{
		if (ft_isdigit(str[i]))
		i++;
	}
	return (true);
}

bool	validate_input(int argc, const char **argv)
{
	size_t	i;

	i = 1;
	if (argc != 6)
		return (false);
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 1 || !validate_num(argv[i]))
		{
			printf("Error: one or more arguments formatted incorrectly");
			return (false);
		}
		i++;
	}
	if (ft_atoi(argv[1]) > 200 || ft_atoi(argv[1]) < 1)
	{
		printf("Error: amount of allowed philosophers \
				is not within boundaries");
		return (false);
	}
	return (true);
}
