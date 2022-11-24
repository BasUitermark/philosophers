/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 10:35:00 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/24 19:12:57 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//make clean function and check where false what to clean;

int	main(int argc, const char **argv)
{
	t_data	data;

	if (!validate_input(argc, argv))
		return (EXIT_FAILURE);
	if (!init_data(&data, argv))
		return (EXIT_FAILURE);
	if (!exec_sim(&data))
		return (EXIT_FAILURE);
	check_sim(&data);
	p_join(&data);
	clean_data(&data);
	return (EXIT_SUCCESS);
}
