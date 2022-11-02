/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 21:58:18 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/02 21:13:49 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	inti_data(t_data *data, char *argv)
{
	data->start_time = gettime();
	data->philo_amount = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->meal_amount = ft_atoi(argv[5]);
	data->forks = ft_calloc(data->philo_amount, sizeof(pthread_mutex_t));
	if (!data->forks)
		return (false);
	data->philo_threads = ft_calloc(data->philo_amount, sizeof(pthread_t));
	if (!data->philo_threads)
		return (false);
	return (true);
}
