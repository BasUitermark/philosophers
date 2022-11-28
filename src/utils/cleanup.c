/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/28 11:38:12 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/28 12:49:54 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_data *data, t_clean n)
{
	int	i;

	i = 0;
	if (n == STRUCT)
	{
		free (data->philos);
		free (data->fork);
	}
	if (n >= DATA)
		pthread_mutex_destroy(&data->data_lock);
	if (n >= PRINT)
		pthread_mutex_destroy(&data->print_lock);
	while (n >= FORKS && i < data->philo_amount && data->fork)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	free (data->philos);
	free (data->fork);
}
