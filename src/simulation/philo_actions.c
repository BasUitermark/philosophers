/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 21:37:05 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/23 18:56:04 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_time_to(long time_to)
{
	long	current;

	current = gettime();
	while (gettime() - current < time_to)
		usleep(250);
}

static bool	philo_grab_drop(t_data *data, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (!print_action(data, philo, GRABBING) || \
			!p_mutex_lock((pthread_mutex_t *)philo->right_fork))
			return (false);
		if (print_action(data, philo, GRABBING) || \
			!p_mutex_lock((pthread_mutex_t *)philo->left_fork))
			return (false);
	}
	else
	{
		if (!print_action(data, philo, GRABBING) || \
			!p_mutex_lock((pthread_mutex_t *)philo->left_fork))
			return (false);
		if (!p_mutex_lock((pthread_mutex_t *)philo->right_fork) || \
			print_action(data, philo, GRABBING))
			return (false);
	}
	return (true);
}

bool	philo_eat(t_data *data, t_philo *philo)
{
	if (!data->sim_active)
		return (false);
	philo_grab_drop(data, philo);
	if (!print_action(data, philo, EATING))
		return (false);
	philo->state = EATING;
	philo->time_eaten = gettime();
	set_time_to(data->time_to_eat);
	if (data->meals)
		philo->meals_eaten += 1;
	if (!p_mutex_unlock((pthread_mutex_t *)philo->left_fork) || \
		!p_mutex_unlock((pthread_mutex_t *)philo->right_fork))
		return (false);
	return (true);
}

bool	philo_sleep(t_data *data, t_philo *philo)
{
	if (!data->sim_active)
		return (false);
	philo->state = SLEEPING;
	if (!print_action(data, philo, SLEEPING))
		return (false);
	set_time_to(data->time_to_sleep);
	return (true);
}

bool	philo_think(t_data *data, t_philo *philo)
{
	if (!data->sim_active)
		return (false);
	philo->state = THINKING;
	if (!print_action(data, philo, THINKING))
		return (false);
	return (true);
}
