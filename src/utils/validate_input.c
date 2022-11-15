/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/27 23:41:01 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/14 13:28:19 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	validate_num(const char *str)
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
	if (argc < 5 || argc > 6)
	{
		printf("Error: invalid amount of arguments\n");
		return (false);
	}
	while (argv[i])
	{
		if (ft_atoi(argv[i]) < 1 || !validate_num(argv[i]))
		{
			printf("Error: one or more arguments formatted incorrectly\n");
			return (false);
		}
		i++;
	}
	if (ft_atoi(argv[1]) > 200)
	{
		printf("Error: inputted amount of philosophers ");
		printf("is not within boundaries\n");
		return (false);
	}
	return (true);
}
