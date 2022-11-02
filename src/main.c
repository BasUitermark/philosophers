/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/22 10:35:00 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/02 21:12:40 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_data	data;

	philos = NULL;
	if (!validate_input(argc, argv))
		return (EXIT_FAILURE);
	if (!init_data(&data, argv))
		return (EXIT_FAILURE);
	// execute sim
	return (EXIT_SUCCESS);
}
