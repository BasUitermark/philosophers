/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 21:58:18 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/15 13:42:57 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_data(t_data *data, const char **argv)
{
	data->start_time = gettime();
	data->philo_amount = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->meal_amount = ft_atoi(argv[5]);
	data->start_time = gettime();
	data->philos = ft_calloc(data->philo_amount, sizeof(t_philo));
	return (true);
}
