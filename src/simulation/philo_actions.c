/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: buiterma <buiterma@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 21:37:05 by buiterma      #+#    #+#                 */
/*   Updated: 2022/11/23 16:51:31 by buiterma      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_time_to(long time_to)
{
	long	current;

	current = gettime();
	while (gettime() - current < time_to)
		usleep(100);
}

static void	philo_grab_drop(t_data *data, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		p_mutex_lock((pthread_mutex_t *)philo->right_fork);
		print_action(data, philo, GRABBING);
		p_mutex_lock((pthread_mutex_t *)philo->left_fork);
		print_action(data, philo, GRABBING);
	}
	else
	{
		p_mutex_lock((pthread_mutex_t *)philo->left_fork);
		print_action(data, philo, GRABBING);
		p_mutex_lock((pthread_mutex_t *)philo->right_fork);
		print_action(data, philo, GRABBING);
	}
}

void	philo_eat(t_data *data, t_philo *philo)
{
	if (!data->sim_active)
		return ;
	philo_grab_drop(data, philo);
	print_action(data, philo, EATING);
	philo->state = EATING;
	philo->time_eaten = gettime();
	set_time_to(data->time_to_eat);
	if (data->meals)
		philo->meals_eaten += 1;
	p_mutex_unlock((pthread_mutex_t *)philo->left_fork);
	p_mutex_unlock((pthread_mutex_t *)philo->right_fork);
}

void	philo_sleep(t_data *data, t_philo *philo)
{
	if (!data->sim_active)
		return ;
	philo->state = SLEEPING;
	print_action(data, philo, SLEEPING);
	set_time_to(data->time_to_sleep);
}

void	philo_think(t_data *data, t_philo *philo)
{
	if (!data->sim_active)
		return ;
	philo->state = THINKING;
	print_action(data, philo, THINKING);
}
