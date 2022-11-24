/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 21:37:05 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/24 19:05:19 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_time_to(long time_to)
{
	long	current;

	current = gettime();
	while (gettime() - current < time_to)
		usleep(INTERVAL);
}

static bool	philo_grab_drop(t_data *data, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock((pthread_mutex_t *)philo->left_fork);
		print_action(data, philo, GRABBINGL, false);
		pthread_mutex_lock((pthread_mutex_t *)philo->right_fork);
		print_action(data, philo, GRABBINGR, false);
	}
	else
	{
		pthread_mutex_lock((pthread_mutex_t *)philo->right_fork);
		print_action(data, philo, GRABBINGR, false);
		if (data->philo_amount == 1)
			return (false);
		pthread_mutex_lock((pthread_mutex_t *)philo->left_fork);
		print_action(data, philo, GRABBINGL, false);
	}
	return (true);
}

bool	philo_eat(t_data *data, t_philo *philo)
{
	if (!read_data(&data->data_lock, &data->sim_active))
		return (false);
	if (!philo_grab_drop(data, philo))
		return (false);
	print_action(data, philo, EATING, false);
	pthread_mutex_lock(&data->data_lock);
	philo->time_eaten = gettime();
	pthread_mutex_unlock(&data->data_lock);
	set_time_to(data->time_to_eat);
	if (data->meals)
	{
		pthread_mutex_lock(&data->data_lock);
		philo->meals_eaten += 1;
		pthread_mutex_unlock(&data->data_lock);
	}
	pthread_mutex_unlock((pthread_mutex_t *)philo->left_fork);
	pthread_mutex_unlock((pthread_mutex_t *)philo->right_fork);
	return (true);
}

bool	philo_sleep(t_data *data, t_philo *philo)
{
	if (!read_data(&data->data_lock, &data->sim_active))
		return (false);
	print_action(data, philo, SLEEPING, false);
	set_time_to(data->time_to_sleep);
	return (true);
}

bool	philo_think(t_data *data, t_philo *philo)
{
	if (!read_data(&data->data_lock, &data->sim_active))
		return (false);
	print_action(data, philo, THINKING, false);
	return (true);
}
