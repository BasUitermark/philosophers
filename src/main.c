/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 10:35:00 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/15 13:47:56 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, const char **argv)
{
	t_data	data;
	t_philo	*philos;

	philos = NULL;
	if (!validate_input(argc, argv))
		return (EXIT_FAILURE);
	if (!init_data(&data, argv))
		return (EXIT_FAILURE);
	print_input(data);
	if (!exec_sim(data))
	{
		//some cleanup
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
