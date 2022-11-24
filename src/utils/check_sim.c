/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_sim.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 15:58:25 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/24 19:09:40 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_meals(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->philo_amount)
	{
		pthread_mutex_lock(&data->data_lock);
		if (data->philos[i].meals_eaten < data->meal_amount)
		{
			pthread_mutex_unlock(&data->data_lock);
			return (false);
		}
		pthread_mutex_unlock(&data->data_lock);
		i++;
	}
	pthread_mutex_lock(&data->data_lock);
	data->sim_active = false;
	pthread_mutex_unlock(&data->data_lock);
	print_action(data, data->philos, FINAL, true);
	return (true);
}

static bool	check_death(t_data *data)
{
	size_t	i;
	long	current;

	i = 0;
	current = gettime();
	while (i < data->philo_amount)
	{
		pthread_mutex_lock(&data->data_lock);
		if (current - data->philos[i].time_eaten > data->time_to_die)
		{
			pthread_mutex_unlock(&data->data_lock);
			pthread_mutex_lock(&data->data_lock);
			data->sim_active = false;
			pthread_mutex_unlock(&data->data_lock);
			print_action(data, &data->philos[i], DIED, true);
			return (true);
		}
		pthread_mutex_unlock(&data->data_lock);
		i++;
	}
	return (false);
}

void	check_sim(t_data *data)
{
	while (true)
	{
		if (data->meals)
			if (check_meals(data))
				return ;
		if (check_death(data))
			return ;
		usleep(10);
	}
}
